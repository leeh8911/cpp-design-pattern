/// @file template_method_test.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief 템플릿 메소드 구현을 위한 테스트 파일
/// @version 0.1
/// @date 2022-11-04
///
/// @copyright Copyright (c) 2022
///

#include "src/behavior/template_method/template_method.h"

#include <gtest/gtest.h>

TEST(TemplateMethodTest, SampleTest)
{
    HouseBuilder builder;
    EXPECT_EQ(builder.Build(), "Build House");
}