/// @file strategy_point_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-23
///
/// @copyright Copyright (c) 2022
///
//
#include <gtest/gtest.h>

#include "src/behavior/strategy/point.h"

using namespace design_pattern::behavior::strategy;  // NOLINT

namespace {

TEST(StrategyPointTest, AddOperatorTrivialCase) {
    Point a(0.0, 0.0);
    Point b(0.0, 0.0);

    Point add = a + b;
    EXPECT_EQ(Point(0.0, 0.0), add);
}

// cppcheck-suppress syntaxError
TEST(StrategyPointTest, AddOperatorToZeroCase) {
    Point a(1.0, 2.0);
    Point b(-1.0, -2.0);

    Point add = a + b;

    EXPECT_EQ(Point(0.0, 0.0), add);
}

TEST(StrategyPointTest, AddOperatorToNonZeroCase) {
    Point a(1.0, -7.0);
    Point b(-7.0, 3.0);

    Point add = a + b;

    EXPECT_EQ(Point(-6.0, -4.0), add);
}

TEST(StrategyPointTest, MultOperatorTrivialCase) {
    Point a(1.0, 1.0);
    double scalar = 0.0;

    Point mult_left = scalar * a;
    Point mult_right = a * scalar;

    EXPECT_EQ(Point(0.0, 0.0), mult_left);
    EXPECT_EQ(Point(0.0, 0.0), mult_right);
}

TEST(StrategyPointTest, MultOperatorToNonZeroCase) {
    Point a(1.0, 1.0);
    double scalar = 3.0;

    Point mult_left = scalar * a;
    Point mult_right = a * scalar;

    EXPECT_EQ(Point(3.0, 3.0), mult_left);
    EXPECT_EQ(Point(3.0, 3.0), mult_right);
}

TEST(StrategyPointTest, DivOperatorTrivialCase) {
    Point a(5.0, 5.0);
    double scalar = 5.0;

    Point div = a / scalar;

    EXPECT_EQ(Point(1.0, 1.0), div);
}
TEST(StrategyPointTest, DivOperatorWrongCase) {
    Point non_zero_point(5.0, 5.0);
    Point zero_point(0.0, 0.0);

    double zero = 0.0;
    double non_zero = 1.0;

    Point div_over_point = non_zero_point / non_zero;
    Point div_over_scalar = non_zero / non_zero_point;

    EXPECT_THROW(non_zero_point / zero, std::invalid_argument);
    EXPECT_THROW(non_zero / zero_point, std::invalid_argument);

    EXPECT_EQ(Point(5.0, 5.0), div_over_point);
    EXPECT_EQ(Point(1.0 / 5.0, 1.0 / 5.0), div_over_scalar);
}

TEST(StrategyPointTest, DistanceTrivialCase) {
    Point p(10.0, 10.0);

    double distance = Point::Distance(p, p);

    EXPECT_EQ(0.0, distance);
}
TEST(StrategyPointTest, DistanceOneMeterCase) {
    Point lhs(10.0, 10.0);
    Point rhs(10.0, 9.0);

    double distance = Point::Distance(lhs, rhs);

    EXPECT_EQ(1.0, distance);
}
}  // namespace
