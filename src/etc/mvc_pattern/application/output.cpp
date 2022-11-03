/**
 * @file output.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "src/etc/mvc_pattern/application/output.h"

#include <vector>

namespace design_pattern::etc::mvc::app
{
size_t Output::Size() const
{
    return container_.size();
}

Target Output::GetItem(size_t idx) const
{
    return container_[idx];
}

void Output::Update(const std::vector<Target> &target_vector)
{
    container_ = target_vector;
}
} // namespace design_pattern::etc::mvc::app