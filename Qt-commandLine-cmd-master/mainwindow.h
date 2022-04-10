#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QProcess>
#include <QStringList>
#include <QString>
#include <QIODevice>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    bool started;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void setStdout();
    void command();
private:
    Ui::MainWindow *ui;
    QProcess *m_process;
};

#endif // MAINWINDOW_H
