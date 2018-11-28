#include <gtest/gtest.h>

#include "collections/String.h"

TEST(StringTests, StringConstruct_VOID)
{
    GSTL::String string;
    EXPECT_STREQ(string.c_str(), "");
}

TEST(StringTests, StringConstruct_CHAR)
{
    GSTL::String string("Testing");
    EXPECT_STREQ(string.c_str(), "Testing");
    EXPECT_EQ(string.size(), 7);
}

TEST(StringTests, StringConstruct_COPY)
{
    GSTL::String string("Testing");
    GSTL::String string2 = string;
    EXPECT_STREQ(string2.c_str(), "Testing");
    EXPECT_EQ(string2.size(), 7);
}

TEST(StringTests, StringResize_SMALLER)
{
    GSTL::String string("Testing 1234");
    string.resize(7);
    EXPECT_STREQ(string.c_str(), "Testing");
    EXPECT_EQ(string.size(), 7);
}

TEST(StringTests, StringResize_LARGER)
{
    GSTL::String string("Testing");
    string.resize(12);
    EXPECT_STREQ(string.c_str(), "Testing");
    EXPECT_EQ(string.size(), 7);
}

TEST(StringTests, StringAppend_CHAR)
{
    GSTL::String string("Testing");
    string.append(" 1234");
    EXPECT_STREQ(string.c_str(), "Testing 1234");
    EXPECT_EQ(string.size(), 12);
}

TEST(StringTests, StringAppend_STRING)
{
    GSTL::String string("Testing");
    GSTL::String string2(" 1234");
    string.append(string2);
    EXPECT_STREQ(string.c_str(), "Testing 1234");
    EXPECT_EQ(string.size(), 12);
}

TEST(StringTests, StringCount_CHAR)
{
    GSTL::String string("aaa bbb ccc aaa cccc");
    EXPECT_EQ(string.count('a'), 6);
    EXPECT_EQ(string.count('b'), 3);
    EXPECT_EQ(string.count('c'), 7);
}

TEST(StringTests, StringCount_CHARSTAR)
{
    GSTL::String string("aaa bbb ccc aaa cccc");
    EXPECT_EQ(string.count("aaa"), 2);
    EXPECT_EQ(string.count("bbb"), 1);
    EXPECT_EQ(string.count("ccc"), 2);
}

TEST(StringTests, StringSubString)
{
    GSTL::String string("This is a test");
    GSTL::String substring = string.substring(5, 9);
    EXPECT_STREQ(substring.c_str(), "is a");
}