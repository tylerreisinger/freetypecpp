//
// Created by tyler on 2/27/24.
//

#include "Glyph.h"

namespace ft {
    GlyphSlot::GlyphSlot(FT_GlyphSlot slot) noexcept: m_glyph(slot) {}
} // ft