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

#include <iostream>

namespace
{

using namespace design_pattern::etc::object;

// TODO: Identifiable instances are equal to itself
// TODO: Identifiable instances are not equal to others
//

class DummyClass
{
};
TEST(ObjectTest, Should_EqualIdentifiable_When_SameIdentifiableInstance)
{
    entity::Identifiable<DummyClass> first;
    entity::Identifiable<DummyClass> second;

    EXPECT_EQ(first, first);
    EXPECT_NE(first, second);
}

// TODO: implement equality of object data and object
// TODO: What kind of member variables in object data? (simply just id data)
TEST(ObjectTest, Should_EqualObjectAndObjectData_When_GivenObjectData)
{
    data::ObjectData object_data{};
    entity::Object object(object_data);

    EXPECT_EQ(object, object_data);
}

TEST(ObjectTest, Should_NotEqualObjectAndObjectData_When_GivenObjectDataAndOther)
{
    data::ObjectData object_data{};
    data::ObjectData other_data{};
    entity::Object object(object_data);

    EXPECT_NE(object, other_data);
}

} // namespace
