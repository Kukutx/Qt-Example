#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCodec>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    started=false;
    m_process = new QProcess(this);
    connect(m_process, SIGNAL(readyRead()), this, SLOT(setStdout()));
    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(command()) );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setStdout()
{
    if(QSysInfo::productType()=="windows")
    {
        QTextCodec *codec = QTextCodec::codecForName("gb2312");
        ui->textEdit->append( codec->toUnicode(m_process->readAllStandardOutput() ) );
    }
    else
        ui->textEdit->append( m_process->readAllStandardOutput() );
    m_process->close();
    m_process->waitForFinished(30000);
    ui->lineEdit->setEnabled(true);
}
void MainWindow::command()
{
    ui->lineEdit->setDisabled(true);
    QString strCommand;
    strCommand += ui->lineEdit->text();
    qDebug() << strCommand;
    m_process->start("C:\\Windows\\System32\\cmd.exe",QStringList() << "/K" << strCommand);
    m_process->waitForReadyRead();
}
