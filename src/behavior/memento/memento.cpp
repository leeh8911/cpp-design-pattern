/// @file memento.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-10-27
///
/// @copyright Copyright (c) 2022
///

#include "src/behavior/memento/memento.h"

#include <chrono>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <utility>

namespace design_pattern::behavior::memento {
Memento::Memento(std::string state)
    : state_(std::move(state)), timestamp_(std::chrono::system_clock::now()) {}
Memento::Memento(std::string state, Timepoint timestamp)
    : state_(std::move(state)), timestamp_(timestamp) {}

std::string Memento::State() const { return state_; }

std::string Memento::Timestamp() const {
    std::time_t t_time = std::chrono::system_clock::to_time_t(timestamp_);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                  timestamp_.time_since_epoch()) %
              1000;
    std::tm tm_time = *std::localtime(&t_time);

    std::ostringstream oss;
    oss << std::put_time(&tm_time, "%F %T");
    oss << '.' << std::setfill('0') << std::setw(3) << ms.count();
    return oss.str();
}

Timepoint Memento::RawTimestamp() const { return timestamp_; }

Originator::Originator(std::string state)
    : state_(std::move(state)), timestamp_(std::chrono::system_clock::now()) {}

MementoPtr Originator::Save() const {
    MementoPtr m = std::make_unique<Memento>(state_, timestamp_);
    return m;
}

void Originator::Restore(IMementoPtr m) {
    state_ = m->State();
    timestamp_ = m->RawTimestamp();
}

std::string Originator::State() const { return state_; }

std::string Originator::Timestamp() const {
    std::time_t t_time = std::chrono::system_clock::to_time_t(timestamp_);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                  timestamp_.time_since_epoch()) %
              1000;
    std::tm tm_time = *std::localtime(&t_time);

    std::ostringstream oss;
    oss << std::put_time(&tm_time, "%F %T");
    oss << '.' << std::setfill('0') << std::setw(3) << ms.count();
    return oss.str();
}

Timepoint Originator::RawTimestamp() const { return timestamp_; }

std::string Caretaker::State() const { return originator_.State(); }
std::string Caretaker::Timestamp() const { return originator_.Timestamp(); }

void Caretaker::Update(std::string state) {
    IMementoPtr m = originator_.Save();
    originator_ = Originator(state);
    history.emplace_back(std::move(m));
}

void Caretaker::Undo() {
    IMementoPtr m = std::move(history.back());
    history.pop_back();

    originator_.Restore(std::move(m));
}
}  // namespace design_pattern::behavior::memento
