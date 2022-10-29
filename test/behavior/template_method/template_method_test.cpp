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
    Object o;
    EXPECT_EQ(o.Position(), {0.0, 0.0});
    EXPECT_EQ(o.Velocity(), {0.0, 0.0});
    EXPECT_EQ(o.AliveCount(), 1);
}

TEST(BoxObjectTest, BoxObjectSampleTest)
{
    BoxObject bo;
    EXPECT_EQ(o.Position(), {0.0, 0.0});
    EXPECT_EQ(o.Velocity(), {0.0, 0.0});
    EXPECT_EQ(o.Shape(), {0.0, 0.0});
    EXPECT_EQ(o.Rotation(), 0.0);
    EXPECT_EQ(o.AliveCount(), 1);
}
}  // namespace
