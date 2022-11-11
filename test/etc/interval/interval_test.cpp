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

// TODO(leeh8911@gmail.com): Interval class calculate intersection other interval
// TODO(leeh8911@gmail.com): Interval class calculate set difference other interval
// TODO(leeh8911@gmail.com): Interval class equallity
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

    interval.Reverse();

    EXPECT_FALSE(interval.IsIncluded(0.0));

    EXPECT_TRUE(interval.IsIncluded(1.0));
    EXPECT_TRUE(interval.IsIncluded(2.0));
    EXPECT_TRUE(interval.IsIncluded(3.0));

    EXPECT_FALSE(interval.IsIncluded(4.0));
}

TEST(IntervalTest, OverlapInterval)
{
    Interval interval_10to12(10.0, 12.0);

    Interval interval_8to9(8.0, 9.0);
    Interval interval_8to10(8.0, 10.0);
    Interval interval_8to11(8.0, 11.0);
    Interval interval_11to14(11.0, 14.0);
    Interval interval_12to14(12.0, 14.0);
    Interval interval_13to14(13.0, 14.0);

    EXPECT_FALSE(interval_10to12.IsOverlap(interval_8to9));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_8to10));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_8to11));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_11to14));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_12to14));
    EXPECT_FALSE(interval_10to12.IsOverlap(interval_13to14));

    interval_10to12.Reverse();
    EXPECT_FALSE(interval_10to12.IsOverlap(interval_8to9.Reverse()));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_8to10.Reverse()));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_8to11.Reverse()));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_11to14.Reverse()));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_12to14.Reverse()));
    EXPECT_FALSE(interval_10to12.IsOverlap(interval_13to14.Reverse()));
}

TEST(IntervalTest, CalculateIntersection)
{
    Interval a{1.0, 3.0};
    Interval b{2.0, 4.0};

    EXPECT_EQ(a.Intersect(b), Interval{2.0, 3.0});
}
} // namespace
