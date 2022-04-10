#include "widget.h"

//#include <QApplication>
//#include <QSplashScreen>
//class DataBase{//模拟一个读取数据库数据的代码，以加长启动时间
//public:
//    void readData()    {
//        for (int i = 0; i < 100000; ++i)
//        {
//            qDebug("reading data");
//        }
//    }
//};
//int main(int argc, char *argv[]){
//    /*
//     * 所谓启动动画，就是说当一个应用程序启动时，在展示主窗口之前，有可能会先去初始化一些运行环境，验证用户信息等前提工作。
//     * 那么在这段空闲期程序的启动过程是没有用户界面的，而用户也无法得知程序的状态，所以就需要在这段空白时间中，
//     * 向用户提供一个展示程序运行状态的窗口，来为用户提供积极的正反馈。
//     * 启动动画在很多软件中得到了应用，例如游戏加载画面，VS的启动画面等。
//    */
//    QApplication a(argc, argv);
//    QSplashScreen splash(QPixmap("D:/Picture/images.jpg"));
//    splash.show();
//    DataBase db;
//    db.readData();
//    QWidget w;
//    w.show();
//    splash.finish(&w);
//    return a.exec();
//}



#include <QApplication>
#include "splashscreen.h"
#include "database.h"
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    splashscreen splash(QPixmap("D:/Picture/61358650.jpg"));
    splash.show();
    a.processEvents();
    DataBase db;
    QObject::connect(&db, SIGNAL(startReadData(int, QString)),
                    &splash, SLOT(showProgressMessage(int,QString))
                    );
    QObject::connect(&db, SIGNAL(readingData(int)),
                    &splash, SLOT(updateProgress(int))
                    );
    db.readData();
    QWidget w;
    w.show();
    splash.finish(&w);
    return a.exec();
}
