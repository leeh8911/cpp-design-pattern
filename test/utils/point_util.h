/// @file point_util.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-24
///
/// @copyright Copyright (c) 2022
///
//

#include <iostream>
#include <vector>

#include "src/behavior/strategy/point.h"

namespace design_pattern::behavior::strategy::test {

std::ostream& operator<<(std::ostream& os, const std::vector<Point>& pv);

std::vector<Point> MakePointsOnCircle(const Point& begin, const Point& end,
                                      std::size_t size);

}  // namespace design_pattern::behavior::strategy::test
