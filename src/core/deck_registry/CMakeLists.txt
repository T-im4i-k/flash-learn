file(GLOB_RECURSE DECK_REGISTRY_SRC_FILES
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(deck_registry SHARED "${DECK_REGISTRY_SRC_FILES}")
target_include_directories(deck_registry PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries(deck_registry PUBLIC card_deck alias)