/// @file object_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-10-29
///
/// @copyright Copyright (c) 2022
///

#include "src/etc/object/object.h"

#include <gtest/gtest.h>

namespace
{

using namespace design_pattern::etc::object;

TEST(ObjectTest, ObjectDefaultCreate)
{
    auto obj = std::make_unique<Object>();
    auto default_position = Vector2D({0.0, 0.0});
    auto default_velocity = Vector2D({0.0, 0.0});
    EXPECT_EQ(obj->Position(), default_position);
    EXPECT_EQ(obj->Velocity(), default_velocity);
    EXPECT_EQ(obj->AliveCount(), 1);
}

TEST(ObjectTest, ObjectMutate)
{
    auto obj = std::make_unique<Object>();
    auto position = Vector2D({1.0, 1.0});
    auto velocity = Vector2D({1.0, 1.0});

    obj->Position({1.0, 1.0});
    obj->Velocity({1.0, 1.0});
    EXPECT_EQ(obj->Position(), position);
    EXPECT_EQ(obj->Velocity(), velocity);
    EXPECT_EQ(obj->AliveCount(), 1);
}

TEST(ObjectTest, ObjectMeasuredUpdate)
{
    auto meas_position = Vector2D({1.0, 1.0});
    auto meas_velocity = Vector2D({1.0, 1.0});
    auto obj = std::make_unique<Object>();
    auto meas = std::make_unique<Object>(meas_position, meas_velocity);

    obj->Assignment(std::move(meas));
    EXPECT_TRUE(obj->HasMeasurement());
    EXPECT_TRUE(obj->Update());
    EXPECT_EQ(obj->Position(), meas_position);
    EXPECT_EQ(obj->Velocity(), meas_velocity);
    EXPECT_EQ(obj->AliveCount(), 2);

    EXPECT_FALSE(obj->HasMeasurement());

    EXPECT_FALSE(obj->Update());
}

TEST(ObjectTest, BoxObjectDefaultCreate)
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
}
TEST(ObjectTest, BoxObjectMutate)
{
    auto meas = std::make_unique<BoxObject>();
    auto meas_position = Vector2D({1.0, 1.0});
    auto meas_velocity = Vector2D({1.0, 1.0});
    auto meas_shape = Vector2D({1.0, 1.0});
    double meas_rotation = kPi / 12;
    meas->Position(meas_position);
    meas->Velocity(meas_velocity);
    meas->Shape(meas_shape);
    meas->Rotation(meas_rotation);
    EXPECT_EQ(meas->Position(), meas_position);
    EXPECT_EQ(meas->Velocity(), meas_velocity);
    EXPECT_EQ(meas->Shape(), meas_shape);
    EXPECT_EQ(meas->Rotation(), kPi / 12);
    EXPECT_EQ(meas->AliveCount(), 1);
}
TEST(ObjectTest, BoxObjectMeasuredUpdate)
{
    auto meas_position = Vector2D({1.0, 1.0});
    auto meas_velocity = Vector2D({1.0, 1.0});
    auto meas_shape = Vector2D({1.0, 1.0});
    double meas_rotation = kPi / 12;
    auto obj = std::make_unique<BoxObject>();
    auto meas = std::make_unique<BoxObject>(meas_position, meas_velocity, meas_shape, meas_rotation);

    obj->Assignment(std::move(meas));
    EXPECT_TRUE(obj->HasMeasurement());
    EXPECT_TRUE(obj->Update());
    EXPECT_EQ(obj->Position(), meas_position);
    EXPECT_EQ(obj->Velocity(), meas_velocity);
    EXPECT_EQ(obj->Shape(), meas_shape);
    EXPECT_EQ(obj->Rotation(), kPi / 12);
    EXPECT_EQ(obj->AliveCount(), 2);

    EXPECT_FALSE(obj->HasMeasurement());

    EXPECT_FALSE(obj->Update());
}
} // namespace
