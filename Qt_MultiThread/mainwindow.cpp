#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "thread.h"
#include "thread2.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyThread thread1("thread1");

    MyThread2 thread2("thread2");

    thread1.start(QThread::HighestPriority);//高优先级的任务获得更多的CPU使用比，因此先计算完成
    thread2.start();//相对低优先级的任务会后完成

    thread1.wait();
    qDebug()<<"thread1 is done!"<<endl;
    thread1.wait();
    qDebug()<<"thread2 is done!"<<endl;
//    thread1.exit();


}

MainWindow::~MainWindow()
{
    delete ui;
}

