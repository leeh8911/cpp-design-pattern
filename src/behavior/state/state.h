/// @file state.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief State Pattern 연습을 위한 Traffic Light 예제입니다.
/// TrafficLight 클래스는 Red, Green, Yellow 상태를 갖는 클래스입니다.
/// 각 색깔에 따라 TrafficLight는 서로 다른 기능(예를 들면 이동 가능/불가능) 을 할 수 있지만,
/// 간단한 예제 구현을 위해 단순한 색깔 이름을 출력하는 방식으로 변경하였습니다.
/// @version 0.1
/// @date 2022-11-08
///
/// @copyright Copyright (c) 2022
///
//

#ifndef SRC_BEHAVIOR_STATE_STATE_H_
#define SRC_BEHAVIOR_STATE_STATE_H_

#include <memory>
#include <string>

namespace design_pattern::behavior::state
{

/// @brief Collor 클래스의 unique pointer를 간단히 사용하기 위한 전방 선언 및 using-directive입니다.
//
class Color;
using ColorPtr = std::unique_ptr<Color>;

/// @brief Collor 클래스는 TrafficLight 클래스가 가질 수 있는 상태에 대한 인터페이스 클래스입니다.
/// 현재 상태의 이름을 출력하거나 다음 상태로 변경해주는 인터페이스를 갖고 있습니다.
//
class Color
{
  public:
    virtual ~Color() = default;
    virtual std::string StateName() = 0;
    virtual ColorPtr Next() = 0;
};

class Red : public Color
{
    std::string StateName() override;
    ColorPtr Next() override;
};

class Green : public Color
{
    std::string StateName() override;
    ColorPtr Next() override;
};

class Yellow : public Color
{
    std::string StateName() override;
    ColorPtr Next() override;
};

/// @brief Red, Green, Yellow 세가지 상태를 갖는 TrafficLight 클래스입니다.
/// 현재 상태를 출력하거나, 다음 상태로 업데이트가 가능합니다.
//
class TrafficLight
{
  public:
    TrafficLight();
    TrafficLight(ColorPtr state);

    std::string CurrentState();
    void Update();

  private:
    ColorPtr state_;
};

} // namespace design_pattern::behavior::state
#endif // SRC_BEHAVIOR_STATE_STATE_H_