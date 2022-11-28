/// @file series.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-28
///
/// @copyright Copyright (c) 2022
///
///
//

#ifndef SRC_ETC_TIME_CHECKER_SERIES_H_
#define SRC_ETC_TIME_CHECKER_SERIES_H_

#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>

namespace design_pattern::etc::time_checker {
template <typename T>
class Series {
 public:
    Series() = default;
    Series(std::size_t size, T init_value) : data_(size, init_value) {}
    Series(const std::initializer_list<T>& init_list) : data_(init_list) {}

    void PushBack(T value) { data_.push_back(value); }
    T Back() const { return data_.back(); }
    std::size_t Size() const { return data_.size(); }

    double Mean() {
        int sum = std::accumulate(std::begin(data_), std::end(data_), 0);
        return static_cast<double>(sum) / data_.size();
    }

    double Variance() {
        double mean = Mean();

        double variance = std::transform_reduce(std::begin(data_), std::end(data_), 0.0, std::plus{},
                                                [mean](auto val) { return (val - mean) * (val - mean); });
        return variance;
    }

    double StandardDeviation() { return std::sqrt(Variance()); }

    std::size_t Min() { return std::min(data_); }
    std::size_t Max() { return std::max(data_); }

 private:
    std::vector<T> data_{};
};
}  // namespace design_pattern::etc::time_checker
#endif  // SRC_ETC_TIME_CHECKER_SERIES_H_
