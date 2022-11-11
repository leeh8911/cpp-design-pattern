/// @file interval.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-11
///
/// @copyright Copyright (c) 2022
///
//

#ifndef SRC_ETC_INTERVAL_INTERVAL_H_
#define SRC_ETC_INTERVAL_INTERVAL_H_

#include <array>
#include <iostream>

namespace design_pattern::etc::interval
{
class Interval
{
  public:
    Interval(double from, double to);
    Interval(const std::array<double, 2> &arr);
    Interval(const Interval &other);
    Interval &operator=(const Interval &other);
    Interval &Reverse();

    bool IsIncluded(double value) const;
    bool IsOverlap(const Interval &other) const;
    bool operator==(const Interval &other) const;
    bool operator!=(const Interval &other) const;

    Interval Intersect(const Interval &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Interval &interval);

  private:
    double from_{};
    double to_{};
    double min_{};
    double max_{};
};
} // namespace design_pattern::etc::interval
#endif // SRC_ETC_INTERVAL_INTERVAL_H_
