/// @file cluster_param.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-25
///
/// @copyright Copyright (c) 2022
///
//

#include "src/behavior/strategy/cluster_param.h"

namespace design_pattern::behavior::strategy {

void IClusterParam::DistanceThreshold(double distance_threshold) { distance_threshold_ = distance_threshold; }
double IClusterParam::DistanceThreshold() const { return distance_threshold_; }
void IClusterParam::MinSamples(std::size_t min_samples) { min_samples_ = min_samples; }
std::size_t IClusterParam::MinSamples() const { return min_samples_; }

void BasicClusterParam::DistanceThreshold(double distance_threshold) {
    IClusterParam::DistanceThreshold(distance_threshold);
}
double BasicClusterParam::DistanceThreshold() const { return IClusterParam::DistanceThreshold(); }
// void BasicClusterParam::MinSamples(std::size_t min_samples) { IClusterParam::MinSamples(min_samples); }
// std::size_t BasicClusterParam::MinSamples() const { return IClusterParam::MinSamples(); }

void DBSCANParam::DistanceThreshold(double distance_threshold) { IClusterParam::DistanceThreshold(distance_threshold); }
double DBSCANParam::DistanceThreshold() const { return IClusterParam::DistanceThreshold(); }
void DBSCANParam::MinSamples(std::size_t min_samples) { IClusterParam::MinSamples(min_samples); }
std::size_t DBSCANParam::MinSamples() const { return IClusterParam::MinSamples(); }

}  // namespace design_pattern::behavior::strategy
