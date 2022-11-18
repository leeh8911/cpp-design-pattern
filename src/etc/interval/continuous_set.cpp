/// @file continuous_set.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-18
///
/// @copyright Copyright (c) 2022
///

#include "src/etc/interval/continuous_set.h"

#include <algorithm>
#include <memory>
#include <utility>
#include <vector>

namespace design_pattern::etc::interval {

std::size_t ContinuousSet::Size() const { return intervals_.size(); }

ContinuousSet &ContinuousSet::Union(const Interval &interval) {
    intervals_.emplace_back(interval);

    std::sort(intervals_.begin(), intervals_.end());

    RemoveOverlappedInterval();

    return *this;
}

ContinuousSet &ContinuousSet::Intersect(const Interval &interval) {
    NumberInterval interval2{};
    interval2.Union(interval);
    if (interval2 == interval) {
        return *this;
    }
    return *this;
}

bool ContinuousSet::operator==(const Interval &interval) const {
    if (intervals_.size() != 1) {
        return false;
    }

    return intervals_.at(0) == interval;
}

bool ContinuousSet::operator==(const ContinuousSet &other) const {
    if (intervals_.size() != other.intervals_.size()) {
        return false;
    }

    auto this_it = intervals_.begin();
    auto other_it = other.intervals_.begin();
    for (; this_it != intervals_.end(); this_it++, other_it++) {
        if ((*this_it) != (*other_it)) {
            return false;
        }
    }
    return true;
}

bool ContinuousSet::operator!=(const ContinuousSet &other) const {
    return !((*this) == other);
}

bool ContinuousSet::operator!=(const Interval &interval) const {
    return !((*this) == interval);
}

void ContinuousSet::RemoveOverlappedInterval() {
    auto iter = intervals_.begin();

    std::vector<IntervalPtr> temporal_vector{};
    temporal_vector.reserve(intervals_.size());

    NumberInterval interval{};
    for (; (iter != intervals_.end()); iter++) {
        if (temporal_vector.empty()) {
            temporal_vector.emplace_back(*iter);
        } else {
            interval = temporal_vector.back();
            if (interval.IsOverlap(*iter)) {
                temporal_vector.back() = std::move(interval.Union(*iter));
            } else {
                temporal_vector.emplace_back(*iter);
            }
        }
    }

    intervals_.swap(temporal_vector);
}

std::ostream &operator<<(std::ostream &os,
                         const ContinuousSet &continuous_set) {
    os << "{";
    for (const auto &elm : continuous_set.intervals_) {
        os << elm << " ";
    }
    os << "}";
    return os;
}
}  // namespace design_pattern::etc::interval
