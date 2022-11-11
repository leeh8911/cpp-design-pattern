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
Interval::Interval(double from, double to) : from_(from), to_(to)
{
}

bool Interval::IsIncluded(double value) const
{
    double min_ = std::min(from_, to_);
    double max_ = std::max(from_, to_);
    return ((min_ <= value) && (value <= max_));
}

bool Interval::IsOverlap(const Interval &other) const
{
    return false;
}

} // namespace design_pattern::etc::interval
