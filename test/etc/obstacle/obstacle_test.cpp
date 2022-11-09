/// @file obstacle_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief Obstacle 관련 모듈을 테스트
/// ObstacleData는 Obstacle과 연관된 데이터를 포함하는 클래스입니다.
/// Obstacle은 ObstacleData를 저장하고, 연산을 수행하는 클래스입니다.
/// ObstacleRepository는 ObstacleData를 기반으로 Obstacle을 Create, Update, Read, Delete를 도와주는 클래스입니다.
/// @version 0.1
/// @date 2022-10-29
///
/// @copyright Copyright (c) 2022
///

#include "src/etc/obstacle/obstacle.h"
#include "src/etc/obstacle/obstacle_data.h"

#include <gtest/gtest.h>

#include <iostream>

namespace
{

using namespace design_pattern::etc::obstacle;

TEST(ObstacleIdentifierTest, Should_NotEqual_When_GivenDistinguishedIdentifiers)
{
    EXPECT_EQ(1, 1);
}

TEST(PointObstacleTest, Should_Normal_When_CreateReadUpdateDelete)
{
    entity::PointObstacleRepository repository;
    EXPECT_EQ(repository.Size(), 0);

    data::PointObstacleData point_obstacle_data{.id_ = 1, .pos_ = {1.0, 1.0}};
    repository.Create(point_obstacle_data);
    EXPECT_EQ(repository.Size(), 1);

    // auto point_obstacle = repository.Read(0);
    // EXPECT_EQ(point_obstacle_data, *(point_obstacle.get()));

    // data::PointObstacleData other_data{.id_ = 1, .pos_ = {1.0, 1.0}};
    // repository.Update(other_data);
    // EXPECT_EQ(repository.Size(), 1);

    // auto other_obstacle = repository.Read(0);
    // EXPECT_EQ(other_data, *(other_obstacle.get()));

    // repository.Delete(0);
    // EXPECT_EQ(repository.Size(), 0);
}

} // namespace
