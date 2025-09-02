file(GLOB_RECURSE CARD_DECK_SRC_FILES
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(card_deck SHARED "${CARD_DECK_SRC_FILES}")
target_include_directories(card_deck PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries(card_deck PUBLIC alias)