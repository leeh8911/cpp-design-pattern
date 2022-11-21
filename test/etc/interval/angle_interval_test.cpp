/// @file angle_interval_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-18
///
/// @copyright Copyright (c) 2022
///

#include <gtest/gtest.h>

#include <cmath>

#include "src/etc/interval/interval.h"

namespace {
using namespace design_pattern::etc::interval;  // NOLINT

// TODO(leeh8911@gmail.com): AngularInterval have almost same Interval class
// (therefore we need Interface Interval class and make derived classes, which
// are AngularInterval and Interval)
// TODO(leeh8911@gmail.com): NEED TO UPDATE TEST CASES FOR ANGLE_INTERVAL!!!

// cppcheck-suppress syntaxError
TEST(AngleIntervalTest, CheckIncludingValue) {
    AngleInterval interval(0.0, 90.0);

    EXPECT_FALSE(interval.IsIncluded(-90.0));
    EXPECT_TRUE(interval.IsIncluded(0.0));
    EXPECT_TRUE(interval.IsIncluded(90.0));
    EXPECT_FALSE(interval.IsIncluded(180.0));
}
TEST(AngleIntervalTest, CheckIncludingValue2) {
    AngleInterval interval(-90.0, 90.0);

    EXPECT_FALSE(interval.IsIncluded(-180.0));
    EXPECT_TRUE(interval.IsIncluded(-90.0));
    EXPECT_TRUE(interval.IsIncluded(0.0));
    EXPECT_TRUE(interval.IsIncluded(90.0));
    EXPECT_FALSE(interval.IsIncluded(180.0));
}

TEST(AngleIntervalTest, Overlap) {
    AngleInterval lhs(0.0, 90.0);
    AngleInterval rhs(-10.0, 100.0);

    EXPECT_TRUE(lhs.IsOverlap(rhs));
    EXPECT_TRUE(rhs.IsOverlap(lhs));
}
TEST(AngleIntervalTest, Overlap2) {
    AngleInterval lhs(-10.0, 90.0);
    AngleInterval rhs(-20.0, -10.0);

    EXPECT_TRUE(lhs.IsOverlap(rhs));
    EXPECT_TRUE(rhs.IsOverlap(lhs));
}

TEST(AngleIntervalTest, IntersectCase) {
    auto lhs = std::make_unique<AngleInterval>(-10.0, 90.0);
    auto rhs = std::make_unique<AngleInterval>(-10.0, 100.0);

    EXPECT_EQ(AngleInterval(-10.0, 90.0), *(lhs->Intersect(std::move(rhs))));
}

// TODO(sangwon): This test currently failed.. But I don't know how to solve
// this problem..
TEST(AngleIntervalTest, IntersectCase2) {
    auto lhs = std::make_unique<AngleInterval>(-90.0, 90.0);
    auto rhs = std::make_unique<AngleInterval>(-180.0, -90.0);
    auto rhs_copy(*(rhs.get()));
    EXPECT_EQ(AngleInterval(-90.0, -90.0), *(lhs->Intersect(std::move(rhs))))
        << "lhs: " << *lhs << ", rhs: " << rhs_copy;
}
}  // namespace
