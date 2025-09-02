find_package(Qt6 REQUIRED COMPONENTS Sql Core)
qt_standard_project_setup(REQUIRES 6.8)

file(GLOB_RECURSE DB_SRC_FILES
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

qt_add_library(db SHARED "${DB_SRC_FILES}")
target_include_directories(db PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries(db PUBLIC core)
target_link_libraries(db PUBLIC Qt6::Sql Qt6::Core)
