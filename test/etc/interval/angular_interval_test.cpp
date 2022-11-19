/// @file angular_interval_test.cpp
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

// cppcheck-suppress syntaxError
// TEST(AngularIntervalTest, CheckIncludingValue) {
//     AngularInterval interval(1.0, 3.0);

//     EXPECT_FALSE(interval.IsIncluded(0.0));

//     EXPECT_TRUE(interval.IsIncluded(1.0));
//     EXPECT_TRUE(interval.IsIncluded(2.0));
//     EXPECT_TRUE(interval.IsIncluded(3.0));

//     EXPECT_FALSE(interval.IsIncluded(4.0));
// }

}  // namespace
