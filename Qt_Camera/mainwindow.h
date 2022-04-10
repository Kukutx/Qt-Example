#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>//系统摄像设备（摄像头）
#include <QCameraViewfinder>//摄像取景器部件
#include <QCameraImageCapture>//截图部件
#include <QFileDialog> //保存时候打开文件窗口

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    //定义槽函数
    void captureImage();
    void displayImage(int,QImage);
    void saveImage();
private:
    Ui::MainWindow *ui;

    QCamera *camera;
    QCameraViewfinder *viewfinder;
    QCameraImageCapture *imageCapture;
};
#endif // MAINWINDOW_H
