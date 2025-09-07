find_package(Qt6 REQUIRED COMPONENTS Quick)
qt_standard_project_setup(REQUIRES 6.8)

file(GLOB_RECURSE WIDGET_QML_FILES
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.qml")

list(TRANSFORM WIDGET_QML_FILES
        REPLACE "^${CMAKE_CURRENT_SOURCE_DIR}/" "")

qt_add_library(widget SHARED "")
qt_add_qml_module(widget
        URI gui.widget
        QML_FILES
        "${WIDGET_QML_FILES}"
        PLUGIN_TARGET widget)