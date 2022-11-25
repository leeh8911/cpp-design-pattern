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

#include <memory>
#include <unordered_set>
#include <utility>
#include <vector>

#include "src/behavior/strategy/cluster_impl.h"
#include "src/behavior/strategy/point.h"

namespace design_pattern::behavior::strategy {
Cluster::Cluster(IClusterPtr pimpl_) : pimpl(std::move(pimpl_)) {}

bool Cluster::Fit(const std::vector<Point>& data) {
    data_ = data;

    label = pimpl->Fit(data);

    label_set = std::unordered_set<std::size_t>(label.begin(), label.end());

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
