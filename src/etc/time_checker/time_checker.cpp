/// @file time_checker.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-27
///
/// @copyright Copyright (c) 2022
///
///

#include "src/etc/time_checker/time_checker.h"

#include <chrono>
#include <iostream>
#include <string>
#include <utility>

namespace design_pattern::etc::time_checker {
ElapseDataBase& ElapseDataBase::GetInstance() {
    static ElapseDataBase instance{};

    return instance;
}

Series<std::size_t>& ElapseDataBase::operator[](std::string name) { return db_[name]; }

std::list<std::string> ElapseDataBase::GetKeyList() {
    std::list<std::string> key_list{};

    for (const auto& elm : db_) {
        key_list.push_back(elm.first);
    }

    return key_list;
}

AutoElapseChecker::AutoElapseChecker(std::string name) : name_(std::move(name)), begin_(steady_clock::now()), end_() {}

AutoElapseChecker::~AutoElapseChecker() {
    end_ = steady_clock::now();
    auto& instance = ElapseDataBase::GetInstance();

    instance[name_].PushBack(std::chrono::duration_cast<ElapseTime>(end_ - begin_).count());
}

//'std::chrono::duration<long, std::ratio<1, 1000000>>::rep'
// duration<long, ratio<1, 1000000>>

}  // namespace design_pattern::etc::time_checker
