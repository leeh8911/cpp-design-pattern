/// @file state.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-08
///
/// @copyright Copyright (c) 2022
///
//

#include "src/behavior/state/state.h"

#include <memory>
#include <string>
#include <utility>

namespace design_pattern::behavior::state {
std::string Red::StateName() { return "Red Light"; }

ColorPtr Red::Next() { return std::make_unique<Green>(); }

std::string Green::StateName() { return "Green Light"; }

ColorPtr Green::Next() { return std::make_unique<Yellow>(); }

std::string Yellow::StateName() { return "Yellow Light"; }

ColorPtr Yellow::Next() { return std::make_unique<Red>(); }

TrafficLight::TrafficLight() : state_(std::make_unique<Red>()) {}

TrafficLight::TrafficLight(ColorPtr state) : state_(std::move(state)) {}

std::string TrafficLight::CurrentState() { return state_->StateName(); }

void TrafficLight::Update() {
    auto next_state = state_->Next();
    std::swap(next_state, state_);
}

}  // namespace design_pattern::behavior::state
