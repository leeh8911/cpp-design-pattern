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

namespace design_pattern::etc::interval
{
Interval::Interval(double from, double to) : from_(from), to_(to)
{
}

bool Interval::IsIncluded(double value)
{
    return ((from_ <= value) && (value <= to_));
}

} // namespace design_pattern::etc::interval
