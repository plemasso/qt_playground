
#include "datamodel.h"

DataModel::DataModel(QObject *parent)
    : QObject{parent}, m_myTemp(55), m_pressure(5)
{
}

int DataModel::getTemperature()
{
    return m_myTemp;
}

void DataModel::setTemperature(int newTemp)
{
    if(newTemp != m_myTemp)
    {
        m_myTemp = newTemp;
        emit temperatureChanged();
        // Note: to bind value modifications to displayed stuff on qml
        // you could also use the Connection object in the qml.
        // see the end of the video here: https://www.youtube.com/watch?v=ragZPvRe6Pk&t=626s&themeRefresh=1
        // or official doc here: https://doc.qt.io/qt-6/qml-qtqml-connections.html
    }
}

int DataModel::increaseTemperature(int deltaTemp)
{
    if(deltaTemp > 0 && deltaTemp < 5)
    {
        setTemperature(m_myTemp + deltaTemp);
    }
    return m_myTemp;
}

int DataModel::decreaseTemperature(int deltaTemp)
{
    if(deltaTemp > 0 && deltaTemp < 5)
    {
        setTemperature(m_myTemp - deltaTemp);
    }
    return m_myTemp;
}

void DataModel::resetTemp()
{
    qDebug() << "Slots called, reset temp";
    m_myTemp = 12;
    emit temperatureChanged();
}
