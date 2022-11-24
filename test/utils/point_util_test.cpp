/// @file point_util_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-24
///
/// @copyright Copyright (c) 2022
///
//

#include "test/utils/point_util.h"

#include <gtest/gtest.h>

#include "src/behavior/strategy/point.h"

using namespace design_pattern::behavior::strategy::test;  // NOLINT
using namespace design_pattern::behavior::strategy;        // NOLINT

namespace {
// cppcheck-suppress syntaxError
TEST(PointGeneratorTest, GenerateTwoPointsCase) {
    Point begin(0.0, 0.0);
    Point end(1.0, 1.0);

    auto points = MakePointsOnLineSegment(begin, end, 2);
    EXPECT_EQ(points.front(), begin);
    EXPECT_EQ(points.back(), end);
}

// cppcheck-suppress syntaxError
TEST(PointGeneratorTest, GenerateWrongCase) {
    Point begin(0.0, 0.0);
    Point end(1.0, 1.0);

    EXPECT_THROW(MakePointsOnLineSegment(begin, end, 1), std::invalid_argument);
}

TEST(PointGeneratorTest, GenerateTenPointsCase) {
    Point begin(0.0, 0.0);
    Point end(1.0, 1.0);

    auto points = MakePointsOnLineSegment(begin, end, 10);

    EXPECT_EQ(10, points.size());
    EXPECT_EQ(begin, points.front());
    EXPECT_EQ(end, points.back());

    EXPECT_EQ(Point(0.1, 0.1), points.at(1));
}
}  // namespace
