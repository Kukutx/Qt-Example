#include "mainwindow.h"
#include "ui_mainwindow.h"
char m_Name[MAXBYTE];
char m_Title[MAXBYTE];
WORD m_nNum;
QStringList fonts;

//这里写个结构体
struct ProcessId{
    QString pstrName;
    QString pstrTitle;
    HWND pHwnd;
    WORD pm_nNum;
};
ProcessId pId[10];




BOOL CALLBACK enumAllWindow(HWND Hwnd, LPARAM IParm)//系统返还给你的窗口句柄,API调用进来的参数
{
    //每次Hwnd返回回来，都需要获取他的类名和标题
    GetClassNameA(Hwnd,m_Name,MAXBYTE);//获得指定窗口所属的类的类名
    GetWindowTextA(Hwnd,m_Title,MAXBYTE);//查找标题
    m_nNum++;
    QString strName = QString::fromLocal8Bit(m_Name);
    QString strTitle = QString::fromLocal8Bit(m_Title);
    //    qDebug()<<"ID:"<<m_nNum<<QString::fromLocal8Bit("窗口句柄:")<<Hwnd<<QString::fromLocal8Bit("窗口类名:")<<strName<<QString::fromLocal8Bit("窗口标题:")<<strTitle;
    QString str=QString::fromLocal8Bit("ID: %1 窗口句柄: 0x%2 窗口类名: %3 窗口标题: %4").arg(m_nNum).arg((int)Hwnd,4, 16, QLatin1Char('0')).arg(strName).arg(strTitle);
    fonts<<str;



//    memset(&pId,0,sizeof(pId));




    //return false;//枚举一次就不枚举了
    return true;//枚举到完毕
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_nNum = 0;
    EnumWindows(enumAllWindow,(LPARAM)"");

//    qDebug()<<pId.pstrName;

    qDebug()<<fonts;
    SetTableWdiget(fonts);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetTableWdiget(QStringList strList)
{
    QStringList headList;//设置tableWidget的表头
    headList << QString::fromLocal8Bit("进程ID") << QString::fromLocal8Bit("窗口句柄") << QString::fromLocal8Bit("窗口类名") << QString::fromLocal8Bit("窗口标题");
    ui->tableWidget->setColumnCount(4);//设置列数
    ui->tableWidget->setHorizontalHeaderLabels(headList);//设置表头
    ui->tableWidget->setColumnWidth(1,150);
//    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setItem(1,1,new QTableWidgetItem("1"));
    int i=0;
    for(QString str : strList){
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(str));
        ++i;
    }
}

