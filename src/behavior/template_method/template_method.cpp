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

} // namespace design_pattern::behavior::template_method
