cmake_minimum_required(VERSION 3.24)
project(freetypecpp)

set(CMAKE_CXX_STANDARD 23)
set(FREETYPE_CPP_LOCATION ${CMAKE_BINARY_DIR}/libfreetypecpp.a)
set(FREETYPE_CPP_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src)

find_package(Freetype REQUIRED)

add_library(freetypecpp src/library.cpp src/Library.cpp src/Library.h src/errors.cpp src/errors.h src/Face.cpp src/Face.h
        tools/font_stats/font_stats.cpp
        src/Glyph.cpp
        src/Glyph.h
        src/Types.h)
target_link_libraries(freetypecpp ${FREETYPE_LIBRARIES})
target_include_directories(freetypecpp PRIVATE ${FREETYPE_INCLUDE_DIRS})

include(tools/CMakeLists.txt)