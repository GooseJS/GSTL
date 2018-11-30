#include <gtest/gtest.h>

#include "gstl/math/Vec2.h"

TEST(Vec2Test, Vec2Construct_VOID_FLOAT)
{
    GSTL::Vec2<float> vec2;
    EXPECT_EQ(vec2.x(), 0);
    EXPECT_EQ(vec2.y(), 0);
}

TEST(Vec2Test, Vec2Construct_COPY)
{
    GSTL::Vec2<float> vec2(0.2f, 0.5f);
    GSTL::Vec2<float> copy = vec2;
    EXPECT_EQ(copy.x(), 0.2f);
    EXPECT_EQ(copy.y(), 0.5f);
}

TEST(Vec2Test, Vec2Add_T_FUNC)
{
    GSTL::Vec2<int> vec2(5, 10);
    vec2.add(5, 2);
    EXPECT_EQ(vec2.x(), 10);
    EXPECT_EQ(vec2.y(), 12);
}

TEST(Vec2Test, Vec2Add_VEC_FUNC)
{
    GSTL::Vec2<int> vec2(5, 10);
    GSTL::Vec2<int> secondVec2(5, 2);
    vec2.add(secondVec2);
    EXPECT_EQ(vec2.x(), 10);
    EXPECT_EQ(vec2.y(), 12);
}

TEST(Vec2Test, Vec2Add_VEC_OVERLOAD)
{
    GSTL::Vec2<int> vec2(5, 10);
    GSTL::Vec2<int> secondVec2(5, 2);
    GSTL::Vec2<int> result = vec2 + secondVec2;
    EXPECT_EQ(result.x(), 10);
    EXPECT_EQ(result.y(), 12);
}

TEST(Vec2Test, Vec2Subtract_T_FUNC)
{
    GSTL::Vec2<int> vec2(5, 10);
    vec2.subtract(5, 2);
    EXPECT_EQ(vec2.x(), 0);
    EXPECT_EQ(vec2.y(), 8);
}

TEST(Vec2Test, Vec2Subtract_VEC_FUNC)
{
    GSTL::Vec2<int> vec2(5, 10);
    GSTL::Vec2<int> secondVec2(5, 2);
    vec2.subtract(secondVec2);
    EXPECT_EQ(vec2.x(), 0);
    EXPECT_EQ(vec2.y(), 8);
}

TEST(Vec2Test, Vec2Subtract_VEC_OVERLOAD)
{
    GSTL::Vec2<int> vec2(5, 10);
    GSTL::Vec2<int> secondVec2(5, 2);
    GSTL::Vec2<int> result = vec2 - secondVec2;
    EXPECT_EQ(result.x(), 0);
    EXPECT_EQ(result.y(), 8);
}

TEST(Vec2Test, Vec2Equals_FUNC)
{
    GSTL::Vec2<float> vec2(1.4f, 10.7f);
    GSTL::Vec2<float> equalTo(1.4f, 10.7f);
    GSTL::Vec2<float> notEqualTo(1.5f, 12.4f);
    EXPECT_TRUE(vec2.equals(equalTo));
    EXPECT_FALSE(vec2.equals(notEqualTo));
}