/// @file point_util.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-24
///
/// @copyright Copyright (c) 2022
///
//

#include "test/utils/point_util.h"

#include <iostream>
#include <vector>

#include "src/behavior/strategy/point.h"

namespace design_pattern::behavior::strategy::test {

std::ostream& operator<<(std::ostream& os, const std::vector<Point>& pv) {
    os << "[";
    for (auto& p : pv) {
        os << p << " ";
    }
    os << "]";
    return os;
}

std::vector<Point> MakePointsOnLineSegment(const Point& begin, const Point& end,
                                           std::size_t size) {
    if (size < 2) {
        throw std::invalid_argument("size must be greater equal to 2");
    }
    Point delta = (end - begin) / static_cast<double>(size);

    std::vector<Point> result{};
    result.reserve(size);

    result.push_back(begin);

    for (std::size_t idx = 1; idx < size - 1; ++idx) {
        result.push_back(result.back() + delta);
    }
    result.push_back(end);

    return result;
}
}  // namespace design_pattern::behavior::strategy::test
