
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>

#include "datamodel.h"
#include "navigatorcaptain.h"
#include "ExternalModules/simplemenumodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    NavigatorCaptain myCaptain;

    // --- Option 3: via singleton register type ---
    // With this registration method:The singleton provider, or instance method,
    // is called by the QQmlEngine when the singleton is first used in QML –
    // and not when the import is first used.
    // Because of this behavior, it is very difficult to precisely control the instantiation
    // of the singleton object.
    qmlRegisterSingletonType<NavigatorCaptain>("MyNavigatorPackage", 1, 0, "MyUniqueNavigatorCaptainAPI", &NavigatorCaptain::qmlInstance);
    // ----------------------------------------------

    // --- Option 2: via register type ---
    // The class definition is open to QML
    // We can instanciate it in the QML
    // Instaciable type
    // This implies that the life of the instance is the same as the QML page,
    // when the qml is created, then the instance is created, when the qml is destroyed,
    // the instance is destroyed
    qmlRegisterType<DataModel>("MyDataModelPackage", 1, 0, "DataModelRegisteredType");
    //qmlRegisterType<SimpleMenuModel>("SimpleMenuModel", 1, 0, "SimpleMenuModelRegType");
    // ----------------------------------------------

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/Playground/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    // --- Option 1: via context property ---
    // Deprecated solution !!
    // This implies that the instance is created in the c++, can live during
    // all the application life (or defined by c++ code).
    // The instance lives in the background (of qml)
    // Need to include QQmlContext
    // Instantiate the class before, and open the instance to the QML
    // This method is useful if QML want to call c++ signals, not for inject values into QML
    // Note: You should not use context properties to inject values into your QML components.
    //       Use singletons or regular object properties instead.
    // This option seems not recommanded to exchange data with QML
    // see https://doc.qt.io/qt-6/qqmlcontext.html#setContextProperty
    // see https://doc.qt.io/qt-6/qtqml-cppintegration-contextproperties.html
    //DataModel myDataModelGlobalInstance; // -> can be c++ singleton. For QML singleton, see option 3
    //QQmlContext* rootContext = engine.rootContext();
    // set an id so that the class could be accessed via QML
    //rootContext->setContextProperty("myDataModelGlobal", &myDataModelGlobalInstance);
    // Does it generate QMLlint ? Unqualified access ? Where the object comes from ?
    // ----------------------------------------------

    return app.exec();
}
