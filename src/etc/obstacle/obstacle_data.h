/// @file obstacle_data.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief 장애물 데이터(ObstacleData) 정보를 정의하는 헤더파일입니다.
/// 장애물 데이터들은 다음과 같습니다.
/// 1. 점 물체 (위치, 속도 정보만 포함)
/// 2. 박스 (위치, 속도, 형태, 자세 포함)
/// 3. 컨투어 (위치, 속도, 폴리라인)
/// 각 장해물 데이터들은 식별자(id), 분류(classification), 이동상태(moving status) 등을 포함하고 있습니다.
/// @version 0.1
/// @date 2022-11-09
///
/// @copyright Copyright (c) 2022
///
//

#ifndef SRC_ETC_OBJECT_OBSTACLE_DATA_H_
#define SRC_ETC_OBJECT_OBSTACLE_DATA_H_

#include <array>
#include <iostream>

namespace design_pattern::etc::obstacle::data
{

using Vector2D = std::array<double, 2>;
bool operator==(const Vector2D &lhs, const Vector2D &rhs);

struct PointObstacleData
{
    std::size_t id_;
    std::size_t classification;
    std::size_t moving_status;

    Vector2D pos_;
    Vector2D vel_;
};

std::ostream &operator<<(std::ostream &os, const PointObstacleData &obstacle_data);

} // namespace design_pattern::etc::obstacle::data
#endif // SRC_ETC_OBJECT_OBSTACLE_DATA_H_