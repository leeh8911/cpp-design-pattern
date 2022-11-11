/// @file interval_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-11
///
/// @copyright Copyright (c) 2022
///
//
#include "src/etc/interval/interval.h"

#include <gtest/gtest.h>

namespace
{
using namespace design_pattern::etc::interval; // NOLINT

// TODO(leeh8911@gmail.com): Interval class can reverse parameter (but its same to origin interval class)
// TODO(leeh8911@gmail.com): Interval class has from and to value
// TODO(leeh8911@gmail.com): Interval class check included value
// TODO(leeh8911@gmail.com): Interval class check overlap other interval
// TODO(leeh8911@gmail.com): Interval class calculate intersection other interval
// TODO(leeh8911@gmail.com): Interval class calculate set difference other interval
//
// TODO(leeh8911@gmail.com): Circular Interval class from, to values are circular value

TEST(IntervalTest, CheckIncludingValue)
{
    Interval interval(1.0, 3.0);

    EXPECT_FALSE(interval.IsIncluded(0.0));

    EXPECT_TRUE(interval.IsIncluded(1.0));
    EXPECT_TRUE(interval.IsIncluded(2.0));
    EXPECT_TRUE(interval.IsIncluded(3.0));

    EXPECT_FALSE(interval.IsIncluded(4.0));

    Interval reverse_inteval(3.0, 1.0);

    EXPECT_FALSE(reverse_inteval.IsIncluded(0.0));

    EXPECT_TRUE(reverse_inteval.IsIncluded(1.0));
    EXPECT_TRUE(reverse_inteval.IsIncluded(2.0));
    EXPECT_TRUE(reverse_inteval.IsIncluded(3.0));

    EXPECT_FALSE(reverse_inteval.IsIncluded(4.0));
}

TEST(IntervalTest, OverrlapInterval)
{
    Interval interval_10to12(10.0, 12.0);

    Interval interval_8to9(8.0, 9.0);
    Interval interval_8to10(8.0, 10.0);
    Interval interval_8to11(8.0, 11.0);
    Interval interval_11to14(11.0, 14.0);
    Interval interval_12to14(12.0, 14.0);
    Interval interval_13to14(13.0, 14.0);

    EXPECT_TRUE(interval_10to12.IsOverlap(interval_8to9));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_8to10));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_8to11));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_11to14));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_12to14));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_13to14));
}
} // namespace