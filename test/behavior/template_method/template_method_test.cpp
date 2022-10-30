/// @file template_method_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-10-29
///
/// @copyright Copyright (c) 2022
///

#include "src/behavior/template_method/template_method.h"

#include <gtest/gtest.h>

namespace
{

using namespace design_pattern::behavior::template_method;

TEST(ObjectTest, ObjectSampleTest)
{
    auto obj = std::make_unique<Object>();
    auto default_position = Vector2D({0.0, 0.0});
    auto default_velocity = Vector2D({0.0, 0.0});
    EXPECT_EQ(obj->Position(), default_position);
    EXPECT_EQ(obj->Velocity(), default_velocity);
    EXPECT_EQ(obj->AliveCount(), 1);

    auto meas = std::make_unique<Object>();
    auto meas_position = Vector2D({1.0, 1.0});
    auto meas_velocity = Vector2D({1.0, 1.0});

    meas->Position({1.0, 1.0});
    meas->Velocity({1.0, 1.0});
    EXPECT_EQ(meas->Position(), meas_position);
    EXPECT_EQ(meas->Velocity(), meas_velocity);
    EXPECT_EQ(meas->AliveCount(), 1);

    obj->Assignment(std::move(meas));
    EXPECT_TRUE(meas == nullptr);

    EXPECT_TRUE(obj->HasMeasurement());

    EXPECT_TRUE(obj->Update());

    EXPECT_FALSE(obj->HasMeasurement());
    EXPECT_EQ(obj->Position(), meas_position);
    EXPECT_EQ(obj->Velocity(), meas_velocity);
    EXPECT_EQ(obj->AliveCount(), 2);

    EXPECT_FALSE(obj->Update());
}

TEST(BoxObjectTest, BoxObjectSampleTest)
{
    auto bo = std::make_unique<BoxObject>();
    auto default_position = Vector2D({0.0, 0.0});
    auto default_velocity = Vector2D({0.0, 0.0});
    auto default_shape = Vector2D({0.0, 0.0});
    EXPECT_EQ(bo->Position(), default_position);
    EXPECT_EQ(bo->Velocity(), default_velocity);
    EXPECT_EQ(bo->Shape(), default_shape);
    EXPECT_EQ(bo->Rotation(), 0.0);
    EXPECT_EQ(bo->AliveCount(), 1);

    auto meas = std::make_unique<BoxObject>();
    auto meas_position = Vector2D({1.0, 1.0});
    auto meas_velocity = Vector2D({1.0, 1.0});
    auto meas_shape = Vector2D({1.0, 1.0});
    EXPECT_EQ(meas->Position(), meas_position);
    EXPECT_EQ(meas->Velocity(), meas_velocity);
    EXPECT_EQ(meas->Shape(), meas_shape);
    EXPECT_EQ(meas->Rotation(), kPi / 12);
    EXPECT_EQ(meas->AliveCount(), 1);

    bo->Assignment(std::move(meas));
    EXPECT_TRUE(meas == nullptr);

    EXPECT_TRUE(obj->HasMeasurement());

    EXPECT_TRUE(obj->Update());

    EXPECT_FALSE(obj->HasMeasurement());
    EXPECT_EQ(obj->Position(), meas_position);
    EXPECT_EQ(obj->Velocity(), meas_velocity);
    EXPECT_EQ(obj->Shape(), meas_shape);
    EXPECT_EQ(obj->Rotation(), kPi / 12);
    EXPECT_EQ(obj->AliveCount(), 2);

    EXPECT_FALSE(obj->Update());
}
}  // namespace
