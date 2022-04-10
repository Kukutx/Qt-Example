#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdio.h>
#include <iostream>
#include <QString>
#include <QStringList>
#include <QProcess>
#include <QDebug>
#include <QIcon>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QTextCodec>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "lua/src/lua.hpp"
#include "lua/src/lauxlib.h"
#include "lua/src/lualib.h"

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    // 注册C++函数
    void register_functions();
    int initLua();
    // 打印lua堆栈
    void PrintLuaStack();
private slots:
    void on_pushButton_clicked();     // 编译
    void on_openpushButton_clicked(); // 打开
    void on_savepushButton_clicked(); //保存
private:
    Ui::MainWindow *ui;
    lua_State *L;
};

#endif // MAINWINDOW_H
