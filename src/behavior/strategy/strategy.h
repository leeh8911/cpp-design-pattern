/// @file strategy.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-16
///
/// @copyright Copyright (c) 2022
///
//
#ifndef SRC_BEHAVIOR_STRATEGY_STRATEGY_H_
#define SRC_BEHAVIOR_STRATEGY_STRATEGY_H_

#include <unordered_set>
#include <vector>

#include "src/behavior/strategy/point.h"

namespace design_pattern::behavior::strategy {
class Cluster {
 public:
    Cluster() = default;
    explicit Cluster(double distance_threshold);

    bool Fit(const std::vector<Point>& data);

    std::size_t LabelSize() const;
    std::vector<std::size_t> Label() const;

    friend std::ostream& operator<<(std::ostream& os, const Cluster& cluster);

 private:
    double distance_threshold_{};
    std::vector<Point> data_{};
    std::vector<std::size_t> label{};
    std::unordered_set<std::size_t> label_set{};
};

std::ostream& operator<<(std::ostream& os, const Cluster& cluster);
}  // namespace design_pattern::behavior::strategy
#endif  // SRC_BEHAVIOR_STRATEGY_STRATEGY_H_
