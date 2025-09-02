file(GLOB_RECURSE CARD_SRC_FILES
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(card SHARED "${CARD_SRC_FILES}")
target_include_directories(card PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries(card PUBLIC alias)