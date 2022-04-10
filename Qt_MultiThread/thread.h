#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QtCore>
#include <QMutex>

class MyThread:public QThread
{
public:
    MyThread(QString name);
    void run();
private:
    QString mName;

};

#endif // MYTHREAD_H




/*
一、直接使用QMutex进行同步

创建线程方法：继承自QThread,重写void run()函数，调用成员start()启动线程，start()中可加入优先级参数。

互斥锁同步方法：void run()函数中使用QMutex来实现同步，当多个线程访问共享变量时，应使用lock/trylock和unlock将对共享变量的操作代码包裹，以保证同步访问共享变量。（C++中引起线程安全的共享资源只有两种：全局变量和静态变量）

示例代码中两个Thread均继承自QThread()，为了保证互斥锁对两个线程均可见，QMutex在一个线程CPP文件中定义，另一个线程文件做extern声明。
*/
