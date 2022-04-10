#ifndef  DATABASE_H
#define  DATABASE_H
#include <QObject>
#include <QColor>
class DataBase:public QObject{
    Q_OBJECT
public :
    explicit DataBase(QObject *parent=0);
    void readData();
signals :
    void readingData(int num);
    void startReadData(int total,const QString &msg);
};

#endif   // DATABASE_H
