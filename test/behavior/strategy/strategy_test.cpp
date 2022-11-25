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
#include <deque>
#include <map>
#include <stdexcept>
#include <utility>
#include <vector>

#include "behavior/strategy/cluster_impl.h"
#include "src/behavior/strategy/point.h"
#include "test/utils/point_util.h"

using namespace design_pattern::behavior::strategy;        // NOLINT
using namespace design_pattern::behavior::strategy::test;  // NOLINT

namespace {
// TODO(sangwon): 군집화 알고리즘을 다양하게 사용하기 위해 전략 패턴을
// 적용해보자!

class StrategyExampleTest : public testing::Test {
 public:
    void SetUp() override {
        std::vector<Point> X_1 = MakePointsOnLineSegment(Point(1.0, -1.0), Point(1.0, 1.0), 10);
        std::vector<Point> X_2 = MakePointsOnLineSegment(Point(1.0, 2.0), Point(1.0, 3.0), 10);

        std::vector<Point> X{};
        X.reserve(X_1.size() + X_2.size());

        std::copy(X_1.begin(), X_1.end(), std::back_inserter(X));
        std::copy(X_2.begin(), X_2.end(), std::back_inserter(X));
    }
    void TearDown() override {}

    std::vector<Point> X;
};

TEST_F(StrategyExampleTest, TwoLabelCase) {
    Cluster cluster(std::make_unique<BasicCluster>(1.0));

    bool success = cluster.Fit(X);

    EXPECT_TRUE(success);
    EXPECT_EQ(2, cluster.LabelSize());
}

TEST_F(StrategyExampleTest, DBSCANTwoLabelCase) {
    Cluster cluster(std::make_unique<DBSCAN>(1.0, 5));

    bool success = cluster.Fit(X);

    EXPECT_TRUE(success);
    EXPECT_EQ(2, cluster.LabelSize()) << cluster;
}

}  // namespace
