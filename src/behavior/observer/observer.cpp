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
Obstacle::Obstacle(std::size_t id) : id_(id)
{
}
std::size_t Obstacle::Id()
{
    return id_;
}

ObstacleRepository::ObstacleRepository() = default;

std::size_t ObstacleRepository::Size()
{
    return repo_.size();
}

void ObstacleRepository::GenerateObstacle()
{
    auto obs = std::make_unique<Obstacle>(GetEmptyId());
    repo_[obs->Id()] = std::move(obs);
}

void ObstacleRepository::GenerateObstacleById(std::size_t id)
{
    auto obs = std::make_unique<Obstacle>(id);
    repo_[obs->Id()] = std::move(obs);
}

std::unordered_set<std::size_t> ObstacleRepository::GetUsedId() const
{
    std::unordered_set<std::size_t> result{};
    for (const auto &elm : repo_)
    {
        result.emplace(elm.first);
    }
    return result;
}

void ObstacleRepository::Erase(std::size_t id)
{
    auto found = repo_.find(id);
    if (found == repo_.end())
    {
        std::string err_msg = "id: " + std::to_string(id) + "cannot find";
        throw std::invalid_argument(err_msg);
    }

    ObstaclePtr null_obstacle = nullptr;
    std::swap(found->second, null_obstacle);
    repo_.erase(found);
}

const ObstaclePtr ObstacleRepository::Find(std::size_t id)
{
    auto found = repo_.find(id);
    if (found == repo_.end())
    {
        return nullptr;
    }

    ObstaclePtr result = nullptr;
    std::swap(found->second, result);
    repo_.erase(found);

    return result;
}

std::size_t ObstacleRepository::GetEmptyId() const
{
    std::size_t candidate = 1;
    while (repo_.find(candidate) != repo_.end())
    {
        candidate += 1;
    }

    return candidate;
}
} // namespace design_pattern::behavior::observer
