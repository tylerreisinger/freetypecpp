#ifndef FREETYPECPP_ERRORS_H
#define FREETYPECPP_ERRORS_H

#include <exception>
#include <string>
#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

#define FT_CHECK(expr) { \
    FT_Error ft_error = (expr); \
    if (ft_error) { \
        throw ft::FreeTypeError(ft_error); \
    }                    \
}


namespace ft {
class FreeTypeError : public std::exception {
public:
    explicit FreeTypeError(FT_Error error) noexcept;

    FreeTypeError(const FreeTypeError&) = default;
    FreeTypeError(FreeTypeError&&) = default;
    FreeTypeError& operator=(const FreeTypeError&) = default;
    FreeTypeError& operator=(FreeTypeError&&) = default;

    const char* what() const noexcept override {
        return m_message.c_str();
    }

    FT_Error m_error = 0;

private:
    std::string m_message;
};
}

#endif //FREETYPECPP_ERRORS_H
