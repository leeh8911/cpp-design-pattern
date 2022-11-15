/// @file obstacle.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-10-30
///
/// @copyright Copyright (c) 2022
///

#ifndef SRC_ETC_OBJECT_OBJECT_H_
#define SRC_ETC_OBJECT_OBJECT_H_

#include <array>
#include <map>
#include <memory>
#include <utility>

#include "src/etc/obstacle/obstacle_data.h"

namespace design_pattern::etc::obstacle {
namespace entity {

/// @brief Forward declarations
class PointObstacleRepository;
class PointObstacle;

using PointObstaclePtr = std::shared_ptr<PointObstacle>;

class PointObstacle {
 public:
    PointObstacle() = delete;
    PointObstacle(const PointObstacle &) = delete;
    PointObstacle(const PointObstacle &&) = delete;
    // TODO: To be privated.
    PointObstacle(const data::PointObstacleData &point_obstacle_data);

    bool operator==(const data::PointObstacleData &point_obstacle_data) const;

    friend PointObstacleRepository;
    friend std::ostream &operator<<(std::ostream &os,
                                    const PointObstacle &point_obstacle);

 private:
    data::PointObstacleData data_;
};

bool operator==(const data::PointObstacleData &point_obstacle_data,
                const PointObstacle &point_obstacle);
std::ostream &operator<<(std::ostream &os, const PointObstacle &point_obstacle);

class PointObstacleRepository {
 public:
    std::size_t Size() const;
    void Create(const data::PointObstacleData &obstacle_data);
    PointObstaclePtr Read(std::size_t id);
    void Update(const data::PointObstacleData &obstacle_data);
    void Delete(std::size_t id);

 private:
    std::map<std::size_t, PointObstaclePtr> repo_;
};

}  // namespace entity

}  // namespace design_pattern::etc::obstacle
#endif  // SRC_ETC_OBJECT_OBJECT_H_