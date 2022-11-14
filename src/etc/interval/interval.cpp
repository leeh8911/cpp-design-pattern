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
#include <limits>
#include <utility>

namespace design_pattern::etc::interval
{

Interval Interval::kEmptyInterval{std::numeric_limits<float>::max(), std::numeric_limits<float>::max()};

Interval::Interval() : Interval(kEmptyInterval)
{
}

Interval::Interval(double from, double to) : from_{std::min(from, to)}, to_{std::max(from, to)}
{
}

Interval::Interval(const std::array<double, 2> &arr) : Interval{arr[0], arr[1]}
{
}

Interval::Interval(const Interval &&other) : Interval{other.from_, other.to_}
{
}
Interval::Interval(const Interval &other) : Interval{other.from_, other.to_}
{
}

Interval &Interval::operator=(Interval &&other)
{
    from_ = other.from_;
    to_ = other.to_;
    return *this;
}

bool Interval::IsIncluded(double value) const
{
    return ((from_ <= value) && (value <= to_));
}

bool Interval::IsOverlap(const Interval &other) const
{
    return IsIncluded(other.from_) || IsIncluded(other.to_);
}

bool Interval::operator==(const Interval &other) const
{
    return ((from_ == other.from_) && (to_ == other.to_));
}

bool Interval::operator!=(const Interval &other) const
{
    return !operator==(other);
}

Interval Interval::Intersect(const Interval &other) const
{
    if (!IsOverlap(other))
    {
        return kEmptyInterval;
    }

    double from = std::max(from_, other.from_);
    double to = std::min(to_, other.to_);
    Interval intersect{from, to};
    return intersect;
}

Interval Interval::Union(const Interval &other) const
{
    if (!IsOverlap(other))
    {
        return kEmptyInterval;
    }
    double from = std::min(from_, other.from_);
    double to = std::max(to_, other.to_);
    return Interval(from, to);
}

std::size_t ContinuousSet::Size() const
{
    return intervals_.size();
}

ContinuousSet &ContinuousSet::Union(const Interval &interval)
{
    if (intervals_.size() == 0)
    {
        intervals_.emplace_back(interval);
        return *this;
    }
    if (intervals_.size() == 1)
    {
        if (intervals_[0].IsOverlap(interval))
        {
            intervals_[0] = intervals_[0].Union(interval);
        }
        else
        {
            intervals_.emplace_back(interval);
        }
        return *this;
    }

    auto it = intervals_.begin();
    Interval unioned{};

    for (; it != intervals_.end(); it++)
    {
        unioned = (*it).Union(interval);
        if (unioned != Interval::kEmptyInterval)
        {
            break;
        }
    }
    if (unioned != Interval::kEmptyInterval)
    {
        std::swap(*it, unioned);
    }
    else
    {
        intervals_.emplace_back(interval);
    }

    RemoveOverlappedInterval();

    return *this;
}

bool ContinuousSet::operator==(const Interval &interval) const
{
    if (intervals_.size() != 1)
    {
        return false;
    }

    return intervals_.at(0) == interval;
}

void ContinuousSet::RemoveOverlappedInterval()
{
    auto first = intervals_.begin();
    auto second = first + 1;
    std::vector<Interval> result{};
    for (; second != intervals_.end(); first++, second++)
    {
        Interval interval(*first);
        if ((*first).IsOverlap(*second))
        {
            interval = (*first).Union(*second);
            first++, second++;
        }
        result.emplace_back(interval);
        if (second == intervals_.end())
        {
            break;
        }
    }
    std::swap(intervals_, result);
}

std::ostream &operator<<(std::ostream &os, const ContinuousSet &continuous_set)
{
    os << "{";
    for (const auto &elm : continuous_set.intervals_)
    {
        os << elm << " ";
    }
    os << "}";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Interval &interval)
{
    os << "<" << interval.from_ << ", " << interval.to_ << ">";
    return os;
}
} // namespace design_pattern::etc::interval
