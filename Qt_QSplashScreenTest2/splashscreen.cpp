#include "splashscreen.h"
#include "ui_splashscreen.h"

splashscreen::splashscreen(QPixmap pixmap,QWidget *parent) :
    QSplashScreen(parent,pixmap),
    ui(new Ui::splashscreen)
{
    ui->setupUi(this);
    bar = new QProgressBar(this);
    //设置进度条的位置
    bar->setGeometry(0,pixmap.height()-50,pixmap.width(),30);
    resize(pixmap.size());
}

splashscreen::~splashscreen(){
    delete ui;
}

void splashscreen::setRange(int min, int max){
    bar->setRange(min, max);
}

void splashscreen::updateProgress(int num){
    bar->setValue(num);
}

void splashscreen::showProgressMessage(int total, const QString &msg){
    bar->setRange(0, total);
    showMessage(msg);
}
