#ifndef FREETYPECPP_LIBRARY_H
#define FREETYPECPP_LIBRARY_H

#include <algorithm>
#include <stdexcept>
#include <string_view>

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

#include "Face.h"

namespace ft {

class Library {
public:
    Library();
    explicit Library(FT_Library library) noexcept;

    Library(const Library&) = delete;
    Library& operator=(const Library&) = delete;
    Library(Library&& other) noexcept {
        std::swap(m_library, other.m_library);
    }
    Library& operator=(Library&& other) noexcept {
        if (m_library) {
            destroy();
        }
        std::swap(m_library, other.m_library);
        return *this;
    }

    ~Library() {
        destroy();
        m_library = nullptr;
    }

    [[nodiscard]]
    FT_Library get_handle() const noexcept { return m_library; }

    [[nodiscard]]
    Face construct_face(std::string_view filepath, long face_index, float width, float height = 0, unsigned int dpi = 0) const;


private:
    void destroy() {
        if (m_library) {
            FT_Done_FreeType(m_library);
        }
    }

    FT_Library m_library = nullptr;
};

} // ft

#endif //FREETYPECPP_LIBRARY_H
