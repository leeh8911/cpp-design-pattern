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

struct BuilderInterface
{
    BuilderInterface() = default;
    virtual ~BuilderInterface() = default;
    virtual std::stringstream Build() = 0;
};

class HouseBuilder : public BuilderInterface
{
  public:
    HouseBuilder() = default;
    ~HouseBuilder() override = default;
    std::stringstream Build() final;

  private:
    virtual std::string Start();
    virtual std::string MakeBasement();
    virtual std::string MakePillar();
    virtual std::string MakeWall();
    virtual std::string MakeRoof();
    virtual std::string MakeRooms();
    virtual std::string End();
};
class ApartmentBuilder : public HouseBuilder
{
  public:
    ApartmentBuilder() = default;
    ~ApartmentBuilder() override = default;

    void BasementDepth(int depth);
    void NumberOfRooms(int num);

  private:
    std::string Start() override;
    std::string MakeBasement() override;
    std::string MakePillar() override;
    std::string MakeWall() override;
    std::string MakeRoof() override;
    std::string MakeRooms() override;
    std::string End() override;

    int basement_depth{};
    int number_of_rooms{};
};

} // namespace design_pattern::behavior::template_method
#endif // SRC_BEHAVIOR_TEMPLATE_METHOD_TEMPLATE_METHOD_H_