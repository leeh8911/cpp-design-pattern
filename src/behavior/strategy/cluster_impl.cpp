/// @file cluster_impl.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-24
///
/// @copyright Copyright (c) 2022
///
//

#include "src/behavior/strategy/cluster_impl.h"

namespace design_pattern::behavior::strategy {
BasicCluster::BasicCluster(double distance_threshold) : distance_threshold_{distance_threshold} {}

std::vector<std::size_t> BasicCluster::Fit(const std::vector<Point>& data) {
    auto curr = data.begin();
    auto next = std::next(curr);

    std::vector<std::size_t> label{};

    label.emplace_back(1);

    while (next != data.end()) {
        double distance = Point::Distance(*curr, *next);

        if (distance < distance_threshold_) {
            label.emplace_back(label.back());
        } else {
            label.emplace_back(label.back() + 1);
        }

        curr = next;
        next = std::next(next);
    }
    return label;
}

}  // namespace design_pattern::behavior::strategy
