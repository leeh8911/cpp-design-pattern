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

#include <stdexcept>
#include <vector>

#include "src/behavior/strategy/point.h"

using namespace design_pattern::behavior::strategy;  // NOLINT

namespace {
// TODO(sangwon): 군집화 알고리즘을 다양하게 사용하기 위해 전략 패턴을
// 적용해보자!
// TODO(sangwon): 테스트를 위한 포인트 생성기

std::ostream& operator<<(std::ostream& os, const std::vector<Point>& pv) {
    os << "[";
    for (auto& p : pv) {
        os << p << " ";
    }
    os << "]";
    return os;
}

std::vector<Point> MakePointsOnCircle(const Point& begin, const Point& end,
                                      std::size_t size) {
    if (size < 2) {
        throw std::invalid_argument("size must be greater equal to 2");
    }
    Point delta = (end - begin) / static_cast<double>(size - 1);

    std::vector<Point> result{};
    result.reserve(size);

    result.push_back(begin);

    for (std::size_t idx = 1; idx < size - 1; ++idx) {
        result.push_back(result.back() + delta);
    }
    result.push_back(end);

    return result;
}

// cppcheck-suppress syntaxError
TEST(PointGeneratorTest, GenerateTwoPointsCase) {
    Point begin(0.0, 0.0);
    Point end(1.0, 1.0);

    auto points = MakePointsOnCircle(begin, end, 2);
    EXPECT_EQ(points.front(), begin);
    EXPECT_EQ(points.back(), end);
}

TEST(PointGeneratorTest, GenerateWrongCase) {
    Point begin(0.0, 0.0);
    Point end(1.0, 1.0);

    EXPECT_THROW(MakePointsOnCircle(begin, end, 1), std::invalid_argument);
}

// TEST(StrategyExampleTest, SampleCase) {
//     Clusterer cluster;

//     std::vector<Point> MakePointsOnCircle({0.0, 0.0}, 1.0, 3.0);
// }

}  // namespace
