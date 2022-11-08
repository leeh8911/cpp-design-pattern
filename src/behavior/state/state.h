/// @file state.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-08
///
/// @copyright Copyright (c) 2022
///
//

#ifndef SRC_BEHAVIOR_STATE_STATE_H_
#define SRC_BEHAVIOR_STATE_STATE_H_

#include <string>

namespace design_pattern::behavior::state
{

class Color
{
  public:
    virtual ~Color() = default;
    virtual std::string StateName() = 0;
    virtual Color *Next() = 0;
};

class Red : public Color
{
    std::string StateName() override;
    Color *Next() override;
};

class Green : public Color
{
    std::string StateName() override;
    Color *Next() override;
};

class Yellow : public Color
{
    std::string StateName() override;
    Color *Next() override;
};

class TrafficLight
{
  public:
    TrafficLight();
    TrafficLight(Color *state);

    std::string CurrentState();
    void Update();

  private:
    Color *state_;
};

} // namespace design_pattern::behavior::state
#endif // SRC_BEHAVIOR_STATE_STATE_H_