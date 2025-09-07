find_package(Qt6 REQUIRED COMPONENTS Quick)
qt_standard_project_setup(REQUIRES 6.8)

file(GLOB_RECURSE ELEMENT_QML_FILES
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.qml")

list(TRANSFORM ELEMENT_QML_FILES
        REPLACE "^${CMAKE_CURRENT_SOURCE_DIR}/" "")

qt_add_library(element SHARED "")
qt_add_qml_module(element
        URI gui.element
        QML_FILES
        "${ELEMENT_QML_FILES}"
        PLUGIN_TARGET element)