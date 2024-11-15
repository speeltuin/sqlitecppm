#include "gtest/gtest.h"
#include <cstring>

import sqlite.capi3;

TEST(SQLitecppmTest, True)
{
    EXPECT_STREQ(get_phrase(), "Hello, world!");
}
