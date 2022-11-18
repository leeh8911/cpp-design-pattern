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
#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

namespace design_pattern::etc::interval {

struct Interval {
    virtual ~Interval() = default;

    virtual bool IsIncluded(double value) const;
    virtual bool IsOverlap(const Interval &other) const;
    virtual bool IsEmpty();
    virtual bool operator==(const Interval &other) const;
    virtual bool operator!=(const Interval &other) const;
    virtual bool operator<(const Interval &other) const;

    virtual Interval &Intersect(const Interval &other) const;
    virtual Interval &Union(const Interval &other) const;
};

using IntervalPtr = std::unique_ptr<Interval>;

class NumberInterval : public Interval {
 public:
    NumberInterval() = default;
    NumberInterval(double from, double to);
    NumberInterval(const NumberInterval &&other);
    NumberInterval(const NumberInterval &other);
    explicit NumberInterval(const std::array<double, 2> &arr);
    NumberInterval &operator=(const NumberInterval &other) = default;
    NumberInterval &operator=(NumberInterval &&other);

    bool IsIncluded(double value) const override;
    bool IsOverlap(const Interval &other) const override;
    bool IsEmpty() override;
    bool operator==(const Interval &other) const override;
    bool operator!=(const Interval &other) const override;
    bool operator<(const Interval &other) const override;

    Interval &Intersect(const Interval &other) const override;
    Interval &Union(const Interval &other) const override;

    friend std::ostream &operator<<(std::ostream &os,
                                    const NumberInterval &interval);

 private:
    static const NumberInterval kEmptyInterval;

    double from_{std::numeric_limits<float>::max()};
    double to_{std::numeric_limits<float>::max()};
};

}  // namespace design_pattern::etc::interval
#endif  // SRC_ETC_INTERVAL_INTERVAL_H_
