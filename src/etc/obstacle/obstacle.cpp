/// @file obstacle.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-10-30
///
/// @copyright Copyright (c) 2022
///

#include "src/etc/obstacle/obstacle.h"

#include <iostream>
#include <memory>
#include <utility>

#include "src/etc/obstacle/obstacle_data.h"

namespace design_pattern::etc::obstacle::entity
{
PointObstacle::PointObstacle(const data::PointObstacleData &point_obstacle_data) : data_(point_obstacle_data)
{
}

std::size_t PointObstacleRepository::Size() const
{
    return repo_.size();
}

void PointObstacleRepository::Create(const data::PointObstacleData &obstacle_data)
{
    auto ptr = std::make_shared<PointObstacle>(obstacle_data);
    repo_[obstacle_data.id_] = std::move(ptr);
}

bool PointObstacle::operator==(const data::PointObstacleData &point_obstacle_data) const
{
    bool same_id = point_obstacle_data.id_ == data_.id_;
    bool same_classification = point_obstacle_data.classification == data_.classification;
    bool same_moving_status = point_obstacle_data.moving_status == data_.moving_status;
    bool same_pos = point_obstacle_data.pos_ == data_.pos_;
    bool same_vel = point_obstacle_data.vel_ == data_.vel_;

    return (same_id && same_classification && same_moving_status && same_pos && same_vel);
}

} // namespace design_pattern::etc::obstacle::entity