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
#include <memory>
#include <utility>

namespace design_pattern::etc::interval {

const NumberInterval NumberInterval::kEmptyInterval{};

NumberInterval::NumberInterval(double from, double to)
    : from_{std::min(from, to)}, to_{std::max(from, to)} {}

NumberInterval::NumberInterval(const std::array<double, 2> &arr)
    : NumberInterval{arr[0], arr[1]} {}

NumberInterval::NumberInterval(const NumberInterval &&other)
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
    NumberInterval other_ = dynamic_cast<const NumberInterval &>(other);
    return IsIncluded(other_.from_) || IsIncluded(other_.to_);
}

bool NumberInterval::IsEmpty() {
    auto temporal_interval = std::make_unique<NumberInterval>(kEmptyInterval);
    return (*this) == (*std::move(temporal_interval));
}

bool NumberInterval::operator==(const Interval &other) const {
    NumberInterval other_ = dynamic_cast<const NumberInterval &>(other);
    return ((from_ == other_.from_) && (to_ == other_.to_));
}

bool NumberInterval::operator!=(const Interval &other) const {
    return !operator==(other);
}

bool NumberInterval::operator<(const Interval &other) const {
    NumberInterval other_ = dynamic_cast<const NumberInterval &>(other);
    return (from_ + to_) / 2. < (other_.from_ + other_.to_) / 2.;
}

Interval &NumberInterval::Intersect(const Interval &other) const {
    if (!IsOverlap(other)) {
        return *std::move(std::make_unique<Interval>(kEmptyInterval));
    }
    NumberInterval other_ = dynamic_cast<const NumberInterval &>(other);

    double from = std::max(from_, other_.from_);
    double to = std::min(to_, other_.to_);
    auto intersect = std::make_unique<NumberInterval>(from, to);
    return *std::move(intersect);
}

Interval &NumberInterval::Union(const Interval &other) const {
    if (!IsOverlap(other)) {
        return *std::move(std::make_unique<Interval>(kEmptyInterval));
    }
    NumberInterval other_ = dynamic_cast<const NumberInterval &>(other);

    double from = std::min(from_, other_.from_);
    double to = std::max(to_, other_.to_);
    auto union_interval = std::make_unique<NumberInterval>(from, to);

    return *std::move(union_interval);
}

std::ostream &operator<<(std::ostream &os, const NumberInterval &interval) {
    os << "<" << interval.from_ << ", " << interval.to_ << ">";
    return os;
}

}  // namespace design_pattern::etc::interval
