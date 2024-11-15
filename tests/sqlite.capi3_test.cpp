#include "gtest/gtest.h"

import speech;

TEST(SQLitecppmTest, True)
{
    EXPECT_STREQ(get_phrase(), "Hello, world!");
}
