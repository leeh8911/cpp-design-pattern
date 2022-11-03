/**
 * @file input.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "src/etc/mvc_pattern/application/input.h"

#include <vector>

namespace design_pattern::etc::mvc::app
{
void Input::Update(const std::vector<Sensor> &sensor_vector)
{
    container_ = sensor_vector;
}

const Sensor &Input::GetItem(size_t idx) const
{
    return container_[idx];
}

size_t Input::Size() const
{
    return container_.size();
}
} // namespace design_pattern::etc::mvc::app