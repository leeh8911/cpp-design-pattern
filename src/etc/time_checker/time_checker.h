/// @file time_checker.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-27
///
/// @copyright Copyright (c) 2022
///
///

#ifndef SRC_ETC_TIME_CHECKER_TIME_CHECKER_H_
#define SRC_ETC_TIME_CHECKER_TIME_CHECKER_H_

#include <chrono>
#include <deque>
#include <list>
#include <map>
#include <string>
#include <vector>

#include "src/etc/time_checker/series.h"

namespace design_pattern::etc::time_checker {

using ElapseTime = std::chrono::microseconds;

class ElapseDataBase {
 public:
    static ElapseDataBase& GetInstance();

    Series<std::size_t>& operator[](std::string name);

    std::list<std::string> GetKeyList();

 private:
    ElapseDataBase() = default;
    std::map<std::string, Series<std::size_t>> db_{};
};

class AutoElapseChecker {
 public:
    using steady_clock = std::chrono::steady_clock;
    using time_point = steady_clock::time_point;

    explicit AutoElapseChecker(std::string name);
    ~AutoElapseChecker();

 private:
    std::string name_{};
    time_point begin_{};
    time_point end_{};
};

}  // namespace design_pattern::etc::time_checker
#endif  // SRC_ETC_TIME_CHECKER_TIME_CHECKER_H_
