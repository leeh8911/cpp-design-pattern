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
#include <vector>

namespace design_pattern::behavior::observer {

/// @brief 주변 환경의 장애물에 대한 클래스 정보입니다.
/// Pattern에 초점을 맞추기 위해 식별자만 기능으로 추가합니다.
///
class Obstacle {
 public:
    explicit Obstacle(std::size_t id);
    ~Obstacle() = default;
    std::size_t Id();

 private:
    std::size_t id_;
};

using ObstaclePtr = std::shared_ptr<Obstacle>;
using ObstacleMap = std::unordered_map<std::size_t, ObstaclePtr>;

/// @brief ObstacleRepository 관측하기 위한 인터페이스를 제공하는 Subscriber
/// 클래스입니다.
class Subscriber {
 public:
    virtual ~Subscriber() = default;
    virtual void Update(ObstacleMap *obstacle_repo) = 0;
};

using SubscriberPtr = std::shared_ptr<Subscriber>;

/// @brief ObstacleRepository 상태 중 Obstacle의 개수를 세어주는 클래스입니다.
///
class ObstacleCounter : public Subscriber {
 public:
    void Update(ObstacleMap *obstacle_repo) override;
    std::size_t operator()();

 private:
    std::size_t count{};
};

/// @brief ObstacleRepository 상태 중 Obstacle Id만 찾아주는 클래스입니다.
///
class ObstacleIdChecker : public Subscriber {
 public:
    void Update(ObstacleMap *obstacle_repo) override;
    std::vector<std::size_t> operator()();

 private:
    std::vector<std::size_t> ids;
};

/// @brief Obstacle을 저장하는 리포지토리 클래스입니다.
/// 해당 저장소를 관측하고자 하는 객체가 있다면 AddSubscriber를 통해 연결해줄 수
/// 있습니다.
///
class ObstacleRepository {
 public:
    ObstacleRepository();
    std::size_t Size();

    void GenerateObstacle();
    void GenerateObstacleById(std::size_t id);

    void Erase(std::size_t id);
    const ObstaclePtr Find(std::size_t id);

    std::unordered_set<std::size_t> GetUsedId() const;

    std::size_t GetEmptyId() const;

    void AddSubscriber(SubscriberPtr sub);
    std::size_t SubscribedCount();
    void RemoveSubscriber(SubscriberPtr sub);
    void Notify();

 private:
    ObstacleMap repo_;
    std::vector<SubscriberPtr> subscribers;
};

}  // namespace design_pattern::behavior::observer
#endif  // SRC_BEHAVIOR_OBSERVER_OBSERVER_H_
