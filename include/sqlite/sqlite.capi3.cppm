module;

#include "sqlite3.h"

export module sqlite.capi3;

export [[nodiscard]] const char* libversion() noexcept
{
    return ::sqlite3_libversion();
}
