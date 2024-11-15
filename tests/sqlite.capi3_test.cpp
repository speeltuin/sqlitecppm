#include "gtest/gtest.h"
#include <cstring>

import sqlite.capi3;

TEST(SQLitecppmTest, LibVersion)
{
    EXPECT_STREQ(libversion(), "3.47.0");
}
