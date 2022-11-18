/// @file angle.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-18
///
/// @copyright Copyright (c) 2022
///
//

#ifndef SRC_ETC_INTERVAL_ANGLE_H_
#define SRC_ETC_INTERVAL_ANGLE_H_

#include <cmath>
#include <iostream>

namespace design_pattern::etc::interval {

class Angle {
 public:
    Angle() = default;
    explicit Angle(double degree);

    double Radian() const;
    double Degree() const;
    void Radian(double value);
    void Degree(double value);

    bool operator==(Angle other) const;
    bool operator!=(Angle other) const;

    Angle operator+(Angle other) const;
    Angle operator-(Angle other) const;
    Angle operator*(double scalar) const;
    Angle operator/(double scalar) const;
    Angle operator-() const;

    friend std::ostream &operator<<(std::ostream &os, Angle angle);

 private:
    double SaturateMinMaxRange(double degree);

    double degree_value_{};
    static constexpr double kMinAngleDegree = 0.0;
    static constexpr double kMaxAngleDegree = 360.0;
    static constexpr double kDegreeToRadian = 180. * M_1_PI;
    static constexpr double kRadianToDegree = 1 / kDegreeToRadian;
};

}  // namespace design_pattern::etc::interval
#endif  // SRC_ETC_INTERVAL_ANGLE_H_