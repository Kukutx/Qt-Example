#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <QSplashScreen>
#include <QProgressBar>
#include <QWidget>

namespace Ui {
class splashscreen;
}

class splashscreen : public QSplashScreen
{
    Q_OBJECT

public:
    explicit splashscreen(QPixmap  pixmap,QWidget *parent = nullptr);
    ~splashscreen();
    void setRange(int min ,int max);
public slots:
    //更新进度
    void updateProgress(int num);
    void showProgressMessage(int total,const QString& msg);
private:
    Ui::splashscreen *ui;
    QProgressBar* bar;  //进度条
};

#endif // SPLASHSCREEN_H
