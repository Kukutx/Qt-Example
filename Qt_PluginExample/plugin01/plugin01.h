#ifndef PLUGIN01_H
#define PLUGIN01_H

#include <QObject>
#include "PluginInterface.h"
#include <QDebug>

class Plugin01 : public QObject,public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID "my_plugin01")
public:
    Plugin01();
    QString show_text() const Q_DECL_OVERRIDE;
    QString get_name() const Q_DECL_OVERRIDE;
    virtual void recMsgfromManager(PluginMetaData metaData) Q_DECL_OVERRIDE;

signals:
    void sendMsg2Manager(PluginMetaData) Q_DECL_OVERRIDE;
};

#endif // PLUGIN01_H
