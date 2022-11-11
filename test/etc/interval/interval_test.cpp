/// @file interval_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-11
///
/// @copyright Copyright (c) 2022
///
//

#include <gtest/gtest.h>

namespace
{

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
    EXPECT_EQ(interval.IsInclude(2.0));
}
} // namespace
