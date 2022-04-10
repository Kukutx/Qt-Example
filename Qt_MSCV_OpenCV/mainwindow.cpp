#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/opencv.hpp>
using namespace cv;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Mat src = imread("D:\\Picture\\999438.jpg");
    imshow("src", src);
    waitKey(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

