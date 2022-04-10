# 基于Qt实现的自定义简易Lua脚本编辑器

.![img](https://img-blog.csdnimg.cn/20191017190654775.gif)

技术点：https://blog.csdn.net/weixin_39568531/article/details/102613089

<1>Qt [Gui](https://so.csdn.net/so/search?q=Gui&spm=1001.2101.3001.7020).简单的控件和基础的qss知识足以

<2>Lua和C++交互。

**编辑器部分基本上用的是网上某个不错的编辑器的源码。简单贴一下：**

```cpp
//codeeditor.h
#ifndef CODEEDITOR_H
#define CODEEDITOR_H
 
#include <QPlainTextEdit>
#include <QObject>
 
QT_BEGIN_NAMESPACE
class QPaintEvent;
class QResizeEvent;
class QSize;
class QWidget;
QT_END_NAMESPACE
 
class LineNumberArea;
 
class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT
 
public:
    CodeEditor(QWidget *parent = 0);
 
    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();
 
protected:
    void resizeEvent(QResizeEvent *event);
 
private slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);
 
private:
    LineNumberArea *lineNumberArea;
};
 
 
class LineNumberArea : public QWidget{
public:
    LineNumberArea(CodeEditor *editor) : QWidget(editor) { codeEditor = editor; }
    QSize sizeHint() const { return QSize(codeEditor->lineNumberAreaWidth(), 0); }
protected:
    void paintEvent(QPaintEvent *event) { codeEditor->lineNumberAreaPaintEvent(event); }
private:
   CodeEditor *codeEditor;
 };
#endif
```

```cpp
//codeeditor.cpp
#include "codeeditor.h"
#include <QWidget>
#include <QPainter>
#include <QTextBlock>
 
CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{
    lineNumberArea = new LineNumberArea(this);
 
    connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
    connect(this, SIGNAL(updateRequest(QRect,int)), this, SLOT(updateLineNumberArea(QRect,int)));
    connect(this, SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
 
    updateLineNumberAreaWidth(0);
    highlightCurrentLine();
}
 
int CodeEditor::lineNumberAreaWidth()
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }
 
    int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;
 
    return space;
}
 
 
 
void CodeEditor::updateLineNumberAreaWidth(int /* newBlockCount */)
{
    setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}
 
void CodeEditor::updateLineNumberArea(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());
 
    if (rect.contains(viewport()->rect()))
        updateLineNumberAreaWidth(0);
}
 
void CodeEditor::resizeEvent(QResizeEvent *e)
{
    QPlainTextEdit::resizeEvent(e);
 
    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}
 
void CodeEditor::highlightCurrentLine()
{
    QList<QTextEdit::ExtraSelection> extraSelections;
 
    if (!isReadOnly()) {
        QTextEdit::ExtraSelection selection;
 
        QColor lineColor = QColor(Qt::yellow).lighter(160);
 
        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = textCursor();
        selection.cursor.clearSelection();
        extraSelections.append(selection);
    }
 
    setExtraSelections(extraSelections);
}
 
void CodeEditor::lineNumberAreaPaintEvent(QPaintEvent *event)
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), Qt::lightGray);
 
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
    int bottom = top + (int) blockBoundingRect(block).height();
 
    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
                             Qt::AlignRight, number);
        }
 
        block = block.next();
        top = bottom;
        bottom = top + (int) blockBoundingRect(block).height();
        ++blockNumber;
    }
}
```



```cpp
// registerfunctions.h
 
#ifndef REGISTERFUNCTIONS
#define REGISTERFUNCTIONS
 
typedef int (*luaTestFunction)(lua_State *L);
//  加载lua头文件
#include "../lua/src/lua.hpp"
 
#include <cmath>
 
// 第一步：定义lua调用的函数
static int myadd(lua_State* L)
{
    double op1 = lua_tonumber(L, 1);
    double op2 = lua_tonumber(L, 2);
    lua_pushnumber(L, op1 + op2);
    return 1;
}
 
static int mysub(lua_State* L)
{
    double op1 = lua_tonumber(L, 1);
    double op2 = lua_tonumber(L, 2);
    lua_pushnumber(L, op1 - op2);
    return 1;
}
 
 
static int l_sin(lua_State *L)
{
    // 如果给定虚拟栈中索引处的元素可以转换为数字，则返回转换后的数字，否则报错。
    double d = luaL_checknumber(L, 1);
    lua_pushnumber(L, sin(d));  /* push result */
 
    /* 这里可以看出，C可以返回给Lua多个结果，
     * 通过多次调用lua_push*()，之后return返回结果的数量。
     */
    return 1;  /* number of results */
}
 
 
int myprint( lua_State* L )
{
    //...
    return 0;
}
 
提供的接口函数
const int TestFUNCNUM = 4;
const luaTestFunction MFUNC_P[] =
{
    myadd,
    mysub,
    l_sin,
    myprint
};
 
const QString MACROFUNCNAME[] =
{
    "cadd",
    "csub",
    "csin",
    "myprint"
};
 
 
 
#ifdef USING_LUA_REGISTER
//待Lua调用的C注册函数。
static int add2(lua_State* L)
{
    //检查栈中的参数是否合法，1表示Lua调用时的第一个参数(从左到右)，依此类推。
    //如果Lua代码在调用时传递的参数不为number，该函数将报错并终止程序的执行。
    double op1 = luaL_checknumber(L,1);
    double op2 = luaL_checknumber(L,2);
    //将函数的结果压入栈中。如果有多个返回值，可以在这里多次压入栈中。
    lua_pushnumber(L,op1 + op2);
    //返回值用于提示该C函数的返回值数量，即压入栈中的返回值数量。
    return 1;
}
 
//另一个待Lua调用的C注册函数。
static int sub2(lua_State* L)
{
    double op1 = luaL_checknumber(L,1);
    double op2 = luaL_checknumber(L,2);
    lua_pushnumber(L,op1 - op2);
    return 1;
}
#endif
 
#endif // REGISTERFUNCTIONS
 
```



```cpp
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 
#include <QMainWindow>
#include <stdio.h>
#include <iostream>
#include "../lua/src/lua.hpp"
#include <QString>
using namespace std;
#include <QStringList>
 
namespace Ui {
class MainWindow;
}
 
class MainWindow : public QMainWindow
{
    Q_OBJECT
 
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    // 注册C++函数
    void register_functions();
    int initLua();
    // 打印lua堆栈
    void PrintLuaStack();
private slots:
    void on_pushButton_clicked();     // 编译
    void on_openpushButton_clicked(); // 打开
    void on_savepushButton_clicked(); //保存
private:
    Ui::MainWindow *ui;
    lua_State *L;
};
 
#endif // MAINWINDOW_H
```



```cpp
// mainwindow.cpp
 
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerfunctions.h"
 
#include <QProcess>
#include <QDebug>
#include <QIcon>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QTextCodec>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "../lua/src/lua.hpp"
#include "../lua/src/lauxlib.h"
#include "../lua/src/lualib.h"
 
 
 
void initStyleSheet(QMainWindow* m){
    m->setStyleSheet("QMainWindow{"
                     "min-width: 700px;    "
                     "min-height: 500px;   "
                     "border-radius: 20;   "
                     "}"
                     "QPushButton {"
                     "color: black;      "
                     "border-width: 1px; "
                     "border-color: #339;"
                     "border-style: solid;"
                     //"border-radius: 2;   "
                     "padding: 3px;       "
                     "font-size: 12px;    "
                     "padding-left: 5px;  "
                     "padding-right: 5px; "
                     "background-color:white;"
                     "width: 45;"
                     "height:15;"
                     "}"
                     "QPushButton:hover{"
                     "color:white;"
                     "background-color:purple;"
                     "}"
                     "QPushButton:pressed{"
                     "color:white;"
                     "background-color:red;"
                     "}"
                     );
}
 
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Lua Code Editor");
    setWindowIcon(QIcon(":/images/lua.png"));
 
    ui->textEdit->setMaximumHeight(100);
    initStyleSheet(this);
 
    /// 设置按键的快捷方式
    ui->savepushButton->setShortcut(QKeySequence::Save);
    ui->openpushButton->setShortcut(QKeySequence::Open);
    ui->pushButton->setShortcut(QKeySequence(QLatin1String("Ctrl+P")));
 
    //新建虚拟机
    L = luaL_newstate();
    if(L == NULL){
        cout << "null" << endl;
    }
    //载入库
    luaL_openlibs(L);
 
    /// 加载注册函数
    initLua();
 
#ifdef USING_LUA_REGISTER
    register_functions();
#endif
}
 
 
 
MainWindow::~MainWindow()
{
    delete ui;
    //关闭虚拟机
    lua_close(L);
}
 
int MainWindow::initLua()
{
    for(int i = 0; i< TestFUNCNUM;i++)
    {
        lua_pushcfunction(L, MFUNC_P[i]);    // 将C函数转换为Lua的"function"并压入虚拟栈。
        lua_setglobal(L, MACROFUNCNAME[i].toUtf8().constData());    // 弹出栈顶元素，并在Lua中用名为"mysin"的全局变量存储。
    }
}
 
void MainWindow::register_functions()
{
#ifdef USING_LUA_REGISTER
    lua_register(L, "add2", add2);
    lua_register(L, "sub2", sub2);
#endif
}
 
/// 编译
void MainWindow::on_pushButton_clicked()
{
    QFile printfile("C:\\Users\\Administrator\\Desktop\\_cplusplus_lua\\LuaCodeEditor\\print.lua");
    if(!printfile.open(QIODevice::ReadWrite | QIODevice::Text)) return;
    QTextStream fileStream(&printfile);
    fileStream.setCodec(QTextCodec::codecForName("utf-8"));// 消除含有中文时乱码的问题
    QString qsAll = fileStream.readAll();
    printfile.close();
 
    qsAll +=  ui->plainTextEdit->toPlainText();
 
    qDebug() << qsAll;
 
    luaL_dostring(L, qsAll.toLatin1().constData());
 
   ::Sleep(2000);
    QFile file("D:\\GAME_LOG.txt");
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)) return;
 
    QTextStream Stream(&file  );
    Stream.setCodec(QTextCodec::codecForName("utf-8"));// 消除含有中文时乱码的问题
    QString logtext = Stream.readAll();
    qDebug() << logtext;
    ui->textEdit->append(logtext);
    file.close();
 
}
 
 
/// 打印堆栈信息
void MainWindow::PrintLuaStack()
{
    int stackTop=lua_gettop(L);//获取栈顶的索引值
    int nIdx = 0;
    int nType;
 
    printf("--stack top(v)(%d)--\n", stackTop);
    //显示栈中的元素
    for(nIdx = stackTop;nIdx > 0;--nIdx)
    {
        nType = lua_type(L, nIdx);
        printf("(i:%d) %s(%s)\n",nIdx, lua_typename(L,nType), lua_tostring(L,nIdx));
    }
    printf("--stack bottom--\n");
}
 
/// 打开文件
void MainWindow::on_openpushButton_clicked()
{
    ui->plainTextEdit->clear();
    QString filepath = QFileDialog::getOpenFileName(this,QString("open file"),QApplication::applicationDirPath(),"Lua File(*.lua)");
    QFile file(filepath);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)) return;
 
 
    QTextStream fileStream(&file  );
    fileStream.setCodec(QTextCodec::codecForName("utf-8"));// 消除含有中文时乱码的问题
    QString qsAll = fileStream.readAll();
    ui->plainTextEdit->insertPlainText(qsAll);
    file.close();
}
 
/// 保存文件
void MainWindow::on_savepushButton_clicked()
{
    QString filepath = QFileDialog::getSaveFileName(this,QString("save file"),QApplication::applicationDirPath(),"Lua File(*.lua)");
    QFile file(filepath);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)) return;
 
    QTextStream in(&file);
    in.setCodec(QTextCodec::codecForName("utf-8"));
    in << ui->plainTextEdit->toPlainText();
    file.close();
}
```

重点关注C++和Lua交互的部分：

（1）Lua库的编译。源文件可以到我的百度云盘链接下载：

链接：https://pan.baidu.com/s/1l6K2xiNQJS8023g7J5lUdQ  提取码：oa2y 

（2）c++/Lua交互，不做过多解释，查看下代码和注释即可。

```cpp
// ui_mainwindow.h
 
 
#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H
 
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <codeeditor.h>
 
QT_BEGIN_NAMESPACE
 
class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *openpushButton;
    QPushButton *savepushButton;
    QPushButton *pushButton;
    CodeEditor *plainTextEdit;
    QTextEdit *textEdit;
 
    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(551, 337);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
 
        horizontalLayout->addItem(horizontalSpacer);
 
        openpushButton = new QPushButton(centralWidget);
        openpushButton->setObjectName(QString::fromUtf8("openpushButton"));
 
        horizontalLayout->addWidget(openpushButton);
 
        savepushButton = new QPushButton(centralWidget);
        savepushButton->setObjectName(QString::fromUtf8("savepushButton"));
 
        horizontalLayout->addWidget(savepushButton);
 
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
 
        horizontalLayout->addWidget(pushButton);
 
 
        verticalLayout->addLayout(horizontalLayout);
 
        plainTextEdit = new CodeEditor(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
 
        verticalLayout->addWidget(plainTextEdit);
 
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
 
        verticalLayout->addWidget(textEdit);
 
        MainWindow->setCentralWidget(centralWidget);
 
        retranslateUi(MainWindow);
 
        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi
 
    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        openpushButton->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        savepushButton->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Compile", 0, QApplication::UnicodeUTF8));
    } // retranslateUi
 
};
 
namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui
 
QT_END_NAMESPACE
 
#endif // UI_MAINWINDOW_H
```

仅供学习参考。存在bug和需要优化的地方。后续再完善(其实也是闲来无事，随便玩玩 )。

（1）luai脚本编译信息显示需要优化。

（2）lua脚本打开可以增加支持拖拽文件打开功能。

（3）..... 其他若干云云.....