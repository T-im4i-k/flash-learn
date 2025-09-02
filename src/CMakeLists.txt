add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/core/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/db/")

add_executable(flash_learn main.cpp)
target_link_libraries(flash_learn PRIVATE core db)