/// @file template_method.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief 템플릿 메소드 구현을 위한 소스파일
/// @version 0.1
/// @date 2022-11-03
///
/// @copyright Copyright (c) 2022
///
//

#include "src/behavior/template_method/template_method.h"

#include <sstream>

namespace design_pattern::behavior::template_method
{
std::stringstream HouseBuilder::Build()
{
    std::stringstream oss;
    oss << Start();
    oss << MakeBasement();
    oss << MakePillar();
    oss << MakeWall();
    oss << MakeRoof();
    oss << MakeRooms();
    oss << End();
    return oss;
}

std::string HouseBuilder::Start()
{
    return "Build House Start\n";
}

std::string HouseBuilder::MakeBasement()
{
    return "Make Basement\n";
}

std::string HouseBuilder::MakePillar()
{
    return "Make Pillar\n";
}

std::string HouseBuilder::MakeWall()
{
    return "Make Wall\n";
}

std::string HouseBuilder::MakeRoof()
{
    return "Make Roof\n";
}

std::string HouseBuilder::MakeRooms()
{
    return "Make Rooms\n";
}

std::string HouseBuilder::End()
{
    return "Build House End\n";
}

void ApartmentBuilder::BasementDepth(int depth)
{
    basement_depth = depth;
}

void ApartmentBuilder::NumberOfRooms(int num)
{
    number_of_rooms = num;
}

std::string ApartmentBuilder::Start()
{
    return "Build Apartment Start\n";
}

std::string ApartmentBuilder::MakeBasement()
{
    std::stringstream oss;
    oss << "Make Basement - " << basement_depth << "m\n";
    return oss.str();
}

std::string ApartmentBuilder::MakePillar()
{
    return "Make Pillar\n";
}

std::string ApartmentBuilder::MakeWall()
{
    return "Make Wall\n";
}

std::string ApartmentBuilder::MakeRoof()
{
    return "Make Roof\n";
}

std::string ApartmentBuilder::MakeRooms()
{
    std::stringstream oss;
    oss << "Make Rooms - " << number_of_rooms << "\n";
    return oss.str();
}

std::string ApartmentBuilder::End()
{
    return "Build Apartment End\n";
}

} // namespace design_pattern::behavior::template_method
