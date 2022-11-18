/// @file continuous_set.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-18
///
/// @copyright Copyright (c) 2022
///

#ifndef SRC_ETC_INTERVAL_CONTINUOUS_SET_H_
#define SRC_ETC_INTERVAL_CONTINUOUS_SET_H_

#include <iostream>
#include <vector>

#include "src/etc/interval/interval.h"

namespace design_pattern::etc::interval {

class ContinuousSet {
 public:
    std::size_t Size() const;

    ContinuousSet &Union(const Interval &interval);
    ContinuousSet &Intersect(const Interval &interval);

    bool operator==(const Interval &interval) const;
    bool operator!=(const Interval &interval) const;
    bool operator==(const ContinuousSet &other) const;
    bool operator!=(const ContinuousSet &other) const;

    friend std::ostream &operator<<(std::ostream &os,
                                    const ContinuousSet &continuous_set);

 private:
    ContinuousSet &Order();
    void RemoveOverlappedInterval();
    std::vector<Interval> intervals_{};
};
}  // namespace design_pattern::etc::interval
#endif  // SRC_ETC_INTERVAL_CONTINUOUS_SET_H_