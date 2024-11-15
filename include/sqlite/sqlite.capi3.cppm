// SPDX-License-Identifier: MIT
// Copyright (c) 2024 AlgorIT Software Consultancy, the Netherlands

module;

//#include "sqlite3.h"

export module sqlite.capi3;

namespace sqlite::capi3
{

// The version of the sqlite3 header that we are including.
export constexpr const char version[] = "3.14";

// The version of the sqlite3 library that we are linking to.
export [[nodiscard]] const char* libversion() noexcept
{ return "3.14"; }

} // namespace sqlite::capi3
