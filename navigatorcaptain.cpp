
#include "navigatorcaptain.h"

NavigatorCaptain::NavigatorCaptain(QObject *parent)
    : QObject{parent}, m_currentScreen(0)
{
}

int NavigatorCaptain::currentScreen()
{
    return m_currentScreen;
}

void NavigatorCaptain::setCurrentScreen(int nextScreen)
{
    m_currentScreen = nextScreen;
    emit currentScreenChanged();
}

int NavigatorCaptain::getPreviousScreen()
{
    return 1;
}

QObject* NavigatorCaptain::qmlInstance(QQmlEngine* engine, QJSEngine* scriptEngine)
{
    // Why engine and scriptEngine param are for ?
    Q_UNUSED(engine);
    Q_UNUSED(scriptEngine);

    // Note from spec: A QObject singleton type instance returned from a singleton type provider is owned by the QML engine unless the object has explicit QQmlEngine::CppOwnership flag set.
    // see https://doc.qt.io/qt-5/qqmlengine.html#qmlRegisterSingletonType-1
    return new NavigatorCaptain;
}

void NavigatorCaptain::goToScreen(int newScreen)
{
    setCurrentScreen(newScreen);
}
