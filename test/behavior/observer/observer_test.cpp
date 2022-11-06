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
// TODO: 기능을 수행하는 객체가 리포지토리의 정보를 전달받는 것을 구현

namespace
{
using namespace design_pattern::behavior::observer;
// TODO: 특정 아이디 지정하는 생성자 추가
TEST(ObserverTest, ObstaclesHasDifferentIds)
{
    // 2개의 임의의 Obstacle을 생성하여 두 개의 ID가 같은지 확인
    Obstacle obs1, obs2;
    EXPECT_NE(obs1.Id(), obs2.Id());

    // 현재 생성된 Obstacle이 총 2개인지 확인
    // TODO: Obstacle의 개수 확인을 여기서 해야 하나?
    EXPECT_EQ(Obstacle::Size(), 2);

    // TODO: Obstacle Id의 중복을 여기서 처리하는게 맞나?
    Obstacle obs3(14);
    EXPECT_EQ(obs3.Id(), 14);

    EXPECT_ANY_THROW(Obstacle(14)); // NOLINT
}

// TODO: 데이터 객체를 Data Transfer Object로 출력하는 리포지토리
// TODO: 현재 저장된 Obstacle의 개수 출력
// TODO: 현재 존재하는 Obstacle Id를 출력
// TODO: 원하는 id의 Obstacle을 출력
// TODO: 특정 index의 Obstacle을 삭제
//
TEST(ObserverTest, ImplementRepository)
{
    ObstacleRepository repo;

    repo.GenerateObstacleById(42);
    repo.GenerateObstacleById(23);
    EXPECT_EQ(repo.Size(), 2);

    auto id_set = repo.GetUsedId();

    EXPECT_TRUE(id_set.find(42) != id_set.end());
    EXPECT_TRUE(id_set.find(23) != id_set.end());
    EXPECT_TRUE(id_set.find(74) == id_set.end());
}

} // namespace
