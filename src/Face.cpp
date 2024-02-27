//
// Created by tyler on 2/27/24.
//

#include "Face.h"

#include <algorithm>

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

} // ft