//
// Created by tyler on 2/27/24.
//

#include "Face.h"

#include <algorithm>

#include "errors.h"

namespace ft {
    Face::Face(FT_Face face) noexcept: m_face(face) {}

    void Face::destroy() noexcept {
        if (m_face) {
            FT_Done_Face(m_face);
        }
        m_face = nullptr;
    }

    Face::Face(Face&& other) noexcept {
        if (m_face) {
            destroy();
        }
        std::swap(m_face, other.m_face);
    }

    Face& Face::operator=(Face&& other) noexcept {
        if (m_face) {
            destroy();
        }
        std::swap(m_face, other.m_face);
        return *this;
    }

    Face::~Face() noexcept {
        destroy();
    }

    std::optional<GlyphSlot> Face::load_glyph(unsigned int glyph_index, bool render) {
        FT_CHECK(FT_Load_Glyph(m_face, glyph_index, FT_LOAD_DEFAULT));
        if (render) {
            FT_CHECK(FT_Render_Glyph(m_face->glyph, FT_RENDER_MODE_NORMAL));
        }
        return GlyphSlot(m_face->glyph);
    }

    std::optional<GlyphSlot> Face::load_char(char32_t char_code, bool render) {
        FT_UInt glyph_index = FT_Get_Char_Index(m_face, char_code);
        if (glyph_index == 0) {
            return std::nullopt;
        } else {
            FT_CHECK(FT_Load_Glyph(m_face, glyph_index, FT_LOAD_DEFAULT));
            if (render) {
                FT_CHECK(FT_Render_Glyph(m_face->glyph, FT_RENDER_MODE_NORMAL));
            }
            return GlyphSlot(m_face->glyph);
        }
    }

} // ft