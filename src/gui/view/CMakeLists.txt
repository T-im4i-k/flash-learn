find_package(Qt6 REQUIRED COMPONENTS Quick)
qt_standard_project_setup(REQUIRES 6.8)

file(GLOB_RECURSE VIEW_QML_FILES
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.qml")

list(TRANSFORM VIEW_QML_FILES
        REPLACE "^${CMAKE_CURRENT_SOURCE_DIR}/" "")

qt_add_library(view SHARED "")
qt_add_qml_module(view
        URI gui.view
        QML_FILES
        "${VIEW_QML_FILES}"
        PLUGIN_TARGET view)