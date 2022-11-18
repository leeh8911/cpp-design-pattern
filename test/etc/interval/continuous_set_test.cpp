/// @file continuous_set_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-18
///
/// @copyright Copyright (c) 2022
///

#include "src/etc/interval/continuous_set.h"

#include <gtest/gtest.h>

#include "src/etc/interval/interval.h"

namespace {
using namespace design_pattern::etc::interval;

// cppcheck-suppress syntaxError
TEST(ContinuousSetTest, ContinuousSetUnion) {
    Interval interval(1.0, 3.0);
    ContinuousSet continuous_set{};

    continuous_set.Union(Interval{1.0, 3.0});
    EXPECT_EQ(continuous_set, (Interval{1.0, 3.0}));

    continuous_set.Union(Interval{3.0, 5.0});
    EXPECT_EQ(continuous_set, (Interval{1.0, 5.0}));

    continuous_set.Union(Interval{7.0, 8.0});
    EXPECT_EQ(continuous_set.Size(), 2);

    continuous_set.Union(Interval{5.0, 7.0});
    EXPECT_EQ(continuous_set.Size(), 1);
    EXPECT_EQ(continuous_set, (Interval{1.0, 8.0}));
}

TEST(ContinuousSetTest, ContinuousSetIntersection) {
    Interval interval(1.0, 3.0);
    ContinuousSet continuous_set{};

    continuous_set.Union(Interval{1.0, 3.0});
    continuous_set.Intersect(Interval{1.0, 3.0});
    EXPECT_EQ(continuous_set, (Interval{1.0, 3.0}));
}

}  // namespace
