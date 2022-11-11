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
namespace design_pattern::etc::interval
{
class Interval
{
  public:
    Interval(double from, double to);

    bool IsIncluded(double value) const;
    bool IsOverlap(const Interval &other) const;

  private:
    double from_{};
    double to_{};
};
} // namespace design_pattern::etc::interval
#endif // SRC_ETC_INTERVAL_INTERVAL_H_
