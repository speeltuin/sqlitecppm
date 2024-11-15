#include "gtest/gtest.h"
#include <cstring>

import speech;

TEST(SQLitecppmTest, True)
{
    EXPECT_STREQ(get_phrase(), "Hello, world!");
}
