#include <cstring>
#include <iostream>

#include "Library.h"

char shade_value(unsigned char value) {
    if (value == 0) {
        return ' ';
    } else if (value < 64) {
        return '.';
    } else if (value < 128) {
        return '*';
    } else if (value < 192) {
        return 'o';
    } else {
        return '#';
    }
}

int main(int argc, char** argv) {
    ft::Library library;
    auto face = library.construct_face("../tools/resources/DejaVuSerif.ttf", 0, 24, 0, 0);

    if (argc < 2) {
        return 0;
    }

    auto len = std::strlen(argv[1]);
    for (int i = 0; i < len; i++) {
        auto glyph = face.load_char(argv[1][i]);

        std::cout << "==================== Glyph: " << argv[1][i] << " ====================\n";
        std::cout << "Width: " << glyph.metrics().width().as_float() << '\n';
        std::cout << "Height: " << glyph.metrics().height().as_float() << '\n';
        std::cout << "Vertical X Bearing: " << glyph.metrics().vert_bearing_x().as_float() << '\n';
        std::cout << "Vertical Y Bearing: " << glyph.metrics().vert_bearing_y().as_float() << '\n';
        std::cout << "Y Advance: " << glyph.metrics().vert_advance().as_float() << '\n';
        std::cout << "Horizontal X Bearing: " << glyph.metrics().hori_bearing_x().as_float() << '\n';
        std::cout << "Horizontal Y Bearing: " << glyph.metrics().hori_bearing_y().as_float() << '\n';
        std::cout << "X Advance: " << glyph.metrics().hori_advance().as_float() << '\n';
        std::cout << "Advance Width: " << glyph.advance().x.as_float() << '\n';
        std::cout << "Advance Height: " << glyph.advance().y.as_float() << '\n';

        for (int y = 0; y < glyph.bitmap().rows; ++y) {
            for (int x = 0; x < glyph.bitmap().width; ++x) {
                std::cout << shade_value(glyph.bitmap().buffer[y * glyph.bitmap().pitch + x]);
            }

            std::cout << '\n';
        }
    }


    return 0;
}