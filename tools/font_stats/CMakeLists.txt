
add_executable(font_stats ${CMAKE_CURRENT_LIST_DIR}/font_stats.cpp)
target_link_libraries(font_stats ${FREETYPE_LIBRARIES} ${FREETYPE_CPP_LOCATION})
target_include_directories(font_stats PRIVATE ${FREETYPE_INCLUDE_DIRS})
include_directories(font_stats  ${FREETYPE_INCLUDE_DIRS} ${FREETYPE_CPP_HEADERS})
