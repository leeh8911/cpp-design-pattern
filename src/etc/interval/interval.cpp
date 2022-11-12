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

InterfaceInterval &SingleInterval::Union(const InterfaceInterval &other) const
{
    // TODO(leeh8911@gmail.com) : to be implemented
    auto temp = std::make_shared<SingleInterval>(dynamic_cast<const SingleInterval &>(other));
    temp = nullptr;
    auto result = std::make_shared<SingleInterval>(*this);
    return *result;
}

InterfaceInterval &SingleInterval::SetDiff(const InterfaceInterval &other) const
{
    // TODO(leeh8911@gmail.com) : to be implemented
    auto temp = std::make_shared<SingleInterval>(dynamic_cast<const SingleInterval &>(other));
    temp = nullptr;
    auto result = std::make_shared<SingleInterval>(*this);
    return *result;
}

MultInterval::MultInterval(const MultInterval &other)
{
    std::copy(other.composite.begin(), other.composite.end(), composite.begin());
}

bool MultInterval::IsIncluded(double value) const
{
    bool included = false;
    for (const auto &elm : composite)
    {
        included = elm->IsIncluded(value);
        if (included)
        {
            break;
        }
    }
    return included;
}

bool MultInterval::IsOverlap(const InterfaceInterval &other) const
{
    // TODO(leeh8911@gmail.com) : to be implemented
    auto temp = std::make_shared<MultInterval>(dynamic_cast<const MultInterval &>(other));
    temp = nullptr;
    return false;
}

bool MultInterval::operator==(const InterfaceInterval &other) const
{
    // TODO(leeh8911@gmail.com) : to be implemented
    auto temp = std::make_shared<MultInterval>(dynamic_cast<const MultInterval &>(other));
    temp = nullptr;
    return false;
}

bool MultInterval::operator!=(const InterfaceInterval &other) const
{
    // TODO(leeh8911@gmail.com) : to be implemented
    auto temp = std::make_shared<MultInterval>(dynamic_cast<const MultInterval &>(other));
    temp = nullptr;
    return false;
}

InterfaceInterval &MultInterval::Intersect(const InterfaceInterval &other) const
{
    // TODO(leeh8911@gmail.com) : to be implemented
    auto temp = std::make_shared<MultInterval>(dynamic_cast<const MultInterval &>(other));
    temp = nullptr;
    auto result = std::make_shared<MultInterval>(*this);
    return *result;
}

InterfaceInterval &MultInterval::Union(const InterfaceInterval &other) const
{
    // TODO(leeh8911@gmail.com) : to be implemented
    auto temp = std::make_shared<MultInterval>(dynamic_cast<const MultInterval &>(other));
    temp = nullptr;
    auto result = std::make_shared<MultInterval>(*this);
    return *result;
}

InterfaceInterval &MultInterval::SetDiff(const InterfaceInterval &other) const
{
    // TODO(leeh8911@gmail.com) : to be implemented
    auto temp = std::make_shared<MultInterval>(dynamic_cast<const MultInterval &>(other));
    temp = nullptr;
    auto result = std::make_shared<MultInterval>(*this);
    return *result;
}

void MultInterval::Append(const SingleInterval &single_interval)
{
    composite.emplace_back(std::make_shared<SingleInterval>(single_interval));
}

std::ostream &operator<<(std::ostream &os, const SingleInterval &interval)
{
    os << "<" << interval.from_ << ", " << interval.to_ << ">";
    return os;
}
} // namespace design_pattern::etc::interval
