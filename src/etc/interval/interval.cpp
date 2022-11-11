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

#include "algorithm"

namespace design_pattern::etc::interval
{
Interval::Interval(double from, double to) : from_{from}, to_{to}, min_{std::min(from, to)}, max_{std::max(from, to)}
{
}

Interval::Interval(const std::array<double, 2> &arr) : Interval{arr[0], arr[1]}
{
}

Interval &Interval::Reverse()
{
    double temp = from_;
    from_ = to_;
    to_ = temp;

    return *this;
}

bool Interval::IsIncluded(double value) const
{
    return ((min_ <= value) && (value <= max_));
}

bool Interval::IsOverlap(const Interval &other) const
{
    return IsIncluded(other.from_) || IsIncluded(other.to_);
}

bool Interval::operator==(const Interval &other) const
{
    return true;
}

bool Interval::operator!=(const Interval &other) const
{
    return !operator==(other);
}

const Interval &Interval::Intersect(const Interval &other) const
{
    return *this;
}

} // namespace design_pattern::etc::interval
