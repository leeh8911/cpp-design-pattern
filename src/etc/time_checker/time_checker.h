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

namespace design_pattern::etc::time_checker {

using ElapseTime = std::chrono::microseconds;

class ElapseDataBase {
 public:
    static ElapseDataBase& GetInstance();

    void PushBack(std::string name, std::size_t time);
    std::size_t Back(std::string name);

    std::list<std::string> GetKeyList();

 private:
    ElapseDataBase() = default;
    std::map<std::string, std::deque<std::size_t>> db_{};
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
