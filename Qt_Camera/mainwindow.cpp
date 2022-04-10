#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPen>
#include <QPainter>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //申请空间
    camera=new QCamera(this); //系统摄像设备（摄像头）
    viewfinder=new QCameraViewfinder(this);//摄像取景器部件
    imageCapture=new QCameraImageCapture(camera); //截图部件  指定父对象camera 依赖摄像头截图

    camera->setViewfinder(viewfinder);//申请好的取景部件给摄像头
    camera->start();//运行摄像头

    //注意：
    //ImageView是 horizontalLayout 类的对象
    //ImageCapture是Lable 类的对象
    ui->ImageView ->addWidget(viewfinder);//摄像头取到的景放入ImageView
    ui->ImageCapture->setScaledContents(true); //让图片适应ImageCapture的大小

    //horizontalLayout 类有捕捉图像的功能
    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(displayImage(int,QImage)));
    connect(ui->buttonCapture, SIGNAL(clicked()), this, SLOT(captureImage()));
    connect(ui->buttonSave, SIGNAL(clicked()), this, SLOT(saveImage()));
    connect(ui->buttonQuit, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::captureImage()
{
        imageCapture->capture();
}

void MainWindow::displayImage(int , QImage image)
{
        ui->ImageCapture->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::saveImage()
{
        QString fileName=QFileDialog::getSaveFileName(this, tr("save file"), "../", tr("Images (*.png *.xpm *.jpg)"));
        //返回的是文件路径字符串  ， 第四个参数是设置可以保存的类型
        if(fileName.isEmpty()) {
                return;
        }
        const QPixmap* pixmap=ui->ImageCapture->pixmap();//使用一种画布指向图片
        if(pixmap) {
                pixmap->save(fileName); //保存画布
        }
}
