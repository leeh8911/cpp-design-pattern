/// @file continuous_set.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-18
///
/// @copyright Copyright (c) 2022
///

#include "src/etc/interval/continuous_set.h"

namespace design_pattern::etc::interval {

std::size_t ContinuousSet::Size() const { return intervals_.size(); }

// TODO(sangwon): find_if와 같은 iterator 기반으로 연산을 변경해야 함
ContinuousSet &ContinuousSet::Union(const Interval &interval) {
    if (intervals_.size() == 0) {
        intervals_.emplace_back(interval);
        return *this;
    }
    if (intervals_.size() == 1) {
        if (intervals_[0].IsOverlap(interval)) {
            intervals_[0] = intervals_[0].Union(interval);
        } else {
            intervals_.emplace_back(interval);
        }
        return *this;
    }

    auto it = intervals_.begin();
    Interval unioned{};

    for (; it != intervals_.end(); it++) {
        unioned = (*it).Union(interval);
        if (unioned.IsEmpty()) {
            break;
        }
    }
    if (unioned.IsEmpty()) {
        std::swap(*it, unioned);
    } else {
        intervals_.emplace_back(interval);
    }

    RemoveOverlappedInterval();

    return *this;
}

ContinuousSet &ContinuousSet::Intersect(const Interval &interval) {
    Interval interval2{};
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
    auto first = intervals_.begin();
    auto second = first + 1;

    for (; (first != intervals_.end()) && (second != intervals_.end());
         first++, second++) {
        if ((*first).IsOverlap(*second)) {
            Interval interval = (*first).Union(*second);
            intervals_.erase(first, second + 1);
            intervals_.insert(first, interval);
            first++, second++;
        }

        if ((first == intervals_.end()) || (second == intervals_.end())) {
            break;
        }
    }
}

void ContinuousSet::Order() {
    // TODO(sangwon): Ordering continuous set
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
