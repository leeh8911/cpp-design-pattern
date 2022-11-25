/// @file cluster_param.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-25
///
/// @copyright Copyright (c) 2022
///
//

#include <string>

#ifndef SRC_BEHAVIOR_STRATEGY_CLUSTER_PARAM_H_
#define SRC_BEHAVIOR_STRATEGY_CLUSTER_PARAM_H_
namespace design_pattern::behavior::strategy {
class IClusterParam {
 public:
    virtual ~IClusterParam() = default;
    virtual void DistanceThreshold(double distance_threshold);
    virtual double DistanceThreshold() const;

    virtual void MinSamples(std::size_t min_samples);
    virtual std::size_t MinSamples() const;

 private:
    double distance_threshold_{};
    std::size_t min_samples_{};
};

class BasicClusterParam : public IClusterParam {
 public:
    void DistanceThreshold(double distance_threshold) override;
    double DistanceThreshold() const override;

 private:
    using IClusterParam::MinSamples;
};

class DBSCANParam : public IClusterParam {
 public:
    void DistanceThreshold(double distance_threshold) override;
    double DistanceThreshold() const override;

    void MinSamples(std::size_t min_samples) override;
    std::size_t MinSamples() const override;
};
}  // namespace design_pattern::behavior::strategy
#endif  // SRC_BEHAVIOR_STRATEGY_CLUSTER_PARAM_H_
