
#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>
#include <QQmlEngine>

class DataModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int temperature READ getTemperature WRITE setTemperature  NOTIFY temperatureChanged)
    Q_PROPERTY(int pressure MEMBER m_pressure WRITE setPressure NOTIFY pressureChanged)
    // Not sure what QML_ELEMENT is for
    // It works without, but spec said should be there if
    // you want to register your object/value type
    QML_ELEMENT
public:
    explicit DataModel(QObject *parent = nullptr);

    int getTemperature();

    void setTemperature(int newTemp);
    void setPressure(int newPressure)
    {
        if(newPressure > 7) return;
        m_pressure = newPressure;
        emit pressureChanged();
    }

    // Q_INVOKABLE allow the methods to be exposed to the QML
    Q_INVOKABLE int increaseTemperature(int deltaTemp);
    Q_INVOKABLE int decreaseTemperature(int deltaTemp);

public slots:
    void resetTemp();

signals:
    void temperatureChanged();
    void pressureChanged();

private:
    int m_myTemp;
    int m_pressure;

};

#endif // DATAMODEL_H
