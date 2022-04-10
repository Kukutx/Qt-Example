#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QMutexLocker>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public QThread
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QThread(parent),
        m_bStopped(false)
    {
        qDebug() << "Worker Thread : " << QThread::currentThreadId();
    }

    ~MainWindow()
    {
        stop();
        quit();
        wait();
    }

    void stop()
    {
        qDebug() << "Worker Stop Thread : " << QThread::currentThreadId();
        QMutexLocker locker(&m_mutex);
        m_bStopped = true;
    }

protected:
    virtual void run() Q_DECL_OVERRIDE {
        qDebug() << "Worker Run Thread : " << QThread::currentThreadId();
        int nValue = 0;
        while (nValue < 100)
        {
            // 休眠50毫秒
            msleep(50);
            ++nValue;

            // 准备更新
            emit resultReady(nValue);

            // 检测是否停止
            {
                QMutexLocker locker(&m_mutex);
                if (m_bStopped)
                    break;
            }
            // locker超出范围并释放互斥锁
        }
    }
signals:
    void resultReady(int value);
private:
    bool m_bStopped;
    QMutex m_mutex;
    Ui::MainWindow *ui;
};



/*
QT5.X版本以上
class WorkerThread : public QThread
{
    Q_OBJECT

public:
    explicit WorkerThread(QObject *parent = 0)
        : QThread(parent)
    {
    }

    ~WorkerThread() {
        // 请求终止
        requestInterruption();
        quit();
        wait();
    }

protected:
    virtual void run() Q_DECL_OVERRIDE {
        // 是否请求终止
        while (!isInterruptionRequested())
        {
            // 耗时操作
        }
    }
};
*/


/******************************************************************************
 * Qt优雅地结束线程   https://blog.csdn.net/caoshangpa/article/details/62421334
如果一个线程运行完成，就会结束。可很多情况并非这么简单，由于某种特殊原因，当线程还未执行完时，我们就想中止它。
不恰当的中止往往会引起一些未知错误。比如：当关闭主界面的时候，很有可能次线程正在运行，这时，就会出现如下提示：
QThread: Destroyed while thread is still running
这是因为次线程还在运行，就结束了UI主线程，导致事件循环结束。这个问题在使用线程的过程中经常遇到，尤其是耗时操作。
在此问题上，常见的两种人：
1.直接忽略此问题。
2.强制中止 - terminate()。
大多数情况下，当程序退出时，次线程也许会正常退出。这时，虽然抱着侥幸心理，但隐患依然存在，也许在极少数情况下，就会出现Crash。
正如前面提到过terminate()，比较危险，不鼓励使用。线程可以在代码执行的任何点被终止。线程可能在更新数据时被终止，从而没有机会来清理自己，解锁等等。。。总之，只有在绝对必要时使用此函数。
所以，我们应该采取合理的措施来优雅地结束线程，一般思路：
1.发起线程退出操作，调用quit()或exit()。
2.等待线程完全停止，删除创建在堆上的对象。
3.适当的使用wait()（用于等待线程的退出）和合理的算法。
下面介绍两种方式：
一.QMutex互斥锁 + bool成员变量。
这种方式是Qt4.x中比较常用的，主要是利用“QMutex互斥锁 + bool成员变量”的方式来保证共享数据的安全性（可以完全参照下面的requestInterruption()源码写法）。
#include <QThread>
#include <QMutexLocker>

class WorkerThread : public QThread
{
    Q_OBJECT

public:
    explicit WorkerThread(QObject *parent = 0)
        : QThread(parent),
          m_bStopped(false)
    {
        qDebug() << "Worker Thread : " << QThread::currentThreadId();
    }

    ~WorkerThread()
    {
        stop();
        quit();
        wait();
    }

    void stop()
    {
        qDebug() << "Worker Stop Thread : " << QThread::currentThreadId();
        QMutexLocker locker(&m_mutex);
        m_bStopped = true;
    }

protected:
    virtual void run() Q_DECL_OVERRIDE {
        qDebug() << "Worker Run Thread : " << QThread::currentThreadId();
        int nValue = 0;
        while (nValue < 100)
        {
            // 休眠50毫秒
            msleep(50);
            ++nValue;

            // 准备更新
            emit resultReady(nValue);

            // 检测是否停止
            {
                QMutexLocker locker(&m_mutex);
                if (m_bStopped)
                    break;
            }
            // locker超出范围并释放互斥锁
        }
    }
signals:
    void resultReady(int value);

private:
    bool m_bStopped;
    QMutex m_mutex;
};
为什么要加锁？很简单，是为了共享数据段操作的互斥。
何时需要加锁？在形成资源竞争的时候，也就是说，多个线程有可能访问同一共享资源的时候。
当主线程调用stop()更新m_bStopped的时候，run()函数也极有可能正在访问它（这时，他们处于不同的线程），所以存在资源竞争，因此需要加锁，保证共享数据的安全性。

二.Qt5以后：requestInterruption() + isInterruptionRequested()
这两个接口是Qt5.x引入的，使用很方便：
class WorkerThread : public QThread
{
    Q_OBJECT

public:
    explicit WorkerThread(QObject *parent = 0)
        : QThread(parent)
    {
    }

    ~WorkerThread() {
        // 请求终止
        requestInterruption();
        quit();
        wait();
    }

protected:
    virtual void run() Q_DECL_OVERRIDE {
        // 是否请求终止
        while (!isInterruptionRequested())
        {
            // 耗时操作
        }
    }
};
在耗时操作中使用isInterruptionRequested()来判断是否请求终止线程，如果没有，则一直运行；当希望终止线程的时候，调用requestInterruption()即可。
正如侯捷所言：「源码面前，了无秘密」。如果还心存疑虑，我们不妨来看看requestInterruption()、isInterruptionRequested()的源码：
void QThread::requestInterruption()
{
    Q_D(QThread);
    QMutexLocker locker(&d->mutex);
    if (!d->running || d->finished || d->isInFinish)
        return;
    if (this == QCoreApplicationPrivate::theMainThread) {
        qWarning("QThread::requestInterruption has no effect on the main thread");
        return;
    }
    d->interruptionRequested = true;
}

bool QThread::isInterruptionRequested() const
{
    Q_D(const QThread);
    QMutexLocker locker(&d->mutex);
    if (!d->running || d->finished || d->isInFinish)
        return false;
    return d->interruptionRequested;
}
^_^，内部实现居然也用了互斥锁QMutex，这样我们就可以放心地使用了。
********************************************************************/
#endif // MAINWINDOW_H
