#ifndef MYTHREAD2_H
#define MYTHREAD2_H
#include <QThread>
#include <QMutex>
class MyThread2:public QThread
{
public:
    MyThread2(QString name);
    void run();
private:
    QString mName;

};

#endif // MYTHREAD2_H
