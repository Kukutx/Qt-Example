#include "plugin02.h"

Plugin02::Plugin02(){}

QString Plugin02::show_text() const
{
    return "this is Plugin02";
}

QString Plugin02::get_name() const
{
    return "Plugin02";
}

void Plugin02::recMsgfromManager(PluginMetaData metaData)
{
    qDebug()<<"插件Plugin02接收到消息："<< metaData.msg;
}
