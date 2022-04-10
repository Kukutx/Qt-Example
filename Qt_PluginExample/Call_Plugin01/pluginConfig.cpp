#include "pluginmanager.h"
void PluginManager::setConfig(bool isLoad)
{
    QFile file(QDir::currentPath() + "./Config.json");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        qDebug() << "can't open error!";
        return;
    }
    JsonObj.insert("runPluin", isLoad);
    jsonDoc.setObject(JsonObj);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");		// 设置写入编码是UTF8
    stream << jsonDoc.toJson();
    file.close();

    (isLoad == true) ? qDebug("Config : true") : qDebug("Config : false");
}
