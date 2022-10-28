/// @file memento.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-10-27
///
/// @copyright Copyright (c) 2022
///

#include "src/behavior/memento/memento.h"

#include <deque>
#include <string>
#include <utility>

namespace design_pattern::behavior::memento
{
Memento::Memento(std::string state) : state_(std::move(state)) {}
std::string Memento::State() const { return state_; }

Originator::Originator(std::string state) : state_(std::move(state)) {}
Memento Originator::Save() const
{
    Memento m(state_);
    return m;
}
void Originator::Restore(const Memento m) { state_ = m.State(); }
std::string Originator::State() const { return state_; }

std::string Caretaker::State() const { return originator_.State(); }
void Caretaker::Update(std::string state)
{
    Memento m = originator_.Save();
    originator_ = Originator(state);
    history.emplace_back(m);
}
void Caretaker::Undo()
{
    Memento m = history.back();
    history.pop_back();

    originator_.Restore(m);
}
}  // namespace design_pattern::behavior::memento
