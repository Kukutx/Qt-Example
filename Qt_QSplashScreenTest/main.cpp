#include "mainwindow.h"
#include <QSplashScreen>
#include <QDesktopWidget>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //程序启动动画类
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("D:/Picture/images.jpg"));
    splash->show();

    //左上角
    Qt::Alignment topLeft = Qt::AlignLeft| Qt::AlignTop;
    //设置一些初始化的启动项信息
    splash->showMessage(QObject::tr("Fantast App Loading ......."),topLeft,Qt::white);

    //控制启动动画加载时长
    for(int i=0;i<10000;i++)
    {
        splash->repaint();
        //这将覆盖QWidget:重画()。
        //它与标准的重绘函数的不同之处在于，它还调用QApplication::flush()来确保更新被显示。
        //即使不存在事件循环。
    }

    MainWindow w;
    w.show();

    //将窗口移动到屏幕的中央（一般默认都会在屏幕中央）
    //w.move ((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);
    splash->finish(&w);
    delete splash;
    return a.exec();
}
