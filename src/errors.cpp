#include "errors.h"
#include <format>

namespace ft {

FreeTypeError::FreeTypeError(FT_Error error) noexcept : m_error(error) {
    m_message = std::format("FreeType returned error code {}.", m_error);
}
}

