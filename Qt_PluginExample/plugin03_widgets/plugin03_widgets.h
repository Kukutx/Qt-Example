#ifndef PLUGIN_WIDGET_H
#define PLUGIN_WIDGET_H

#include "PluginInterface.h"
#include <QDebug>
#include <QWidget>

class Plugin_widget : public QWidget,public PluginInterface
{
    Q_OBJECT
    Q_INTERFACES(PluginInterface)
    Q_PLUGIN_METADATA(IID "Plugin_widget")
public:
    Plugin_widget();
    QString show_text() const Q_DECL_OVERRIDE;
    QString get_name() const Q_DECL_OVERRIDE;
    virtual void recMsgfromManager(PluginMetaData metaData) Q_DECL_OVERRIDE;

signals:
    void sendMsg2Manager(PluginMetaData) Q_DECL_OVERRIDE;
};

#endif // PLUGIN_WIDGET_H
