#ifndef FREETYPECPP_FACE_H
#define FREETYPECPP_FACE_H

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

#include "Glyph.h"

namespace ft {

class Face {
public:
    explicit Face(FT_Face face) noexcept;

    Face(const Face&) = delete;
    Face& operator=(const Face&) = delete;
    Face(Face&& other) noexcept;
    Face& operator=(Face&& other) noexcept;
    ~Face() noexcept;

    [[nodiscard]]
    long num_faces() const noexcept { return m_face->num_faces; }
    [[nodiscard]]
    long current_face_index() const noexcept { return m_face->face_index; }
    [[nodiscard]]
    long face_flags() const noexcept { return m_face->face_flags; }
    [[nodiscard]]
    long style_flags() const noexcept { return m_face->style_flags; }
    [[nodiscard]]
    long num_glyphs() const noexcept { return m_face->num_glyphs; }
    [[nodiscard]]
    const char* family_name() const noexcept { return m_face->family_name; }
    [[nodiscard]]
    const char* style_name() const noexcept { return m_face->style_name; }
    [[nodiscard]]
    BoundingBox<FT_Pos> bbox() const noexcept { return {m_face->bbox}; }
    [[nodiscard]]
    unsigned short units_per_EM() const noexcept { return m_face->units_per_EM; }
    [[nodiscard]]
    short ascender() const noexcept { return m_face->ascender; }
    [[nodiscard]]
    short descender() const noexcept { return m_face->descender; }
    [[nodiscard]]
    short height() const noexcept { return m_face->height; }
    [[nodiscard]]
    short max_advance_width() const noexcept { return m_face->max_advance_width; }
    [[nodiscard]]
    short max_advance_height() const noexcept { return m_face->max_advance_height; }
    [[nodiscard]]
    short underline_position() const noexcept { return m_face->underline_position; }
    [[nodiscard]]
    short underline_thickness() const noexcept { return m_face->underline_thickness; }

    [[nodiscard]]
    GlyphSlot current_glyph() const noexcept { return GlyphSlot(m_face->glyph); }
    GlyphSlot current_glyph() noexcept { return GlyphSlot(m_face->glyph); }
    std::optional<GlyphSlot> load_glyph(unsigned int glyph_index, bool render = true);
    std::optional<GlyphSlot> load_char(char32_t char_code, bool render = true);

    [[nodiscard]]
    FT_Face get_handle() const noexcept { return m_face; }
private:
    void destroy() noexcept;

    FT_Face m_face = nullptr;
};

} // ft

#endif //FREETYPECPP_FACE_H
