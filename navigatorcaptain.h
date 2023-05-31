
#ifndef NAVIGATORCAPTAIN_H
#define NAVIGATORCAPTAIN_H


#include <QObject>
#include <QQmlEngine>

// --- Option 3: via non-instantiable QML object ---
// Because I don't want a navigator object to be instanced from QML (let's say)
// Singleton accessible object
// You can also use qmlRegisterSingletonInstance instead of following example

class NavigatorCaptain : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(int currentScreen READ currentScreen WRITE setCurrentScreen NOTIFY currentScreenChanged)

public:
    explicit NavigatorCaptain(QObject *parent = nullptr);

    void setCurrentScreen(int nextScreen);

    int currentScreen();

    Q_INVOKABLE int getPreviousScreen();
    Q_INVOKABLE void goToScreen(int newScreen);

    // This callback is called the first time the singleton is used
    // It is called by the QmlEngine
    // The singleton is seen as QML singleton, the current class is not actually
    // a real singleton (however we can do so, if needed. In the implementation of that qmlInstance,
    // we could return our instance, but we have to be careful to not remove it in the c++)
    // We could also use the set context property (option 1) and set context property with a
    // real c++ singleton, see: https://qml.guide/singletons/
    static QObject* qmlInstance(QQmlEngine *engine, QJSEngine *scriptEngine);

public slots:

signals:
    void currentScreenChanged();

private:
    int m_currentScreen;
};

#endif // NAVIGATORCAPTAIN_H
