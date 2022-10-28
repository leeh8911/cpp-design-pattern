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

MementoPtr Originator::Save() const
{
    MementoPtr m = std::make_unique<Memento>(state_);
    return m;
}

void Originator::Restore(MementoPtr m) { state_ = m->State(); }

std::string Originator::State() const { return state_; }

std::string Caretaker::State() const { return originator_.State(); }

void Caretaker::Update(std::string state)
{
    MementoPtr m = originator_.Save();
    originator_ = Originator(state);
    history.emplace_back(std::move(m));
}

void Caretaker::Undo()
{
    MementoPtr m;
    std::swap(m, history[history.size() - 1]);
    history.pop_back();

    originator_.Restore(std::move(m));
}
}  // namespace design_pattern::behavior::memento
