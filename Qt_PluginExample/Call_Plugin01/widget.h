#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWindow>
#include<QWidget>
#include<QSystemTrayIcon>
#include <QMenu>
#include <QPluginLoader>
#include "PluginInterface.h"
#include "pluginmanager.h"
class PluginManager;
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QProcess *pProcess;
    QWidget *childWidget=NULL;
    QWindow *childWindow=NULL;

    void readJson();
    QJsonArray jsonArray;
    QJsonDocument jsonDoc;
    QJsonObject JsonObj;
    QJsonParseError jsonError;

protected:
    QSystemTrayIcon *m_systemTray;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_checkBox_clicked(bool checked);

    void on_integrateWidgetBtn_clicked();

    bool event(QEvent * eve);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
