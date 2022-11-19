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
#include <string>
#include <vector>

namespace design_pattern::etc::interval {

// Forward declaration for IntervalPtr(using directive)
struct Interval;
using IntervalPtr = std::unique_ptr<Interval>;

struct Interval {
    Interval() = default;
    Interval(const Interval &) = default;
    Interval(Interval &&) = default;
    Interval &operator=(const Interval &) = default;
    Interval &operator=(Interval &&) = default;
    virtual ~Interval() = default;

    virtual bool IsIncluded(double value) const = 0;
    virtual bool IsOverlap(const Interval &other) const = 0;
    virtual bool IsEmpty() = 0;
    virtual bool operator==(const Interval &other) const = 0;
    virtual bool operator!=(const Interval &other) const = 0;
    virtual bool operator<(const Interval &other) const = 0;

    virtual IntervalPtr Intersect(IntervalPtr other) const = 0;
    virtual IntervalPtr Union(IntervalPtr other) const = 0;

    virtual std::string ToString() const = 0;
    friend std::ostream &operator<<(std::ostream &os, const Interval &interval);

    virtual double From() const = 0;
    virtual double To() const = 0;
};

class NumberInterval : public Interval {
 public:
    NumberInterval() = default;
    NumberInterval(double from, double to);
    NumberInterval(NumberInterval &&other);
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

    IntervalPtr Intersect(IntervalPtr other) const override;
    IntervalPtr Union(IntervalPtr other) const override;

    std::string ToString() const override;

    double From() const override;
    double To() const override;

 private:
    static const NumberInterval kEmptyInterval;

    double from_{std::numeric_limits<float>::max()};
    double to_{std::numeric_limits<float>::max()};
};
using NumberIntervalPtr = std::unique_ptr<NumberInterval>;

}  // namespace design_pattern::etc::interval
#endif  // SRC_ETC_INTERVAL_INTERVAL_H_
