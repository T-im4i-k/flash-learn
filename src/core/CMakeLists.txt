add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/alias/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/card/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/deck/")

add_library(core INTERFACE)
target_link_libraries(core INTERFACE alias card deck)