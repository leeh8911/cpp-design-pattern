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

ContinuousSet &ContinuousSet::Union(IntervalPtr interval) {
    intervals_.emplace_back(std::move(interval));

    std::sort(intervals_.begin(), intervals_.end());

    RemoveOverlappedInterval();

    return *this;
}

ContinuousSet &ContinuousSet::Intersect(IntervalPtr interval) {
    NumberInterval interval2{};
    interval2.Union(std::move(interval));
    if (interval2.IsEmpty()) {
        return *this;
    }
    return *this;
}

bool ContinuousSet::operator==(const Interval &interval) const {
    if (intervals_.size() != 1) {
        return false;
    }

    Interval &this_interval = *(intervals_.at(0).get());
    return this_interval == interval;
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
    std::vector<IntervalPtr> temporal_vector{};
    temporal_vector.reserve(intervals_.size());

    // [NOTE]
    // Do intervals_ elements move to temporal vector.
    // When move element, if there is overlapped area to temporal vector's
    // element moved element change to union(element, overlapped temporal
    // vector's element)
    // Otherwise, just move into temporal vector
    for (auto iter = intervals_.begin(); (iter != intervals_.end()); iter++) {
        if (temporal_vector.empty()) {
            temporal_vector.emplace_back(std::move(*iter));
            continue;
        }

        IntervalPtr interval = nullptr;
        std::swap(interval, temporal_vector.back());
        temporal_vector.pop_back();

        if (interval->IsOverlap((**iter))) {
            auto union_ptr = (interval->Union(std::move(*iter)));
            temporal_vector.emplace_back(std::move(union_ptr));
        } else {
            temporal_vector.emplace_back(std::move(interval));
            temporal_vector.emplace_back(std::move(*iter));
        }
    }

    intervals_.swap(temporal_vector);
}

std::ostream &operator<<(std::ostream &os,
                         const ContinuousSet &continuous_set) {
    os << "{";
    for (const auto &elm : continuous_set.intervals_) {
        os << *elm.get() << " ";
    }
    os << "}";
    return os;
}
}  // namespace design_pattern::etc::interval
