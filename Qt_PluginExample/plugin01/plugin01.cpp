#include "plugin01.h"

Plugin01::Plugin01(){}

QString Plugin01::show_text() const
{
    return "this is Plugin01";
}

QString Plugin01::get_name() const
{
    return "Plugin01";
}

void Plugin01::recMsgfromManager(PluginMetaData metaData)
{
    qDebug()<<"插件Plugin01接收到消息："<< metaData.msg;
}
