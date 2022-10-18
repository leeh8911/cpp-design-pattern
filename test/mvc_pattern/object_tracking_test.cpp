/**
 * @file object_tracking_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "src/mvc_pattern/application/object_tracking.h"

#include <gtest/gtest.h>

#include <vector>

#include "src/mvc_pattern/application/input.h"
#include "src/mvc_pattern/application/output.h"
#include "src/mvc_pattern/application/tracking.h"

namespace design_pattern::test
{

using namespace design_pattern::mvc::app;  // NOLINT

class ObjectTrackingTest : public testing::Test
{
 public:
    ObjectTracking object_tracking_;
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(ObjectTrackingTest, Input)
{
    std::vector<Sensor> sensor_vector{};
    sensor_vector.push_back(Sensor{.id = 1});
    sensor_vector.push_back(Sensor{.id = 2});
    sensor_vector.push_back(Sensor{.id = 3});

    Input input;
    input.Update(sensor_vector);

    EXPECT_EQ(input.Size(), 3);
    EXPECT_EQ(input.GetItem(0), sensor_vector[0]);
    EXPECT_EQ(input.GetItem(1), sensor_vector[1]);
    EXPECT_EQ(input.GetItem(2), sensor_vector[2]);
}
TEST_F(ObjectTrackingTest, Output)
{
    std::vector<Target> target_vector{};
    target_vector.push_back(Target{.id = 1});
    target_vector.push_back(Target{.id = 2});
    target_vector.push_back(Target{.id = 3});

    Output output;
    output.Update(target_vector);

    EXPECT_EQ(output.Size(), 3);
    EXPECT_EQ(output.GetItem(0), target_vector[0]);
    EXPECT_EQ(output.GetItem(1), target_vector[1]);
    EXPECT_EQ(output.GetItem(2), target_vector[2]);
}
TEST_F(ObjectTrackingTest, Tracking)
{
    std::vector<Sensor> sensor_vector{};
    sensor_vector.push_back(Sensor{.id = 1});
    sensor_vector.push_back(Sensor{.id = 2});
    sensor_vector.push_back(Sensor{.id = 3});

    std::vector<Target> target_vector{};
    target_vector.push_back(Target{.id = 1});
    target_vector.push_back(Target{.id = 2});
    target_vector.push_back(Target{.id = 3});

    Input input;
    Output output;

    Tracking tracking(&input, &output);

    tracking.InputSensor(sensor_vector);

    tracking.Update();

    std::vector<Target> target_output = tracking.OutputTarget();

    EXPECT_EQ(tracking.InputSize(), 3);
    EXPECT_EQ(tracking.OutputSize(), 3);
    EXPECT_EQ(target_output[0], target_vector[0]);
    EXPECT_EQ(target_output[1], target_vector[1]);
    EXPECT_EQ(target_output[2], target_vector[2]);
}
TEST_F(ObjectTrackingTest, ObjectTracking)
{
    std::vector<Sensor> sensor_vector{};
    sensor_vector.push_back(Sensor{.id = 1});
    sensor_vector.push_back(Sensor{.id = 2});
    sensor_vector.push_back(Sensor{.id = 3});

    std::vector<Target> target_vector{};
    target_vector.push_back(Target{.id = 1});
    target_vector.push_back(Target{.id = 2});
    target_vector.push_back(Target{.id = 3});

    ObjectTracking object_tracking;

    object_tracking.InputSensor(sensor_vector);

    object_tracking.Update();

    std::vector<Target> output = object_tracking.OutputTarget();

    EXPECT_EQ(object_tracking.InputSize(), 3);
    EXPECT_EQ(object_tracking.OutputSize(), 3);

    EXPECT_EQ(output[0], target_vector[0]);
    EXPECT_EQ(output[1], target_vector[1]);
    EXPECT_EQ(output[2], target_vector[2]);
}

}  // namespace design_pattern::test
