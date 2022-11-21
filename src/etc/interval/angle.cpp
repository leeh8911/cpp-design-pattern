/// @file angle.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-18
///
/// @copyright Copyright (c) 2022
///
//

#include "src/etc/interval/angle.h"
namespace design_pattern::etc::interval {

constexpr double Angle::kDegreeToRadian;
constexpr double Angle::kRadianToDegree;
constexpr double Angle::kMinAngleDegree;
constexpr double Angle::kMaxAngleDegree;

Angle::Angle(double degree) : degree_value_(SaturateMinMaxRange(degree)) {}

double Angle::Radian() const { return degree_value_ * kRadianToDegree; }

double Angle::Degree() const { return degree_value_; }

void Angle::Radian(double value) { degree_value_ = value * kDegreeToRadian; }

void Angle::Degree(double value) { degree_value_ = value; }

bool Angle::operator==(const Angle& other) const {
    return degree_value_ == other.degree_value_;
}

bool Angle::operator!=(const Angle& other) const { return !(*this == other); }

bool Angle::operator<(const Angle& other) const {
    return degree_value_ < other.degree_value_;
}

bool Angle::operator<=(const Angle& other) const {
    return ((*this) < other) || ((*this) == other);
}

bool Angle::operator>(const Angle& other) const { return !((*this) <= other); }

bool Angle::operator>=(const Angle& other) const { return !((*this) < other); }

Angle& Angle::operator-=(const Angle& other) {
    *this += (-other);
    return *this;
}

Angle& Angle::operator+=(const Angle& other) {
    degree_value_ += other.degree_value_;
    degree_value_ = SaturateMinMaxRange(degree_value_);

    return *this;
}

Angle Angle::operator-(const Angle& other) const { return (*this + -other); }

Angle Angle::operator/(double scalar) const { return (*this) * (1 / scalar); }

Angle Angle::operator-() const { return Angle(-degree_value_); }

Angle Angle::operator*(double scalar) const {
    return Angle(degree_value_ * scalar);
}

Angle Angle::operator+(const Angle& other) const {
    Angle add(*this);
    add += other;
    return add;
}

double Angle::SaturateMinMaxRange(double degree) {
    degree = std::fmod(degree, kMaxAngleDegree);
    return degree < 0 ? (degree + 360.) : degree;
}

std::ostream& operator<<(std::ostream& os, const Angle& angle) {
    os << angle.degree_value_;
    return os;
}
}  // namespace design_pattern::etc::interval
