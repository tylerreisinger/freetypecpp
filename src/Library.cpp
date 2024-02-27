//
// Created by tyler on 2/27/24.
//

#include "Library.h"
#include "errors.h"

namespace ft {
    Library::Library() {
        FT_CHECK(FT_Init_FreeType(&m_library));
    }

    Library::Library(FT_Library library) noexcept {
        m_library = library;
    }

    Face Library::construct_face(std::string_view filepath, long face_index) const {
        FT_Face face;
        FT_CHECK(FT_New_Face(m_library, filepath.data(), face_index, &face));
        return Face(face);
    }

} // ft