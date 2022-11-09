/// @file obstacle_data.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-09
///
/// @copyright Copyright (c) 2022
///
//

#include "src/etc/obstacle/obstacle_data.h"

namespace design_pattern::etc::obstacle::data
{
bool operator==(const Vector2D &lhs, const Vector2D &rhs)
{
    return ((lhs[0] == rhs[0]) && (lhs[1] == rhs[1]));
}

std::ostream &operator<<(std::ostream &os, const PointObstacleData &obstacle_data)
{
    os << "Id(" << obstacle_data.id_ << ")";
    return os;
}
} // namespace design_pattern::etc::obstacle::data
