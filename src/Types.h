#ifndef FREETYPECPP_TYPES_H
#define FREETYPECPP_TYPES_H

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

class Int26_6 {
public:
    explicit Int26_6(FT_Fixed value): m_value(value) {}
    ~Int26_6() = default;
    Int26_6(const Int26_6&) = default;
    Int26_6& operator=(const Int26_6&) = default;
    Int26_6(Int26_6&&) noexcept = default;
    Int26_6& operator=(Int26_6&&) noexcept = default;

    [[nodiscard]]
    FT_Fixed raw_value() const noexcept { return m_value; }
    [[nodiscard]]
    float as_float() const noexcept { return static_cast<float>(m_value) / 64.0f; }
    [[nodiscard]]
    long integer_part() const noexcept { return m_value >> 6; }
    [[nodiscard]]
    long fractional_part() const noexcept { return m_value & 0x3F; }
    [[nodiscard]]
    long ceil() const noexcept { return (m_value + 63) >> 6; }
    [[nodiscard]]
    long floor() const noexcept { return m_value >> 6; }

private:
    FT_Fixed m_value = 0;
};

class Int16_16 {
public:
    explicit Int16_16(FT_Fixed value): m_value(value) {}

    Int16_16(const Int16_16&) = default;
    Int16_16& operator=(const Int16_16&) = default;
    Int16_16(Int16_16&&) noexcept = default;
    Int16_16& operator=(Int16_16&&) noexcept = default;

    [[nodiscard]]
    FT_Fixed raw_value() const noexcept { return m_value; }
    [[nodiscard]]
    float as_float() const noexcept { return static_cast<float>(m_value) / 0xFFFF; }
    [[nodiscard]]
    long integer_part() const noexcept { return m_value >> 16; }
    [[nodiscard]]
    long fractional_part() const noexcept { return m_value & 0xFFFF; }
    [[nodiscard]]
    long ceil() const noexcept { return (m_value + 0xFFFF) >> 16; }
    [[nodiscard]]
    long floor() const noexcept { return m_value >> 16; }

private:
    FT_Fixed m_value = 0;
};

template <typename T>
class Vector {
public:
    constexpr Vector(T x, T y) noexcept: x(x), y(y) {}
    constexpr Vector(FT_Vector vector) noexcept: x(vector.x), y(vector.y) {}

    constexpr Vector(const Vector&) = default;
    constexpr Vector& operator=(const Vector&) = default;
    constexpr Vector(Vector&&) noexcept = default;
    constexpr Vector& operator=(Vector&&) noexcept = default;

    constexpr Vector<T> operator+(const Vector<T>& other) const noexcept {
        return Vector<T>(x + other.x, y + other.y);
    }
    constexpr Vector<T> operator-(const Vector<T>& other) const noexcept {
        return Vector<T>(x - other.x, y - other.y);
    }
    constexpr Vector<T>& operator+=(const Vector<T>& other) noexcept {
        x += other.x;
        y += other.y;
        return *this;
    }
    constexpr Vector<T>& operator-=(const Vector<T>& other) noexcept {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    constexpr Vector<T> operator -() const noexcept {
        return Vector<T>(-x, -y);
    }

    T x;
    T y;
};

template <typename T>
class BoundingBox {
public:
    constexpr BoundingBox() noexcept: x_min(0), y_min(0), x_max(0), y_max(0) {}
    constexpr BoundingBox(T x_min, T y_min, T x_max, T y_max) noexcept:
        x_min(x_min), y_min(y_min), x_max(x_max), y_max(y_max) {}

    constexpr BoundingBox(FT_BBox bbox) noexcept :
        x_min(bbox.xMin), y_min(bbox.yMin), x_max(bbox.xMax), y_max(bbox.yMax) {};
    constexpr BoundingBox(const BoundingBox&) = default;
    constexpr BoundingBox& operator=(const BoundingBox&) = default;
    constexpr BoundingBox(BoundingBox&&) noexcept = default;
    constexpr BoundingBox& operator=(BoundingBox&&) noexcept = default;

    [[nodiscard]]
    constexpr bool is_null() const noexcept {
        return x_min == 0 && y_min == 0 && x_max == 0 && y_max == 0;
    }


    T x_min;
    T y_min;
    T x_max;
    T y_max;
};


#endif //FREETYPECPP_TYPES_H
