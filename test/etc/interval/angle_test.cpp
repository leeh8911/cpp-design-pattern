/// @file angle_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-18
///
/// @copyright Copyright (c) 2022
///
//

#include "src/etc/interval/angle.h"

#include <gtest/gtest.h>
namespace {

using namespace design_pattern::etc::interval;  // NOLINT

// cppcheck-suppress syntaxError
TEST(AngleTest, BaseAngleTest) {
    Angle a;
    EXPECT_DOUBLE_EQ(0.0, a.Radian());
    EXPECT_DOUBLE_EQ(0.0, a.Degree());

    a.Degree(180.0);
    EXPECT_DOUBLE_EQ(M_PI, a.Radian());
    EXPECT_DOUBLE_EQ(180.0, a.Degree());

    a.Radian(M_PI);
    EXPECT_DOUBLE_EQ(M_PI, a.Radian());
    EXPECT_DOUBLE_EQ(180.0, a.Degree());
}

TEST(AngleTest, AngleExistRange0To360) {
    EXPECT_EQ(Angle(360), Angle(0));
    EXPECT_EQ(Angle(360 * 2), Angle(0));
    EXPECT_EQ(Angle(-360), Angle(0));
    EXPECT_EQ(Angle(-360 * 2), Angle(0));

    EXPECT_EQ(Angle(-1), Angle(359));
    EXPECT_EQ(Angle(-360.0 + -1.), Angle(359));
}

TEST(AngleTest, AddOperation) {
    EXPECT_EQ(Angle(10) + Angle(30), Angle(40));
    EXPECT_EQ(Angle(270) + Angle(180), Angle(90));
}
TEST(AngleTest, SubOperation) {
    EXPECT_EQ(Angle(30) - Angle(20), Angle(10));
    EXPECT_EQ(Angle(90) - Angle(90), Angle(0));
    EXPECT_EQ(Angle(90 + 360) - Angle(90), Angle(0));
    EXPECT_EQ(Angle(90 - 360) - Angle(90), Angle(0));
}
TEST(AngleTest, MultOperation) {
    EXPECT_EQ(Angle(30) * 3., Angle(90));
    EXPECT_EQ(Angle(90) * 4., Angle(0));
    EXPECT_EQ(Angle(90) * -3., Angle(90));
    EXPECT_EQ(Angle(90) * -4., Angle(0));
}
TEST(AngleTest, DivOperation) {
    EXPECT_EQ((Angle(30) / 3.), Angle(10));
    EXPECT_EQ((Angle(90) / (1 / 4.)), Angle(90) * 4.);
    EXPECT_EQ((Angle(90) / (1 / (-3.))), (Angle(90) * -3.));
    EXPECT_EQ((Angle(90) / (1 / (-4.))), (Angle(90) * -4.));
}
}  // namespace
