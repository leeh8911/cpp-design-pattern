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

// TODO(leeh8911@gmail.com): Interval class has from and to value
// TODO(leeh8911@gmail.com): Interval class check included value
// TODO(leeh8911@gmail.com): Interval class check overlap other interval
// TODO(leeh8911@gmail.com): Interval class calculate intersection other interval
// TODO(leeh8911@gmail.com): Interval class calculate set difference other interval
//
// TODO(leeh8911@gmail.com): Circular Interval class from, to values are circular value

TEST(IntervalTest, ConstructInterval)
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
} // namespace
