#include "plugin03_widgets.h"
#pragma execution_character_set("utf-8")
Plugin_widget::Plugin_widget(){}

QString Plugin_widget::show_text() const
{
    return "this is Plugin_widget";
}

QString Plugin_widget::get_name() const
{
    return "Plugin_widget";
}

void Plugin_widget::recMsgfromManager(PluginMetaData metaData)
{
    qDebug()<<"插件Plugin_widget接收到消息："<< metaData.msg;
    if(metaData.msg == "show")
        this->show();
}
