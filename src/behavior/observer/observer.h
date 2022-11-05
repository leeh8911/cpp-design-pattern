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

#include <unordered_map>
#include <unordered_set>
#include <utility>

namespace design_pattern::behavior::observer
{

class Obstacle
{
  public:
    Obstacle();
    explicit Obstacle(std::size_t id);
    ~Obstacle();
    std::size_t Id();

    static std::size_t Size();

  private:
    std::size_t id_;

    static std::unordered_set<std::size_t> allocated_id_set_;
    static std::size_t GetEmptyId();
    static bool IsContainedId(std::size_t id);
    static void AllocateId(std::size_t id);
};

class ObstacleRepository
{
  public:
    ObstacleRepository();
    std::size_t Size();
    void GenerateObstacle();

  private:
    std::unordered_map<std::size_t, Obstacle *> repo_;
};

} // namespace design_pattern::behavior::observer
#endif // SRC_BEHAVIOR_OBSERVER_OBSERVER_H_