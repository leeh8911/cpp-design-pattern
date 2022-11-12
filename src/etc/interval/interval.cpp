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
SingleInterval::SingleInterval(double from, double to) : from_{std::min(from, to)}, to_{std::max(from, to)}
{
}

SingleInterval::SingleInterval(const std::array<double, 2> &arr) : SingleInterval{arr[0], arr[1]}
{
}

bool SingleInterval::IsIncluded(double value) const
{
    return ((from_ <= value) && (value <= to_));
}

bool SingleInterval::IsOverlap(const InterfaceInterval &other) const
{
    return IsOverlap(dynamic_cast<const SingleInterval &>(other));
}

bool SingleInterval::IsOverlap(const SingleInterval &other) const
{
    return IsIncluded(other.from_) || IsIncluded(other.to_);
}

bool SingleInterval::operator==(const InterfaceInterval &other) const
{
    return operator==(dynamic_cast<const SingleInterval &>(other));
}

bool SingleInterval::operator==(const SingleInterval &other) const
{
    return ((from_ == other.from_) && (to_ == other.to_));
}

bool SingleInterval::operator!=(const InterfaceInterval &other) const
{
    return operator!=(dynamic_cast<const SingleInterval &>(other));
}

bool SingleInterval::operator!=(const SingleInterval &other) const
{
    return !(operator==(other));
}

InterfaceInterval &SingleInterval::Intersect(const InterfaceInterval &other) const
{
    auto result = Intersect(dynamic_cast<const SingleInterval &>(other));

    return *std::make_shared<SingleInterval>(result);
}

SingleInterval SingleInterval::Intersect(const SingleInterval &other) const
{
    double from{}, to{};
    if (!IsOverlap(other))
    {
        return SingleInterval{0.0, 0.0};
    }

    from = std::max(from_, other.from_);
    to = std::min(to_, other.to_);
    SingleInterval intersect{from, to};
    return intersect;
}

std::ostream &operator<<(std::ostream &os, const SingleInterval &interval)
{
    os << "<" << interval.from_ << ", " << interval.to_ << ">";
    return os;
}
} // namespace design_pattern::etc::interval
