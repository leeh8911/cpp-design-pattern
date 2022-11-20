/// @file interval.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-11
///
/// @copyright Copyright (c) 2022
///
//

#include "src/etc/interval/interval.h"

#include <algorithm>
#include <cmath>
#include <exception>
#include <limits>
#include <memory>
#include <string>
#include <utility>

namespace design_pattern::etc::interval {

const NumberInterval NumberInterval::kEmptyInterval{};
const AngleInterval AngleInterval::kEmptyAngleInterval{};

NumberInterval::NumberInterval(double from, double to)
    : from_{std::min(from, to)}, to_{std::max(from, to)} {}

NumberInterval::NumberInterval(const std::array<double, 2> &arr)
    : NumberInterval{arr[0], arr[1]} {}

NumberInterval::NumberInterval(NumberInterval &&other)
    : NumberInterval{other.from_, other.to_} {}

NumberInterval::NumberInterval(const NumberInterval &other)
    : NumberInterval{other.from_, other.to_} {}

NumberInterval &NumberInterval::operator=(NumberInterval &&other) {
    from_ = other.from_;
    to_ = other.to_;
    return *this;
}

bool NumberInterval::IsIncluded(double value) const {
    return ((from_ <= value) && (value <= to_));
}

bool NumberInterval::IsOverlap(const Interval &other) const {
    if (other.IsIncluded(from_) || other.IsIncluded(to_)) {
        return true;
    }
    if (IsIncluded(other.From()) && IsIncluded(other.To())) {
        return true;
    }
    return false;
}

bool NumberInterval::IsEmpty() { return (*this) == (kEmptyInterval); }

bool NumberInterval::operator==(const Interval &other) const {
    return ((from_ == other.From()) && (to_ == other.To()));
}

bool NumberInterval::operator!=(const Interval &other) const {
    return !operator==(other);
}

bool NumberInterval::operator<(const Interval &other) const {
    NumberInterval other_ = dynamic_cast<const NumberInterval &>(other);
    return (from_ + to_) / 2. < (other_.from_ + other_.to_) / 2.;
}

IntervalPtr NumberInterval::Intersect(IntervalPtr other) const {
    if (!IsOverlap(*other)) {
        return std::make_unique<NumberInterval>(kEmptyInterval);
    }

    double from = std::max(from_, other->From());
    double to = std::min(to_, other->To());
    auto intersect = std::make_unique<NumberInterval>(from, to);
    return intersect;
}

IntervalPtr NumberInterval::Union(IntervalPtr other) const {
    if (!IsOverlap(*other)) {
        return std::make_unique<NumberInterval>(kEmptyInterval);
    }
    double from = std::min(from_, other->From());
    double to = std::max(to_, other->To());
    auto union_interval = std::make_unique<NumberInterval>(from, to);

    return union_interval;
}

std::string NumberInterval::ToString() const {
    std::string result{};
    result = "<" + std::to_string(from_) + ", " + std::to_string(to_) + ">";
    return result;
}

double NumberInterval::From() const { return from_; }

double NumberInterval::To() const { return to_; }

AngleInterval::AngleInterval(Angle from, Angle to) : from_(from), to_(to) {}

AngleInterval::AngleInterval(AngleInterval &&other)
    : from_(other.from_), to_(other.to_) {}

AngleInterval::AngleInterval(const AngleInterval &other)
    : from_(other.from_), to_(other.to_) {}

AngleInterval::AngleInterval(const std::array<Angle, 2> &arr)
    : from_(arr[0]), to_(arr[1]) {}

AngleInterval &AngleInterval::operator=(AngleInterval &&other) {
    from_ = other.from_;
    to_ = other.to_;
    return *this;
}

bool AngleInterval::IsIncluded(double value) const {
    Angle angle(value);

    return ((from_ <= angle) && (angle <= to_));
}

bool AngleInterval::IsOverlap(const Interval &other) const {
    if (other.IsIncluded(From()) || other.IsIncluded(To())) {
        return true;
    }
    if (IsIncluded(other.From()) && IsIncluded(other.To())) {
        return true;
    }
    return false;
}

bool AngleInterval::IsEmpty() { return (*this) == (kEmptyAngleInterval); }

bool AngleInterval::operator==(const Interval &other) const {
    return ((From() == other.From()) && (To() == other.To()));
}

bool AngleInterval::operator!=(const Interval &other) const {
    return !((*this) == other);
}

bool AngleInterval::operator<(const Interval &other) const {
    AngleInterval other_ = dynamic_cast<const AngleInterval &>(other);
    return (from_ + to_) / 2. < (other_.from_ + other_.to_) / 2.;
}

IntervalPtr AngleInterval::Intersect(IntervalPtr other) const {
    if (!IsOverlap(*other)) {
        return std::make_unique<AngleInterval>(kEmptyAngleInterval);
    }
    AngleInterval other_ = dynamic_cast<const AngleInterval &>(other);

    Angle from = std::max(from_, other_.from_);
    Angle to = std::min(to_, other_.to_);
    auto intersect = std::make_unique<AngleInterval>(from, to);
    return intersect;
}

IntervalPtr AngleInterval::Union(IntervalPtr other) const {
    if (!IsOverlap(*other)) {
        return std::make_unique<AngleInterval>(kEmptyAngleInterval);
    }
    AngleInterval other_ = dynamic_cast<const AngleInterval &>(other);

    Angle from = std::min(from_, other_.from_);
    Angle to = std::max(to_, other_.to_);
    auto union_interval = std::make_unique<AngleInterval>(from, to);

    return union_interval;
}

double AngleInterval::From() const { return static_cast<double>(from_); }

double AngleInterval::To() const { return static_cast<double>(to_); }

std::ostream &operator<<(std::ostream &os, const Interval &interval) {
    os << "<" << interval.ToString() << ">";
    return os;
}

}  // namespace design_pattern::etc::interval
