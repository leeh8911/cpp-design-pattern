/// @file state_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-08
///
/// @copyright Copyright (c) 2022
///
//

#include <gtest/gtest.h>

#include "src/behavior/state/state.h"

namespace
{

using namespace design_pattern::behavior::state;

TEST(StateTest, Should_PrintColor_When_GivenOrNotInitialStateColor)
{
    TrafficLight traffic_light{};

    EXPECT_EQ(traffic_light.CurrentState(), "Red Light");

    TrafficLight red_state_light(new Red);
    TrafficLight green_state_light(new Green);
    TrafficLight yellow_state_light(new Yellow);

    EXPECT_EQ(red_state_light.CurrentState(), "Red Light");
    EXPECT_EQ(green_state_light.CurrentState(), "Green Light");
    EXPECT_EQ(yellow_state_light.CurrentState(), "Yellow Light");
}

TEST(StateTest, Should_PrintColor_When_StartingRedStateAndUpdatingTrafficLight)
{
    TrafficLight traffic_light{};
    EXPECT_EQ(traffic_light.CurrentState(), "Red Light");

    traffic_light.Update();
    EXPECT_EQ(traffic_light.CurrentState(), "Green Light");

    traffic_light.Update();
    EXPECT_EQ(traffic_light.CurrentState(), "Yellow Light");

    traffic_light.Update();
    EXPECT_EQ(traffic_light.CurrentState(), "Red Light");
}
} // namespace
