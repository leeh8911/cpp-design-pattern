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
class InterfaceInterval
{
  public:
    virtual ~InterfaceInterval() = default;

    virtual bool IsIncluded(double value) const = 0;
    virtual bool IsOverlap(const InterfaceInterval &other) const = 0;
    virtual bool operator==(const InterfaceInterval &other) const = 0;
    virtual bool operator!=(const InterfaceInterval &other) const = 0;

    virtual InterfaceInterval &Intersect(const InterfaceInterval &other) const = 0;
};

class SingleInterval : public InterfaceInterval
{
  public:
    SingleInterval(double from, double to);
    explicit SingleInterval(const std::array<double, 2> &arr);

    bool IsIncluded(double value) const override;
    bool IsOverlap(const InterfaceInterval &other) const override;
    bool operator==(const InterfaceInterval &other) const override;
    bool operator!=(const InterfaceInterval &other) const override;

    InterfaceInterval &Intersect(const InterfaceInterval &other) const override;

    bool IsOverlap(const SingleInterval &other) const;
    bool operator==(const SingleInterval &other) const;
    bool operator!=(const SingleInterval &other) const;

    SingleInterval Intersect(const SingleInterval &other) const;

    friend std::ostream &operator<<(std::ostream &os, const SingleInterval &interval);

  private:
    double from_{};
    double to_{};
};

class MultInterval : public InterfaceInterval
{
  public:
  private:
    std::vector<InterfaceInterval *> composite;
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
