/// @file observer.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-05
///
/// @copyright Copyright (c) 2022
///
//

#ifndef SRC_BEHAVIOR_OBSERVER_OBSERVER_H_
#define SRC_BEHAVIOR_OBSERVER_OBSERVER_H_

#include <utility>

namespace design_pattern::behavior::observer
{

class Obstacle
{
  public:
    std::size_t id_;
    Obstacle();

  private:
};

} // namespace design_pattern::behavior::observer
#endif // SRC_BEHAVIOR_OBSERVER_OBSERVER_H_