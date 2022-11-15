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
#include <vector>

namespace design_pattern::etc::interval {
class Interval {
   public:
    Interval();
    Interval(double from, double to);
    Interval(const Interval &&other);
    Interval(const Interval &other);
    explicit Interval(const std::array<double, 2> &arr);
    Interval &operator=(const Interval &other) = default;
    Interval &operator=(Interval &&other);

    bool IsIncluded(double value) const;
    bool IsOverlap(const Interval &other) const;
    bool operator==(const Interval &other) const;
    bool operator!=(const Interval &other) const;

    Interval Intersect(const Interval &other) const;
    Interval Union(const Interval &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Interval &interval);
    static Interval kEmptyInterval;

   private:
    double from_{};
    double to_{};
};

class ContinuousSet {
   public:
    std::size_t Size() const;

    ContinuousSet &Union(const Interval &interval);
    ContinuousSet &Intersect(const Interval &interval);

    bool operator==(const Interval &interval) const;
    bool operator!=(const Interval &interval) const;
    bool operator==(const ContinuousSet &other) const;
    bool operator!=(const ContinuousSet &other) const;

    friend std::ostream &operator<<(std::ostream &os, const ContinuousSet &continuous_set);

   private:
    void RemoveOverlappedInterval();
    void Order();
    std::vector<Interval> intervals_{};
};

}  // namespace design_pattern::etc::interval
#endif  // SRC_ETC_INTERVAL_INTERVAL_H_
