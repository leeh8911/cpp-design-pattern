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

using namespace design_pattern::behavior::strategy;  // NOLINT

namespace {
// TODO(sangwon): 주어진 돈과 시간 제약을 고려한 운송 수단 선택을 도와주는
// 기능을 만들자
// DONE(sangwon): 자동차를 타고 특정 거리만 큼 이동했을 때 걸리는 시간과 돈을
// 추정하자
// TODO(sangwon): 다양한 탈 것들을 적용하기 위한 추상화.
// TODO(sangwon): 자전거를 타고 갔을 때를 추가한다.
// TEST(StrategyTest, WhenUsingCarEstimateTimeAndMoney) {
//     auto car = std::make_unique<Car>();
//     car->Distance(1);  // Move 1 km

//     EXPECT_EQ(car->EstimateTime(), 0.25);  // 1/4 hour
//     EXPECT_EQ(car->EstimateMoney(), 1);    // 1 dollar
// }

}  // namespace
