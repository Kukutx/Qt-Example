#include "thread.h"
#include <QDebug>

int i=50;
QMutex mutex;
MyThread::MyThread(QString name):QThread(),mName(name)
{
    qDebug()<<"creating.."<<endl;
}

void MyThread::run()
{
    qDebug()<<this->mName<<"running.."<<endl;
    mutex.lock();                 //当开启锁后会先执行锁以下的代码（同步）直到解锁后才是异步
    /*
    for(;i<100;i++)
    {
        qDebug()<<this->mName<<i<<endl;

    }
    */
    i++;
    i*=2;
    qDebug()<<this->mName<<i<<endl;
    mutex.unlock();

    qDebug()<<this->mName<<"stop running.."<<endl;
    sleep(1);

}
