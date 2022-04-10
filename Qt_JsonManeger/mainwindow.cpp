#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    testJson.writeObjJson();
    testJson.readObjJson();
    testJson.updateObjJson();
    qDebug()<<"\n";
    testJson.readObjJson();
    qDebug()<<"\n";
    testJson.deleteObjJson();
    qDebug()<<"\n";
    testJson.readObjJson();
}

MainWindow::~MainWindow()
{
    delete ui;
}

