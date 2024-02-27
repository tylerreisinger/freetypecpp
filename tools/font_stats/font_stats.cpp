#include <iostream>

#include "Face.h"

#include "Library.h"

void print_stats();

int main(int argc, char** argv) {
    print_stats();

    return 0;
}

void print_stats() {
    ft::Library library;

    auto face = library.construct_face("../tools/resources/DejaVuSerif.ttf", 0);

    std::cout << "Face Family Name: " << face.family_name() << '\n';
    std::cout << "Face Style Name: " << face.style_name() << '\n';
    std::cout << "Total Faces: " << face.num_faces() << '\n';
    std::cout << "Glyph Count: " << face.num_glyphs() << '\n';
    std::cout << "Units per EM: " << face.units_per_EM() << '\n';
    std::cout << "Ascender: " << face.ascender() << '\n';
    std::cout << "Descender: " << face.descender() << '\n';
    std::cout << "Height: " << face.height() << '\n';
    std::cout << "Max Advance Width: " << face.max_advance_width() << '\n';
    std::cout << "Max Advance Height: " << face.max_advance_height() << '\n';
    std::cout << "Underline Position: " << face.underline_position() << '\n';
    std::cout << "Underline Thickness: " << face.underline_thickness() << '\n';
    std::cout << "Face Flags: " << face.face_flags() << '\n';
    std::cout << "Style Flags: " << face.style_flags() << '\n';
    std::cout << "Bounding Box: [" << face.bbox().xMin << ", " << face.bbox().yMin << "], ["
        << face.bbox().xMax << ", " << face.bbox().yMax << "]\n";
}