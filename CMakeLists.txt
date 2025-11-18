cmake_minimum_required(VERSION 3.16)

project(Playground VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml)

find_package(Qt6 6.8 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appPlayground
    main.cpp
    datamodel.h
    datamodel.cpp
    navigatorcaptain.h
    navigatorcaptain.cpp
)

qt_add_qml_module(appPlayground
    URI Playground
    VERSION 1.0
    QML_FILES
        Main.qml
        DummyWidget.qml
        NavButton.qml
    SOURCES
        datamodel.cpp datamodel.h
        navigatorcaptain.cpp navigatorcaptain.h
)

# Statement for adding "SimpleMenu" as external module/plugin
add_subdirectory(ExternalModules)

set (_QML_IMPORT_PATHS "")
list(APPEND _QML_IMPORT_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ExternalModules)
set (
    QML_IMPORT_PATH
    ${QT_QML_OUTPUT_DIRECTORY}
    CACHE
    STRING
    "Path used to locate CMake modules by Qt Creator"
    FORCE
)
target_link_libraries(appPlayground
    PRIVATE simple_menuplugin)
# ------------------------------------------------------------

set_target_properties(appPlayground PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appPlayground
    PRIVATE Qt6::Quick
)

install(TARGETS appPlayground
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# ---- Play around cpp and QML interaction ----
# First try, class as instantiable QML Type
#add_compile_definitions(CPP_QML_INTERACTION_CLASS_AS_QML_TYPE)
