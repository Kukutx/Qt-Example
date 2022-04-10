// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerfunctions.h"

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
    return 0;
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
    QFile printfile("C:\\Users\\liuzh\\Downloads\\QtLuaEditor\\print.lua");
    if(!printfile.open(QIODevice::ReadWrite | QIODevice::Text)) return;
    QTextStream fileStream(&printfile);
    fileStream.setCodec(QTextCodec::codecForName("utf-8"));// 消除含有中文时乱码的问题
    QString qsAll = fileStream.readAll();
    printfile.close();
    qsAll +=  ui->plainTextEdit->toPlainText();
    qDebug() << qsAll;

    luaL_dostring(L,qsAll.toLatin1().constData());
    //这里需要知道怎么输出到text控件上

    ::Sleep(2000);
    QFile file(".\\GAME_LOG.txt");
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)) return;

    QTextStream Stream(&file);
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
