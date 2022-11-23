/// @file point.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-23
///
/// @copyright Copyright (c) 2022
///
//

#include "src/behavior/strategy/point.h"

#include <iostream>
#include <stdexcept>
#include <utility>

namespace design_pattern::behavior::strategy {

Point::Point(const Point& other) noexcept { *this = other; }

Point::Point(Point&& other) noexcept { *this = std::move(other); }

Point& Point::operator=(const Point& other) noexcept {
    if (this != &other) {
        x_ = other.x_;
        y_ = other.y_;
    }
    return *this;
}

Point& Point::operator=(Point&& other) noexcept {
    if (this != &other) {
        x_ = other.x_;
        y_ = other.y_;
    }
    return *this;
}

Point& Point::operator/=(double scalar) {
    if (scalar == 0.0) throw std::invalid_argument("scalar is zero");

    double inv_scalar = 1 / scalar;
    *this *= inv_scalar;
    return *this;
}

Point::Point(double x, double y) noexcept : x_(x), y_(y) {}

bool Point::operator==(const Point& rhs) const {
    return ((x_ == rhs.x_) && (y_ == rhs.y_));
}

bool Point::operator!=(const Point& rhs) const { return !(*this == rhs); }

Point& Point::operator-() {
    x_ = -x_;
    y_ = -y_;

    return *this;
}

Point& Point::operator+=(const Point& rhs) {
    x_ += rhs.x_;
    y_ += rhs.y_;

    return *this;
}

Point& Point::operator-=(const Point& rhs) {
    *this += -Point(rhs);
    return *this;
}

Point& Point::operator*=(double scalar) {
    x_ *= scalar;
    y_ *= scalar;
    return *this;
}

Point Point::operator+(const Point& rhs) const {
    Point add(*this);
    add += rhs;
    return add;
}

Point Point::operator-(const Point& rhs) const { return (*this + -Point(rhs)); }

Point Point::operator*(double scalar) const {
    Point scalar_mult(*this);
    scalar_mult *= scalar;
    return scalar_mult;
}

Point Point::operator/(double scalar) const {
    Point scalar_div(*this);
    scalar_div /= scalar;
    return scalar_div;
}

Point operator/(double scalar, const Point& rhs) {
    if ((rhs.x_ == 0.0) || (rhs.y_ == 0.0))
        throw std::invalid_argument("scalar is zero");
    Point inv_rhs(1 / rhs.x_, 1 / rhs.y_);
    return scalar * inv_rhs;
}

Point operator*(double scalar, const Point& rhs) {
    Point scalar_mult = rhs * scalar;
    return scalar_mult;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "<" << p.x_ << ", " << p.y_ << ">";
    return os;
}
}  // namespace design_pattern::behavior::strategy
