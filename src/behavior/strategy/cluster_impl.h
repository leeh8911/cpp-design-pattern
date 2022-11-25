/// @file cluster_impl.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-24
///
/// @copyright Copyright (c) 2022
///
//

#ifndef SRC_BEHAVIOR_STRATEGY_CLUSTER_IMPL_H_
#define SRC_BEHAVIOR_STRATEGY_CLUSTER_IMPL_H_

#include <unordered_set>
#include <vector>

#include "src/behavior/strategy/point.h"

namespace design_pattern::behavior::strategy {

class IClusterImpl {
 public:
    virtual ~IClusterImpl() = default;

    virtual std::vector<std::size_t> Fit(const std::vector<Point>& data) = 0;
};

class BasicCluster : public IClusterImpl {
 public:
    explicit BasicCluster(double distance_threshold);

    std::vector<std::size_t> Fit(const std::vector<Point>& data) override;

 private:
    double distance_threshold_{};
};

}  // namespace design_pattern::behavior::strategy
#endif  // SRC_BEHAVIOR_STRATEGY_CLUSTER_IMPL_H_
