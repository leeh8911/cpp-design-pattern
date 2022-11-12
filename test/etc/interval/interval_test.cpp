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

// TODO(leeh8911@gmail.com): Interval's reversable is not useful (I think from_ always smaller than to_)
// TODO(leeh8911@gmail.com): Interval class calculate set difference other interval
//
// TODO(leeh8911@gmail.com): Circular Interval class from, to values are circular value

// I don't know why?
// cppcheck-suppress syntaxError
TEST(IntervalTest, CheckIncludingValue)
{
    Interval interval(1.0, 3.0);

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
}

TEST(IntervalTest, CalculateIntersection)
{
    Interval origin{1.0, 3.0};
    Interval overlap_case_1{2.0, 4.0};
    Interval overlap_case_2{0.0, 2.0};
    Interval overlap_case_3{0.0, 1.0};
    Interval overlap_case_4{3.0, 4.0};
    Interval overlap_case_5{1.1, 2.9};
    Interval non_overlap_case_1{4.0, 5.0};
    Interval non_overlap_case_2{0.0, 0.5};

    auto result1 = origin.Intersect(overlap_case_1);
    EXPECT_EQ(result1, (Interval{2.0, 3.0}));
    EXPECT_NE(result1, (Interval{1.0, 4.0}));

    auto result2 = origin.Intersect(overlap_case_2);
    EXPECT_EQ(result2, (Interval{1.0, 2.0}));

    auto result3 = origin.Intersect(overlap_case_3);
    EXPECT_EQ(result3, (Interval{1.0, 1.0}));

    auto result4 = origin.Intersect(overlap_case_4);
    EXPECT_EQ(result4, (Interval{3.0, 3.0}));

    auto result5 = origin.Intersect(overlap_case_5);
    EXPECT_EQ(result5, (Interval{1.1, 2.9}));

    auto result6 = origin.Intersect(non_overlap_case_1);
    EXPECT_EQ(result6, (Interval{0.0, 0.0}));

    auto result7 = origin.Intersect(non_overlap_case_2);
    EXPECT_EQ(result7, (Interval{0.0, 0.0}));
}

TEST(IntervalTest, CompositeIntervalCreate)
{

    CompositeInterval comp_interval{};

    comp_interval.AddInterval(std::make_unique<Interval>(1.0, 3.0));
    comp_interval.AddInterval(std::make_unique<Interval>(6.0, 8.0));

    EXPECT_TRUE(comp_interval.IsIncluded(2.0));
    EXPECT_TRUE(comp_interval.IsIncluded(7.0));
}

TEST(IntervalTest, CompositeIntervalOverlap)
{
    CompositeInterval comp_interval{};

    comp_interval.AddInterval(std::make_unique<Interval>(1.0, 3.0));
    comp_interval.AddInterval(std::make_unique<Interval>(6.0, 8.0));

    Interval interval_0to2{0.0, 2.0};
    Interval interval_2to4{2.0, 4.0};
    Interval interval_2to7{2.0, 7.0};
    Interval interval_5to7{5.0, 7.0};
    Interval interval_7to9{7.0, 9.0};

    EXPECT_TRUE(comp_interval.IsOverlap(interval_0to2));
    EXPECT_TRUE(comp_interval.IsOverlap(interval_2to4));
    EXPECT_TRUE(comp_interval.IsOverlap(interval_2to7));
    EXPECT_TRUE(comp_interval.IsOverlap(interval_5to7));
    EXPECT_TRUE(comp_interval.IsOverlap(interval_7to9));
}
} // namespace
