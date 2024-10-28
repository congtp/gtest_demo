#include <gtest/gtest.h>
#include <cstdio>

TEST(Sprintf, NoFormatOperation)
{
    // set up
    char output[5];
    memset(output, 0xaa, sizeof(output));

    // test 
    ASSERT_EQ(3, sprintf(output, "Hey"));
    ASSERT_STREQ("Hey", output);
    EXPECT_EQ((char)0xaa, output[4]);
}

TEST(Sprintf, InsertString)
{
    // set up
    char output[20];
    memset(output, 0xaa, sizeof(output));

    // test
    ASSERT_EQ(12, sprintf(output, "Hello %s\n", "World"));
    ASSERT_STREQ("Hello World\n", output);
    ASSERT_EQ((char)0xaa, output[13]);
}