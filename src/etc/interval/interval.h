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
class InterfaceInterval;
class MultiInterval;
class SingleInterval;

class InterfaceInterval
{
  public:
    virtual ~InterfaceInterval() = default;

    virtual bool IsIncluded(double value) const = 0;
    virtual bool IsOverlap(const InterfaceInterval &other) const = 0;

    virtual bool Equal(const InterfaceInterval &other) const = 0;
    virtual bool NotEqual(const InterfaceInterval &other) const = 0;

    virtual InterfaceInterval &Intersect(const InterfaceInterval &other) const = 0;
    virtual InterfaceInterval &Union(const InterfaceInterval &other) const = 0;
    virtual InterfaceInterval &SetDiff(const InterfaceInterval &other) const = 0;
};

class SingleInterval : public InterfaceInterval
{
  public:
    SingleInterval(double from, double to);
    explicit SingleInterval(const std::array<double, 2> &arr);

    bool IsIncluded(double value) const override;
    bool IsOverlap(const InterfaceInterval &other) const override;

    bool Equal(const InterfaceInterval &other) const override;
    bool NotEqual(const InterfaceInterval &other) const override;

    InterfaceInterval &Intersect(const InterfaceInterval &other) const override;
    InterfaceInterval &Union(const InterfaceInterval &other) const override;
    InterfaceInterval &SetDiff(const InterfaceInterval &other) const override;

    bool IsOverlap(const SingleInterval &other) const;

    SingleInterval Intersect(const SingleInterval &other) const;

    friend std::ostream &operator<<(std::ostream &os, const SingleInterval &interval);

  private:
    double from_{};
    double to_{};
};

class MultiInterval : public InterfaceInterval
{
  public:
    MultiInterval() = default;
    MultiInterval(const MultiInterval &other);

    bool IsIncluded(double value) const override;
    bool IsOverlap(const InterfaceInterval &other) const override;

    bool Equal(const InterfaceInterval &other) const override;
    bool NotEqual(const InterfaceInterval &other) const override;

    InterfaceInterval &Intersect(const InterfaceInterval &other) const override;
    InterfaceInterval &Union(const InterfaceInterval &other) const override;
    InterfaceInterval &SetDiff(const InterfaceInterval &other) const override;

    void Append(const SingleInterval &single_interval);

  private:
    std::vector<std::shared_ptr<InterfaceInterval>> composite{};
};

class Interval
{
  public:
    Interval(double from, double to);
    explicit Interval(const InterfaceInterval &interval);

  private:
    std::unique_ptr<InterfaceInterval> pimpl;
};
} // namespace design_pattern::etc::interval
#endif // SRC_ETC_INTERVAL_INTERVAL_H_
