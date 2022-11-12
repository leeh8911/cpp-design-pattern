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
#include <memory>
#include <vector>

namespace design_pattern::etc::interval
{
// forward declaration
struct InterfaceInterval;
using InterfaceIntervalPtr = std::unique_ptr<InterfaceInterval>;
class Interval;
using IntervalPtr = std::unique_ptr<Interval>;

struct InterfaceInterval
{
    virtual ~InterfaceInterval() = default;

    virtual bool IsIncluded(double) const = 0;
    virtual bool IsOverlap(const InterfaceInterval &other) const = 0;
    virtual bool operator==(const InterfaceInterval &other) const = 0;
    virtual bool operator!=(const InterfaceInterval &other) const = 0;
    virtual const InterfaceInterval &&Intersect(const InterfaceInterval &other) const = 0;

    friend std::ostream &operator<<(std::ostream &os, const InterfaceInterval &interface_interval);
};

class Interval : public InterfaceInterval
{
  public:
    Interval(double from, double to);
    explicit Interval(const std::array<double, 2> &arr);
    Interval(const Interval &other) = delete;
    Interval(const Interval &&other);
    Interval &operator=(const Interval &other) = delete;
    Interval &operator=(const Interval &&other);

    bool IsIncluded(double value) const override;
    bool IsOverlap(const InterfaceInterval &other) const override;
    bool operator==(const InterfaceInterval &other) const override;
    bool operator!=(const InterfaceInterval &other) const override;
    const InterfaceInterval &&Intersect(const InterfaceInterval &other) const override;

    bool IsOverlap(const Interval &other) const;
    bool operator==(const Interval &other) const;
    bool operator!=(const Interval &other) const;

    const Interval &&Intersect(const Interval &other) const;

    friend std::ostream &operator<<(std::ostream &os, const Interval &interval);

  private:
    double from_{};
    double to_{};
};

class CompositeInterval : public InterfaceInterval
{
  public:
    CompositeInterval() = default;
    CompositeInterval(const CompositeInterval &other) = delete;
    CompositeInterval(CompositeInterval &&other);
    CompositeInterval &operator=(const CompositeInterval &other) = delete;
    CompositeInterval &operator=(CompositeInterval &&other);

    bool IsIncluded(double) const override;
    bool IsOverlap(const InterfaceInterval &other) const override;
    bool operator==(const InterfaceInterval &other) const override;
    bool operator!=(const InterfaceInterval &other) const override;
    const InterfaceInterval &&Intersect(const InterfaceInterval &other) const override;

    void AddInterval(InterfaceIntervalPtr other);
    void RemoveInterval(const InterfaceInterval &other);

    friend std::ostream &operator<<(std::ostream &os, const CompositeInterval &composite_interval);

  private:
    std::vector<InterfaceIntervalPtr> composite_{};
};
} // namespace design_pattern::etc::interval
#endif // SRC_ETC_INTERVAL_INTERVAL_H_
