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
#include <utility>

namespace design_pattern::etc::interval
{
Interval::Interval(double from, double to) : from_{std::min(from, to)}, to_{std::max(from, to)}
{
}

Interval::Interval(const std::array<double, 2> &arr) : Interval{arr[0], arr[1]}
{
}

Interval::Interval(const Interval &&other) : Interval{other.from_, other.to_}
{
}

Interval &Interval::operator=(const Interval &&other)
{
    if (this != &other)
    {
        Interval temp(std::move(other));
        std::swap(*this, temp);
    }
    return *this;
}

bool Interval::IsIncluded(double value) const
{
    return ((from_ <= value) && (value <= to_));
}

bool Interval::IsOverlap(const InterfaceInterval &other) const
{
    return other.IsOverlap(*this);
}

bool Interval::IsOverlap(const Interval &other) const
{
    return IsIncluded(other.from_) || IsIncluded(other.to_);
}

bool Interval::operator==(const InterfaceInterval &other) const
{
    return other.operator==(*this);
}

bool Interval::operator==(const Interval &other) const
{
    return ((from_ == other.from_) && (to_ == other.to_));
}

bool Interval::operator!=(const InterfaceInterval &other) const
{
    return other.operator!=(*this);
}

bool Interval::operator!=(const Interval &other) const
{
    return !operator==(other);
}

const InterfaceInterval &&Interval::Intersect(const InterfaceInterval &other) const
{
    return other.Intersect(*this);
}

const Interval &&Interval::Intersect(const Interval &other) const
{
    double from{}, to{};
    if (!IsOverlap(other))
    {
        return std::move(Interval(0.0, 0.0));
    }

    from = std::max(from_, other.from_);
    to = std::min(to_, other.to_);
    return std::move(Interval(from, to));
}

std::ostream &operator<<(std::ostream &os, const Interval &interval)
{
    os << "<" << interval.from_ << ", " << interval.to_ << ">";
    return os;
}
} // namespace design_pattern::etc::interval
