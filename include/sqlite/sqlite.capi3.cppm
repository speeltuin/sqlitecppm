// SPDX-License-Identifier: MIT
// Copyright (c) 2024 AlgorIT Software Consultancy, the Netherlands

module;

#include "sqlite3.h"

export module sqlite.capi3;

namespace sqlite::capi3
{

// The version of the sqlite3 header that we are including.
export constexpr const char version[] = SQLITE_VERSION;
export constexpr const int version_number = SQLITE_VERSION_NUMBER;
export constexpr const char source_id[] = SQLITE_SOURCE_ID;

// The version of the sqlite3 library that we are linking to.
export [[nodiscard]] const char* libversion() noexcept
{ return ::sqlite3_libversion(); }
export [[nodiscard]] int libversion_number() noexcept
{ return ::sqlite3_libversion_number(); }
export [[nodiscard]] const char* sourceid() noexcept
{ return ::sqlite3_sourceid(); }

} // namespace sqlite::capi3
