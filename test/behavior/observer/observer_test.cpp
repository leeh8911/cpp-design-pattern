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

namespace {
using namespace design_pattern::behavior::observer;
TEST(ObserverTest, Should_FindObstacle_When_GivenSpecificId) {
    ObstacleRepository repo;

    repo.GenerateObstacleById(42);
    EXPECT_EQ(repo.Size(), 1);

    EXPECT_TRUE(repo.Find(42) != nullptr);
    EXPECT_TRUE(repo.Find(23) == nullptr);
}

TEST(ObserverTest, Should_EraseAllObstacle_When_GivenSpecificId) {
    ObstacleRepository repo;
    repo.GenerateObstacleById(42);
    repo.Erase(42);
    EXPECT_EQ(repo.Size(), 0);
}

TEST(ObserverTest, Should_MultipleSubscriber) {
    std::array<std::size_t, 3> given_ids{1, 2, 3};

    auto counter = std::make_shared<ObstacleCounter>();
    auto id_checker = std::make_shared<ObstacleIdChecker>();

    ObstacleRepository repo;

    repo.AddSubscriber(counter);
    repo.AddSubscriber(id_checker);

    repo.Notify();
    EXPECT_EQ((*counter)(), 0);
    EXPECT_EQ((*id_checker)().size(), 0);

    for (auto id : given_ids) {
        repo.GenerateObstacleById(id);
    }

    repo.Notify();
    EXPECT_EQ((*counter)(), given_ids.size());
    EXPECT_EQ((*id_checker)().size(), given_ids.size());

    std::unordered_set<std::size_t> id_set(given_ids.begin(), given_ids.end());
    for (auto id : (*id_checker)()) {
        auto found = id_set.find(id);
        EXPECT_TRUE(found != id_set.end());
    }
}

}  // namespace
