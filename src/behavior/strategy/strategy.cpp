/// @file strategy.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-16
///
/// @copyright Copyright (c) 2022
///
//

#include "src/behavior/strategy/strategy.h"

#include <vector>

#include "src/behavior/strategy/point.h"

namespace design_pattern::behavior::strategy {
Cluster::Cluster(double distance_threshold) : distance_threshold_{distance_threshold} {}

bool Cluster::Fit(const std::vector<Point>& data) {
    data_ = data;

    auto curr = data.begin();
    auto next = std::next(curr);

    label.emplace_back(1);
    label_set.emplace(label.back());

    while (next != data.end()) {
        double distance = Point::Distance(*curr, *next);

        if (distance < distance_threshold_) {
            label.emplace_back(label.back());
        } else {
            label.emplace_back(label.back() + 1);
            label_set.emplace(label.back());
        }

        curr = next;
        next = std::next(next);
    }
    return true;
}

std::size_t Cluster::LabelSize() const { return label_set.size(); }

std::vector<std::size_t> Cluster::Label() const { return label; }

std::ostream& operator<<(std::ostream& os, const Cluster& cluster) {
    os << "Distance Threshold: " << cluster.distance_threshold_ << "\n";
    os << "Label Size: " << cluster.label_set.size() << "\n";

    auto p_it = cluster.data_.begin();
    auto l_it = cluster.label.begin();
    for (; p_it != cluster.data_.end(); ++p_it, ++l_it) {
        os << "Point: " << *p_it << " - Label: " << *l_it << "\n";
    }
    return os;
}
}  // namespace design_pattern::behavior::strategy
