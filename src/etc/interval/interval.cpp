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
    std::cout << "From-To: " << from_ << ", " << to_ << std::endl;
}

Interval::Interval(const std::array<double, 2> &arr) : Interval{arr[0], arr[1]}
{
}

Interval::Interval(const Interval &&other) : Interval{other.from_, other.to_}
{
    std::cout << "Move constructor : " << other << std::endl;
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
    std::cout << "Call Construct on Intersect: " << std::endl;
    std::unique_ptr<Interval> result = nullptr;
    if (!IsOverlap(other))
    {
        Interval temp{0.0, 0.0};
        std::cout << temp;
        result = std::make_unique<Interval>(std::move(temp));
        return std::move(*result);
    }

    from = std::max(from_, other.from_);
    to = std::min(to_, other.to_);

    Interval temp{from, to};
    std::cout << temp;
    result = std::make_unique<Interval>(std::move(temp));
    return std::move(*result);
}

bool CompositeInterval::IsIncluded(double value) const
{
    bool included = false;
    for (const auto &elm : composite_)
    {
        included = elm->IsIncluded(value);
        if (included)
        {
            break;
        }
    }
    return included;
}

bool CompositeInterval::IsOverlap(const InterfaceInterval &other) const
{
    bool overlap{};
    for (const auto &elm : composite_)
    {
        overlap = elm->IsOverlap(other);
        if (overlap)
        {
            break;
        }
    }
    return overlap;
}

bool CompositeInterval::operator==(const InterfaceInterval &other) const
{
    other.IsIncluded(0.0);
    return false;
}

bool CompositeInterval::operator!=(const InterfaceInterval &other) const
{
    other.IsIncluded(0.0);
    return false;
}

const InterfaceInterval &&CompositeInterval::Intersect(const InterfaceInterval &other) const
{
    other.IsIncluded(0.0);
    return std::move(*this);
}

CompositeInterval::CompositeInterval(CompositeInterval &&other) : composite_{std::move(other.composite_)}
{
}

CompositeInterval &CompositeInterval::operator=(CompositeInterval &&other)
{
    if (this != &other)
    {
        auto temp(std::move(other));
        std::swap(*this, temp);
    }
    return *this;
}

void CompositeInterval::AddInterval(InterfaceIntervalPtr other)
{
    composite_.emplace_back(std::move(other));
}

void CompositeInterval::RemoveInterval(const InterfaceInterval &other)
{
    other.IsIncluded(0.0);
}

std::ostream &operator<<(std::ostream &os, const Interval &interval)
{
    os << "<" << interval.from_ << ", " << interval.to_ << ">";
    return os;
}

std::ostream &operator<<(std::ostream &os, const CompositeInterval &composite_interval)
{
    const auto &composite = composite_interval.composite_;
    for (const auto &elm : composite)
    {
        os << *(dynamic_cast<Interval *>(elm.get()));
    }
    return os;
}
} // namespace design_pattern::etc::interval
