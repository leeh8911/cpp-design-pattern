/// @file observer_test.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-06
///
/// @copyright Copyright (c) 2022
///

#include "src/behavior/observer/observer.h"

#include <gtest/gtest.h>

// Observer pattern implementation todo list
// TODO: 리포지토리가 업데이트 되었을 때 다른 기능들이 해당 정보를 확인할 수 있도록
// TODO: 데이터 객체를 Data Transfer Object로 출력하는 리포지토리
// TODO: 기능을 수행하는 객체가 리포지토리의 정보를 전달받는 것을 구현

namespace
{
using namespace design_pattern::behavior::observer;
TEST(ObserverTest, ImplementValueObject)
{
    Obstacle obs1, obs2;
    EXPECT_NE(obs1.Id(), obs2.Id());

    EXPECT_EQ(Obstacle::Size(), 2);
}

} // namespace
