/// @file template_method.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief 템플릿 메소드 구현을 위한 헤더파일
/// @version 0.1
/// @date 2022-11-04
///
/// @copyright Copyright (c) 2022
///
///
//

#ifndef SRC_BEHAVIOR_TEMPLATE_METHOD_TEMPLATE_METHOD_H_
#define SRC_BEHAVIOR_TEMPLATE_METHOD_TEMPLATE_METHOD_H_

#include <sstream>

namespace design_pattern::behavior::template_method
{

class HouseBuilder
{
  public:
    HouseBuilder() = default;
    virtual ~HouseBuilder() = default;
    virtual std::stringstream Build();
    virtual std::string Start();
    virtual std::string MakeBasement();
    virtual std::string MakePillar();
    virtual std::string MakeWall();
    virtual std::string MakeRoof();
    virtual std::string MakeRooms();
    virtual std::string End();

  private:
};

} // namespace design_pattern::behavior::template_method
#endif // SRC_BEHAVIOR_TEMPLATE_METHOD_TEMPLATE_METHOD_H_