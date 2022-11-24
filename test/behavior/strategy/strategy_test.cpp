/// @file strategy_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-16
///
/// @copyright Copyright (c) 2022
///
//

#include "src/behavior/strategy/strategy.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <stdexcept>
#include <utility>
#include <vector>

#include "src/behavior/strategy/point.h"
#include "test/utils/point_util.h"

using namespace design_pattern::behavior::strategy;        // NOLINT
using namespace design_pattern::behavior::strategy::test;  // NOLINT

namespace {
// TODO(sangwon): 군집화 알고리즘을 다양하게 사용하기 위해 전략 패턴을
// 적용해보자!

TEST(StrategyExampleTest, NoClusteringCase) {
    Cluster cluster(0.0);
    std::vector<Point> X = MakePointsOnLineSegment(Point(1.0, -1.0), Point(1.0, 1.0), 10);

    bool success = cluster.Fit(X);

    EXPECT_TRUE(success);
    EXPECT_EQ(X.size(), cluster.LabelSize()) << cluster;
}

TEST(StrategyExampleTest, OneLabelCase) {
    Cluster cluster(1.0);
    std::vector<Point> X = MakePointsOnLineSegment(Point(1.0, -1.0), Point(1.0, 1.0), 10);

    bool success = cluster.Fit(X);

    EXPECT_TRUE(success);
    EXPECT_EQ(1, cluster.LabelSize());
}

TEST(StrategyExampleTest, TwoLabelCase) {
    Cluster cluster(1.0);
    std::vector<Point> X_1 = MakePointsOnLineSegment(Point(1.0, -1.0), Point(1.0, 1.0), 10);
    std::vector<Point> X_2 = MakePointsOnLineSegment(Point(1.0, 2.0), Point(1.0, 3.0), 10);

    std::vector<Point> X{};
    X.reserve(X_1.size() + X_2.size());

    std::copy(X_1.begin(), X_1.end(), std::back_inserter(X));
    std::copy(X_2.begin(), X_2.end(), std::back_inserter(X));

    bool success = cluster.Fit(X);

    EXPECT_TRUE(success);
    EXPECT_EQ(2, cluster.LabelSize());
}

}  // namespace
