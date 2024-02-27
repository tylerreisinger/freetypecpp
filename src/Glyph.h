#ifndef FREETYPECPP_GLYPH_H
#define FREETYPECPP_GLYPH_H

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

#include "Types.h"

namespace ft {

class GlyphMetrics {
public:
    GlyphMetrics() = default;
    GlyphMetrics(FT_Glyph_Metrics metrics) noexcept: m_metrics(metrics) {}

    GlyphMetrics(const GlyphMetrics&) = default;
    GlyphMetrics& operator=(const GlyphMetrics&) = default;
    GlyphMetrics(GlyphMetrics&&) noexcept = default;
    GlyphMetrics& operator=(GlyphMetrics&&) noexcept = default;

    [[nodiscard]]
    FT_Glyph_Metrics raw_metrics() const noexcept { return m_metrics; }
    [[nodiscard]]
    Int26_6 width() const noexcept { return Int26_6(m_metrics.width); }
    [[nodiscard]]
    Int26_6 height() const noexcept { return Int26_6(m_metrics.height); }
    [[nodiscard]]
    Int26_6 hori_bearing_x() const noexcept { return Int26_6(m_metrics.horiBearingX); }
    [[nodiscard]]
    Int26_6 hori_bearing_y() const noexcept { return Int26_6(m_metrics.horiBearingY); }
    [[nodiscard]]
    Int26_6 hori_advance() const noexcept { return Int26_6(m_metrics.horiAdvance); }
    [[nodiscard]]
    Int26_6 vert_bearing_x() const noexcept { return Int26_6(m_metrics.vertBearingX); }
    [[nodiscard]]
    Int26_6 vert_bearing_y() const noexcept { return Int26_6(m_metrics.vertBearingY); }
    [[nodiscard]]
    Int26_6 vert_advance() const noexcept { return Int26_6(m_metrics.vertAdvance); }

private:
    FT_Glyph_Metrics m_metrics;
};

class GlyphSlot {
public:
    explicit GlyphSlot(FT_GlyphSlot slot) noexcept;
    ~GlyphSlot() = default;
    GlyphSlot(const GlyphSlot&) = default;
    GlyphSlot& operator=(const GlyphSlot&) = default;
    GlyphSlot(GlyphSlot &&) noexcept = default;
    GlyphSlot& operator=(GlyphSlot&&) noexcept = default;

    [[nodiscard]]
    FT_GlyphSlot get_handle() const noexcept { return m_glyph; }

    [[nodiscard]]
    unsigned int glyph_index() const noexcept { return m_glyph->glyph_index; }
    [[nodiscard]]
    Int16_16 linear_horizontal_advance() const noexcept { return Int16_16(m_glyph->linearHoriAdvance); }
    [[nodiscard]]
    Int16_16 linear_vertical_advance() const noexcept { return Int16_16(m_glyph->linearVertAdvance); }

    [[nodiscard]]
    Vector<Int26_6> advance() const noexcept { return {m_glyph->advance}; }
    [[nodiscard]]
    FT_Glyph_Format format() const noexcept { return m_glyph->format; }
    [[nodiscard]]
    int bitmap_left() const noexcept { return m_glyph->bitmap_left; }
    [[nodiscard]]
    int bitmap_top() const noexcept { return m_glyph->bitmap_top; }

    [[nodiscard]]
    FT_Bitmap bitmap() const noexcept { return m_glyph->bitmap; }
    [[nodiscard]]
    int lsb_delta() const noexcept { return m_glyph->lsb_delta; }
    [[nodiscard]]
    int rsb_delta() const noexcept { return m_glyph->rsb_delta; }
    [[nodiscard]]
    GlyphMetrics metrics() const noexcept { return {m_glyph->metrics}; }

    [[nodiscard]]
    bool is_rendered() const noexcept { return m_glyph->bitmap.buffer != nullptr; }

private:
    FT_GlyphSlot m_glyph = nullptr;
};

} // ft

#endif //FREETYPECPP_GLYPH_H
