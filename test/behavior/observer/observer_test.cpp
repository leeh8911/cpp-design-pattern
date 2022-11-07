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
TEST(ObserverTest, Should_FindObstacle_When_GivenSpecificId)
{
    ObstacleRepository repo;

    repo.GenerateObstacleById(42);
    EXPECT_EQ(repo.Size(), 1);

    EXPECT_TRUE(repo.Find(42) != nullptr);
    EXPECT_TRUE(repo.Find(23) == nullptr);
}

TEST(ObserverTest, Should_EraseAllObstacle_When_GivenSpecificId)
{
    ObstacleRepository repo;
    repo.GenerateObstacleById(42);
    repo.Erase(42);
    EXPECT_EQ(repo.Size(), 0);
}

TEST(ObserverTest, NotificationSubscriber)
{
    Subscriber subscriber1{};
    Subscriber subscriber2{};
    Subscriber subscriber3{};

    ObstacleRepository repo;

    repo.AddSubscriber(&subscriber1);
    repo.AddSubscriber(&subscriber2);
    repo.AddSubscriber(&subscriber3);

    repo.Notify();
    EXPECT_EQ(subscriber1.ObstacleCount(), 0);
    EXPECT_EQ(subscriber2.ObstacleCount(), 0);
    EXPECT_EQ(subscriber3.ObstacleCount(), 0);

    repo.GenerateObstacleById(1);
    repo.GenerateObstacleById(2);

    repo.Notify();
    EXPECT_EQ(subscriber1.ObstacleCount(), 2);
    EXPECT_EQ(subscriber2.ObstacleCount(), 2);
    EXPECT_EQ(subscriber3.ObstacleCount(), 2);
}

} // namespace
