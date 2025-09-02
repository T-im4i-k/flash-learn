file(GLOB_RECURSE DECK_SRC_FILES
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(deck SHARED "${DECK_SRC_FILES}")
target_include_directories(deck PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries(deck PUBLIC card alias)