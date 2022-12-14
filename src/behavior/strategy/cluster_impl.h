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

#include <deque>
#include <limits>
#include <memory>
#include <unordered_set>
#include <vector>

#include "src/behavior/strategy/cluster_param.h"
#include "src/behavior/strategy/point.h"

namespace design_pattern::behavior::strategy {

class IClusterImpl {
 public:
    virtual ~IClusterImpl() = default;

    virtual std::vector<std::size_t> Fit(const std::vector<Point>& data) = 0;
};
using IClusterPtr = std::unique_ptr<IClusterImpl>;

class BasicCluster : public IClusterImpl {
 public:
    explicit BasicCluster(double distance_threshold);
    explicit BasicCluster(const IClusterParam& param);

    std::vector<std::size_t> Fit(const std::vector<Point>& data) override;

 private:
    double distance_threshold_{};
};

class DBSCAN : public IClusterImpl {
 public:
    explicit DBSCAN(double eps, std::size_t min_samples);
    explicit DBSCAN(const IClusterParam& param);

    std::vector<std::size_t> Fit(const std::vector<Point>& data) override;

 private:
    static constexpr std::size_t kUnDefined = 0;
    static constexpr std::size_t kNoise = std::numeric_limits<std::size_t>::max();

    double eps_{};
    std::size_t min_samples_{};

    std::deque<std::size_t> QueryInBoundSamples(const std::vector<Point>& data, double eps, const Point& p);
};

}  // namespace design_pattern::behavior::strategy
#endif  // SRC_BEHAVIOR_STRATEGY_CLUSTER_IMPL_H_
