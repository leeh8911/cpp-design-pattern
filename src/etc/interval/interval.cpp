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
#include <limits>
#include <utility>

namespace design_pattern::etc::interval {

const Interval Interval::kEmptyInterval{};

Interval::Interval()
    : from_{std::numeric_limits<float>::max()},
      to_{std::numeric_limits<float>::max()} {}

Interval::Interval(double from, double to)
    : from_{std::min(from, to)}, to_{std::max(from, to)} {}

Interval::Interval(const std::array<double, 2> &arr)
    : Interval{arr[0], arr[1]} {}

Interval::Interval(const Interval &&other) : Interval{other.from_, other.to_} {}
Interval::Interval(const Interval &other) : Interval{other.from_, other.to_} {}

Interval &Interval::operator=(Interval &&other) {
    from_ = other.from_;
    to_ = other.to_;
    return *this;
}

bool Interval::IsIncluded(double value) const {
    return ((from_ <= value) && (value <= to_));
}

bool Interval::IsOverlap(const Interval &other) const {
    return IsIncluded(other.from_) || IsIncluded(other.to_);
}

bool Interval::IsEmpty() const { return (*this) == kEmptyInterval; }

bool Interval::operator==(const Interval &other) const {
    return ((from_ == other.from_) && (to_ == other.to_));
}

bool Interval::operator!=(const Interval &other) const {
    return !operator==(other);
}

Interval Interval::Intersect(const Interval &other) const {
    if (!IsOverlap(other)) {
        return kEmptyInterval;
    }

    double from = std::max(from_, other.from_);
    double to = std::min(to_, other.to_);
    Interval intersect{from, to};
    return intersect;
}

Interval Interval::Union(const Interval &other) const {
    if (!IsOverlap(other)) {
        return kEmptyInterval;
    }
    double from = std::min(from_, other.from_);
    double to = std::max(to_, other.to_);
    return Interval(from, to);
}

std::ostream &operator<<(std::ostream &os, const Interval &interval) {
    os << "<" << interval.from_ << ", " << interval.to_ << ">";
    return os;
}

}  // namespace design_pattern::etc::interval
