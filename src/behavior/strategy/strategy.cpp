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

namespace design_pattern::behavior::strategy {
void Vehicle::Distance(double distance) { distance_ = distance; }

double Vehicle::Distance() const { return distance_; }

double Vehicle::EstimateMoney() { return distance_ * money_distance_ratio; }

double Vehicle::EstimateTime() { return distance_ * time_distance_ratio; }

double Car::EstimateMoney() { return Distance() * money_distance_ratio; }

double Car::EstimateTime() { return Distance() * time_distance_ratio; }

}  // namespace design_pattern::behavior::strategy
