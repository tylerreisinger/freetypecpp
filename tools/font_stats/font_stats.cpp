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

    auto face = library.construct_face("../tools/resources/DejaVuSerif.ttf", 0, 16);

    std::cout << "Face Family Name: " << face.family_name() << '\n';
    std::cout << "Face Style Name: " << face.style_name() << '\n';
    std::cout << "Total Faces: " << face.num_faces() << '\n';
    std::cout << "Glyph Count: " << face.num_glyphs() << '\n';
    std::cout << "Units per EM: " << face.units_per_EM() << '\n';
    std::cout << "Ascender: " << static_cast<float>(face.ascender()) / face.units_per_EM() << " em\n";
    std::cout << "Descender: " << static_cast<float>(face.descender()) / face.units_per_EM() << " em\n";
    std::cout << "Height: " << static_cast<float>(face.height()) / face.units_per_EM() << " em\n";
    std::cout << "Max Advance Width: " << static_cast<float>(face.max_advance_width()) / face.units_per_EM() << " em \n";
    std::cout << "Max Advance Height: " << static_cast<float>(face.max_advance_height()) / face.units_per_EM() << " em \n";
    std::cout << "Underline Position: " << face.underline_position() << '\n';
    std::cout << "Underline Thickness: " << face.underline_thickness() << '\n';
    std::cout << "Face Flags: " << face.face_flags() << '\n';
    std::cout << "Style Flags: " << face.style_flags() << '\n';
    std::cout << "Bounding Box: [" << face.bbox().xMin << ", " << face.bbox().yMin << "], ["
        << face.bbox().xMax << ", " << face.bbox().yMax << "]\n";
}