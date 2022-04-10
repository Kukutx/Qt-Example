#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<Windows.h>
#include<QMessageBox>
#include<QDebug>
#include<tlhelp32.h>
#pragma comment  (lib, "User32.lib")
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//    void GetProcessList();
    void SetTableWdiget(QStringList strList);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
