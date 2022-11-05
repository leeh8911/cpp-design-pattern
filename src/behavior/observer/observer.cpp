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

#include <unordered_set>
#include <utility>

namespace design_pattern::behavior::observer
{
auto Obstacle::allocated_id_set_ = std::unordered_set<std::size_t>{};

std::size_t Obstacle::GetEmptyId()
{
    std::size_t id_candidate = 1;

    while (Obstacle::allocated_id_set_.find(id_candidate) != Obstacle::allocated_id_set_.end())
    {
        id_candidate += 1;
    }

    return id_candidate;
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
} // namespace design_pattern::behavior::observer
