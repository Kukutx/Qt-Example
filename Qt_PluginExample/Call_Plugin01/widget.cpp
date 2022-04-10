#include "widget.h"
#include "ui_widget.h"
#pragma comment(lib, "User32.lib")
#pragma execution_character_set("utf-8")
Widget::Widget(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::Widget)
{
    ui->setupUi(this);
    readJson();


    m_systemTray = new QSystemTrayIcon(this);
    m_systemTray->setIcon(QIcon(":/res/logo.ico"));
    m_systemTray->setToolTip("SystemTray Program");
    m_systemTray->show();
    connect(m_systemTray, &QSystemTrayIcon::activated,this, [=]{
        this->show();
    });
}

Widget::~Widget()
{
    delete ui;
}
//读取json里的配置来决定 checkBox
void Widget::readJson()
{
    QFile file(QDir::currentPath() + "./Config.json");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "can't open error!";
        return;
    }
    QTextStream stream(&file);
    QString str = stream.readAll();

    jsonDoc = QJsonDocument::fromJson(str.toUtf8(), &jsonError);
    // 判断是否解析失败
    if (jsonError.error != QJsonParseError::NoError && !jsonDoc.isNull()) {
        qDebug() << "Json格式错误！" << jsonError.error;
        return;
    }

    if (jsonDoc.isObject())    //判断是否Object对象
    {
        //解析根 { }对象成员
        QJsonObject rootObj = jsonDoc.object();
        QJsonValue m_runPluin = rootObj.value("runPluin");     // 根据键获取值
        ui->checkBox->setChecked(m_runPluin.toBool());
        if(ui->checkBox->isChecked()==true){
            PluginManager * pm = PluginManager::instance();
            pm->loadAllPlugins();
        }
    }
    file.close();
}
//点击外部隐藏程序
bool Widget::event(QEvent * eve)
{
    //    if (QEvent::ActivationChange == eve->type())
    //    {
    //        if(QApplication::activeWindow() != this)
    //        {
    //            this->hide();
    //        }
    //    }
    return QWidget::event(eve);
}

//加载所有插件
void Widget::on_pushButton_clicked()
{
    PluginManager * pm = PluginManager::instance();
    pm->loadAllPlugins();
}

//插件01发消息
void Widget::on_pushButton_2_clicked()
{
    PluginManager * pm = PluginManager::instance();
    auto loader = pm->getPlugin("Plugin01");
    if(loader)
    {
        PluginInterface *plugin = qobject_cast<PluginInterface *>(loader->instance());
        PluginMetaData m;
        m.dest = "Plugin02";
        m.from = "Plugin01";
        m.msg = "插件1给插件2发的消息";
        plugin->sendMsg2Manager(m);
    }
    else
        qDebug()<<"插件不存在 ";
}

//卸载所有插件
void Widget::on_pushButton_3_clicked()
{
    PluginManager * pm = PluginManager::instance();
    pm->unloadAllPlugins();
}

//插件02发消息
void Widget::on_pushButton_4_clicked()
{
    PluginManager * pm = PluginManager::instance();
    auto loader = pm->getPlugin("Plugin02");
    if(loader)
    {
        PluginInterface *plugin = qobject_cast<PluginInterface *>(loader->instance());
        PluginMetaData m;
        m.dest = "Plugin01";
        m.from = "Plugin02";
        m.msg = "插件2给插件1发的消息";
        emit plugin->sendMsg2Manager(m);
    }else
        qDebug()<<"插件不存在 ";
}

void Widget::on_pushButton_5_clicked()
{
    PluginManager * pm = PluginManager::instance();
    auto loader = pm->getPlugin("Plugin_widget");
    if(loader)
    {
        PluginInterface *plugin = qobject_cast<PluginInterface *>(loader->instance());
        PluginMetaData m;
        m.dest = "Plugin_widget";
        m.from = "";
        m.msg = "show";
        emit plugin->sendMsg2Manager(m);
    }
}

void Widget::on_checkBox_clicked(bool checked)
{
    PluginManager *PJson=PluginManager::instance();
    PJson->setConfig(checked);
}

#include <Windows.h>
void Widget::on_integrateWidgetBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "open file", QDir::currentPath());
    QFileInfo fileInfo(fileName);
    pProcess = new QProcess(this);
    pProcess->start(fileName);
    //尝试启动进程且隐藏（失败）
//    pProcess->setCreateProcessArgumentsModifier([](QProcess::CreateProcessArguments *args)
//    {
//        args->startupInfo->dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
//        args->startupInfo->wShowWindow = SW_HIDE;
//    });
    if(!pProcess->waitForFinished(5000))
    {
        qDebug()<<"--------";
    }

    //获取句柄 //从调试输出中获取，程序的句柄id
    WId childWidgetWinId = (WId)FindWindow(NULL,(LPCWSTR)(fileInfo.baseName().toStdWString().c_str()));  //这个方法必要要程序名与窗口标题一致才能嵌入
    //WId childWidgetWinId = (WId)FindWindow(L"Notepad",NULL);
    qDebug()<<childWidgetWinId;
    childWindow = QWindow::fromWinId(childWidgetWinId);
    childWidget = QWidget::createWindowContainer(childWindow, this, Qt::Widget );
    ui->childWidgetLayout->addWidget(childWidget);
}
