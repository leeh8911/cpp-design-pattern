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

/// @brief 주변 환경의 장애물에 대한 클래스 정보입니다.
/// Pattern에 초점을 맞추기 위해 식별자만 기능으로 추가합니다.
///
class Obstacle
{
  public:
    explicit Obstacle(std::size_t id);
    ~Obstacle() = default;
    std::size_t Id();

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

    // TODO: Erase와 Find의 소스코드가 중복된 기능을 표현함
    // TODO: Find를 통해 출력된 id-obstcle은 완전 제거되어야 하나? (현재는 unique_ptr을 출력해야 해서 삭제해버림)
    void Erase(std::size_t id);
    const ObstaclePtr Find(std::size_t id);

    std::unordered_set<std::size_t> GetUsedId() const;

    std::size_t GetEmptyId() const;

  private:
    std::unordered_map<std::size_t, ObstaclePtr> repo_;
};

} // namespace design_pattern::behavior::observer
#endif // SRC_BEHAVIOR_OBSERVER_OBSERVER_H_