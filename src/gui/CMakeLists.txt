add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/launcher/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/widget/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/element/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/view/")

add_library(gui INTERFACE)
target_link_libraries(gui INTERFACE launcher widget element view)