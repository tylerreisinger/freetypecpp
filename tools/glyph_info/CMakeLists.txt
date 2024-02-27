
add_executable(glyph_info ${CMAKE_CURRENT_LIST_DIR}/glyph_info.cpp)
target_link_libraries(glyph_info ${FREETYPE_LIBRARIES} ${FREETYPE_CPP_LOCATION})
target_include_directories(glyph_info PRIVATE ${FREETYPE_INCLUDE_DIRS})
include_directories(glyph_info  ${FREETYPE_INCLUDE_DIRS} ${FREETYPE_CPP_HEADERS})
