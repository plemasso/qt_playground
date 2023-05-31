qt_add_library(simple_menu STATIC)

qt_add_qml_module(simple_menu
    URI "SimpleMenu"
    VERSION 1.0
    QML_FILES
        SimpleMenu.qml
    SOURCES
        simplemenumodel.cpp simplemenumodel.h
    #RESOURCE_PREFIX /
    #IMPORT_PATH
)
