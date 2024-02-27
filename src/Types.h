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


#endif //FREETYPECPP_TYPES_H
