#include "thread2.h"
#include <QDebug>

extern int i;
extern QMutex mutex;
MyThread2::MyThread2(QString name):QThread(),mName(name)
{
 qDebug()<<"creating.."<<endl;
}

void MyThread2::run()
{
    qDebug()<<this->mName<<"running.."<<endl;
    mutex.lock();
    /*
    for(;i>0;i--)
    {
        qDebug()<<this->mName<<i<<endl;
    }
    */
    i--;
    i/=2;
    qDebug()<<this->mName<<i<<endl;
    mutex.unlock();
    qDebug()<<this->mName<<"stop runnning.."<<endl;
    sleep(1);
}
