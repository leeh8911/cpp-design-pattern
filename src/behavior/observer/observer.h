/// @file observer.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief Implement oberser pattern.
/// reference: https://refactoring.guru/ko/design-patterns/observer
/// @version 0.1
/// @date 2022-11-05
///
/// @copyright Copyright (c) 2022
///
//

#ifndef SRC_BEHAVIOR_OBSERVER_OBSERVER_H_
#define SRC_BEHAVIOR_OBSERVER_OBSERVER_H_

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <utility>

namespace design_pattern::behavior::observer
{

class Obstacle
{
  public:
    explicit Obstacle(std::size_t id);
    ~Obstacle() = default;
    std::size_t Id();

    static std::size_t Size();

  private:
    std::size_t id_;
};
using ObstaclePtr = std::unique_ptr<Obstacle>;

class ObstacleRepository
{
  public:
    ObstacleRepository();
    std::size_t Size();

    void GenerateObstacle();
    void GenerateObstacleById(std::size_t id);

    void Erase(std::size_t id);

    std::unordered_set<std::size_t> GetUsedId() const;
    const Obstacle *Find(std::size_t id) const;

    std::size_t GetEmptyId() const;

  private:
    std::unordered_map<std::size_t, ObstaclePtr> repo_;
};

} // namespace design_pattern::behavior::observer
#endif // SRC_BEHAVIOR_OBSERVER_OBSERVER_H_