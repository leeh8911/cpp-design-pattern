/// @file observer.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-05
///
/// @copyright Copyright (c) 2022
///
//

#include "src/behavior/observer/observer.h"

#include <exception>
#include <iostream>
#include <unordered_set>
#include <utility>

namespace design_pattern::behavior::observer
{
auto Obstacle::allocated_id_set_ = std::unordered_set<std::size_t>{};

std::size_t Obstacle::GetEmptyId()
{
    std::size_t id_candidate = 1;

    while (Obstacle::IsContainedId(id_candidate))
    {
        id_candidate += 1;
    }

    return id_candidate;
}

bool Obstacle::IsContainedId(std::size_t id)
{
    return allocated_id_set_.find(id) != allocated_id_set_.end();
}

void Obstacle::AllocateId(std::size_t id)
{
    allocated_id_set_.emplace(id);
}

std::size_t Obstacle::Size()
{
    return allocated_id_set_.size();
}

Obstacle::~Obstacle()
{
    allocated_id_set_.erase(id_);
}
std::size_t Obstacle::Id()
{
    return id_;
}

Obstacle::Obstacle() : id_(GetEmptyId())
{
    AllocateId(id_);
}

Obstacle::Obstacle(std::size_t id)
{
    if (Obstacle::IsContainedId(id))
    {
        throw std::invalid_argument("This id is contained");
    }
    else
    {
        id_ = id;
        AllocateId(id_);
    }
}

ObstacleRepository::ObstacleRepository() = default;

std::size_t ObstacleRepository::Size()
{
    return repo_.size();
}

void ObstacleRepository::GenerateObstacle()
{
    Obstacle *obs = new Obstacle;
    repo_[obs->Id()] = obs;
}
} // namespace design_pattern::behavior::observer
