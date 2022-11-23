/// @file point.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-23
///
/// @copyright Copyright (c) 2022
///
//

#ifndef SRC_BEHAVIOR_STRATEGY_POINT_H_
#define SRC_BEHAVIOR_STRATEGY_POINT_H_

#include <iostream>

namespace design_pattern::behavior::strategy {
class Point {
 public:
    // Rule of Five (basic constructors: default, copy, move, assignments)
    Point() noexcept = default;
    Point(const Point& other) noexcept;
    Point(Point&& other) noexcept;
    Point& operator=(const Point& other) noexcept;
    Point& operator=(Point&& other) noexcept;

    Point(double x, double y) noexcept;

    bool operator==(const Point& rhs) const;
    bool operator!=(const Point& rhs) const;

    Point& operator-();
    Point& operator+=(const Point& rhs);
    Point& operator-=(const Point& rhs);
    Point& operator*=(double scalar);
    Point& operator/=(double scalar);

    Point operator+(const Point& rhs) const;
    Point operator-(const Point& rhs) const;
    Point operator*(double scalar) const;
    Point operator/(double scalar) const;

    friend Point operator*(double scalar, const Point& rhs);
    friend Point operator/(double scalar, const Point& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

 private:
    double x_{}, y_{};
};

Point operator*(double scalar, const Point& rhs);
Point operator/(double scalar, const Point& rhs);
std::ostream& operator<<(std::ostream& os, const Point& p);

}  // namespace design_pattern::behavior::strategy
#endif  // SRC_BEHAVIOR_STRATEGY_POINT_H_
