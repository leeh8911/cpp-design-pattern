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

namespace design_pattern::behavior::state
{
std::string Red::StateName()
{
    return "Red Light";
}

Color *Red::Next()
{
    return new Green;
}

std::string Green::StateName()
{
    return "Green Light";
}

Color *Green::Next()
{
    return new Yellow;
}

std::string Yellow::StateName()
{
    return "Yellow Light";
}

Color *Yellow::Next()
{
    return new Red;
}

TrafficLight::TrafficLight() : state_(new Red)
{
}

TrafficLight::TrafficLight(Color *state) : state_(state)
{
}

std::string TrafficLight::CurrentState()
{
    return state_->StateName();
}

void TrafficLight::Update()
{
    state_ = state_->Next();
}

} // namespace design_pattern::behavior::state
