// SPDX-License-Identifier: MIT
// Copyright (c) 2024 AlgorIT Software Consultancy, the Netherlands

//#include <gtest/gtest.h>
#include <cstring>

import sqlite.capi3;

// TEST(SQLite3cppmTest, LibVersion)
// {
//     EXPECT_STREQ(sqlite::capi3::libversion(), sqlite::capi3::version);
//     EXPECT_EQ(sqlite::capi3::libversion_number(), sqlite::capi3::version_number);
//     EXPECT_STREQ(sqlite::capi3::sourceid(), sqlite::capi3::source_id);
// }

int main()
{
    return (std::strcmp(sqlite::capi3::libversion(), sqlite::capi3::version) != 0);
}
