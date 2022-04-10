#include "mainwindow.h"

#include <QApplication>
#include <QSharedMemory>
#include <QMessageBox>

#if defined Q_OS_WIN32   //for win
#include <windows.h>
bool checkOnly()
{
    //  创建互斥量
    HANDLE m_hMutex  =  CreateMutex(NULL, FALSE,  L"fortest_abc123" );
    //  检查错误代码
    if  (GetLastError()  ==  ERROR_ALREADY_EXISTS)  {
      //  如果已有互斥量存在则释放句柄并复位互斥量
     CloseHandle(m_hMutex);
     m_hMutex  =  NULL;
      //  程序退出
      return  false;
    }
    else
        return true;
}
#endif


#if defined  Q_OS_LINUX   //for linux
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
bool checkOnly()
{
    const char filename[]  = "/tmp/lockfile";
    int fd = open (filename, O_WRONLY | O_CREAT , 0644);
    int flock = lockf(fd, F_TLOCK, 0 );
    if (fd == -1) {
            perror("open lockfile/n");
            return false;
    }
    //给文件加锁
    if (flock == -1) {
            perror("lock file error/n");
            return false;
    }
    //程序退出后，文件自动解锁
    return true;
}
#endif


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //方案 1
//    QSharedMemory singleton(a.applicationName());  //qt防止重复启动让程序只打开一次，防止多开
//    if(!singleton.create(1))
//    {
//        QMessageBox::warning(NULL, "Waring", "Program already running!");
//        return 0;
//    }

//    //方案 2
//    if(checkOnly()==false) //检查程序是否 已经启动过
//        return 0;

    //方案 3
    HANDLE mutex = CreateMutexA(NULL, FALSE, "MyApp");           //创建一个互斥量对象 防止程序多开！
    if (GetLastError() == ERROR_ALREADY_EXISTS)              	 //如果之前已经打开了一个程序的话！那么显示错误信息并退出
    {
        QMessageBox msg;
        msg.setText("Already Running");
        msg.exec();
        CloseHandle(mutex);
        mutex=NULL;
        return 0;
    }

    MainWindow w;
    w.show();
    return a.exec();
}


