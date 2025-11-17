
#ifndef SIMPLEMENUMODEL_H
#define SIMPLEMENUMODEL_H

#include <QtQml/qqmlextensionplugin.h>
#include <QObject>
#include <QQmlEngine>

Q_IMPORT_QML_PLUGIN(SimpleMenuPlugin)

class SimpleMenuModel : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit SimpleMenuModel(QObject *parent = nullptr);

signals:

};

#endif // SIMPLEMENUMODEL_H
