cmake_minimum_required(VERSION 3.24)
project(freetypecpp)

set(CMAKE_CXX_STANDARD 23)

find_package(Freetype REQUIRED)

add_library(freetypecpp src/library.cpp)
target_link_libraries(freetypecpp ${FREETYPE_LIBRARIES})
target_include_directories(freetypecpp PRIVATE ${FREETYPE_INCLUDE_DIRS})