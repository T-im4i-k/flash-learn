cmake_minimum_required(VERSION 3.28)

project(flash_learn
        DESCRIPTION "A lightweight GUI application for creating and studying flashcards."
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src/")

enable_testing()
#add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/test/")