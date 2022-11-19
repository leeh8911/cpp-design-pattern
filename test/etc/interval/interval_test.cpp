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

#include <cmath>

#include "src/etc/interval/continuous_set.h"

namespace {
using namespace design_pattern::etc::interval;  // NOLINT

// TODO(leeh8911@gmail.com): NumberInterval's reversible is not useful (I think
// from_ always smaller than to_)
// TODO(leeh8911@gmail.com): NumberInterval class calculate set difference other
// interval
// TODO(leeh8911@gmail.com): Circular NumberInterval class from, to values are
// circular value

// cppcheck-suppress syntaxError
TEST(IntervalTest, CheckIncludingValue) {
    NumberInterval interval(1.0, 3.0);

    EXPECT_FALSE(interval.IsIncluded(0.0));

    EXPECT_TRUE(interval.IsIncluded(1.0));
    EXPECT_TRUE(interval.IsIncluded(2.0));
    EXPECT_TRUE(interval.IsIncluded(3.0));

    EXPECT_FALSE(interval.IsIncluded(4.0));
}

TEST(IntervalTest, OverlapInterval) {
    NumberInterval interval_10to12(10.0, 12.0);

    NumberInterval interval_8to9(8.0, 9.0);
    NumberInterval interval_8to10(8.0, 10.0);
    NumberInterval interval_8to11(8.0, 11.0);
    NumberInterval interval_11to14(11.0, 14.0);
    NumberInterval interval_12to14(12.0, 14.0);
    NumberInterval interval_13to14(13.0, 14.0);

    EXPECT_FALSE(interval_10to12.IsOverlap(interval_8to9));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_8to10));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_8to11));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_11to14));
    EXPECT_TRUE(interval_10to12.IsOverlap(interval_12to14));
    EXPECT_FALSE(interval_10to12.IsOverlap(interval_13to14));
}

TEST(IntervalTest, CalculateIntersection) {
    NumberInterval origin{1.0, 3.0};
    auto overlap_case_1 = std::make_unique<NumberInterval>(2.0, 4.0);
    auto overlap_case_11 = std::make_unique<NumberInterval>(2.0, 4.0);
    auto overlap_case_2 = std::make_unique<NumberInterval>(0.0, 2.0);
    auto overlap_case_3 = std::make_unique<NumberInterval>(0.0, 1.0);
    auto overlap_case_4 = std::make_unique<NumberInterval>(3.0, 4.0);
    auto overlap_case_5 = std::make_unique<NumberInterval>(1.1, 2.9);
    auto non_overlap_case_1 = std::make_unique<NumberInterval>(4.0, 5.0);
    auto non_overlap_case_2 = std::make_unique<NumberInterval>(0.0, 0.5);

    EXPECT_EQ(*origin.Intersect(std::move(overlap_case_1)),
              (NumberInterval{2.0, 3.0}));
    EXPECT_NE(*origin.Intersect(std::move(overlap_case_11)),
              (NumberInterval{1.0, 4.0}));
    EXPECT_EQ(*origin.Intersect(std::move(overlap_case_2)),
              (NumberInterval{1.0, 2.0}));
    EXPECT_EQ(*origin.Intersect(std::move(overlap_case_3)),
              (NumberInterval{1.0, 1.0}));
    EXPECT_EQ(*origin.Intersect(std::move(overlap_case_4)),
              (NumberInterval{3.0, 3.0}));

    EXPECT_EQ(*origin.Intersect(std::move(overlap_case_5)),
              (NumberInterval{1.1, 2.9}));

    EXPECT_TRUE(origin.Intersect(std::move(non_overlap_case_1))->IsEmpty());
    EXPECT_TRUE(origin.Intersect(std::move(non_overlap_case_2))->IsEmpty());
}
}  // namespace
