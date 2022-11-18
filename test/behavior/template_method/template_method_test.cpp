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

#include <sstream>
#include <string>

namespace {
using namespace design_pattern::behavior::template_method;

TEST(TemplateMethodTest, HouseBuild) {
    HouseBuilder builder;

    std::stringstream ss = builder.Build();

    std::stringstream expect_ss;
    expect_ss << "Build House Start" << std::endl;
    expect_ss << "Make Basement" << std::endl;
    expect_ss << "Make Pillar" << std::endl;
    expect_ss << "Make Wall" << std::endl;
    expect_ss << "Make Roof" << std::endl;
    expect_ss << "Make Rooms" << std::endl;
    expect_ss << "Build House End" << std::endl;

    std::string s = "";
    std::string expect_s = "";
    while (ss && expect_ss) {
        std::getline(ss, s);
        std::getline(expect_ss, expect_s);

        EXPECT_EQ(s, expect_s);
    }
}

TEST(TemplateMethodTest, ApartmentBuild) {
    ApartmentBuilder builder;
    builder.BasementDepth(3);
    builder.NumberOfRooms(4);

    std::stringstream ss = builder.Build();

    std::stringstream expect_ss;
    expect_ss << "Build Apartment Start" << std::endl;
    expect_ss << "Make Basement - 3m" << std::endl;
    expect_ss << "Make Pillar" << std::endl;
    expect_ss << "Make Wall" << std::endl;
    expect_ss << "Make Roof" << std::endl;
    expect_ss << "Make Rooms - 4" << std::endl;
    expect_ss << "Build Apartment End" << std::endl;

    std::string s = "";
    std::string expect_s = "";
    while (ss && expect_ss) {
        std::getline(ss, s);
        std::getline(expect_ss, expect_s);

        EXPECT_EQ(s, expect_s);
    }
}
}  // namespace
