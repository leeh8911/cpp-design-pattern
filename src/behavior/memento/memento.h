/// @file memento.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-10-27
///
/// @copyright Copyright (c) 2022
///

#ifndef SRC_BEHAVIOR_MEMENTO_MEMENTO_H_
#define SRC_BEHAVIOR_MEMENTO_MEMENTO_H_

#include <deque>
#include <string>

namespace design_pattern::behavior::memento
{
class Memento
{
 public:
    Memento() = default;
    virtual ~Memento() = default;
    explicit Memento(std::string state);
    virtual std::string State() const;

 private:
    std::string state_;
};

class Originator : public Memento
{
 public:
    Originator() = default;
    explicit Originator(std::string state);
    Memento Save() const;
    void Restore(const Memento m);
    std::string State() const override;

 private:
    std::string state_;
};

class Caretaker
{
 public:
    void Update(std::string state);
    std::string State() const;
    void Undo();

 private:
    Originator originator_;
    std::deque<Memento> history;
};

}  // namespace design_pattern::behavior::memento
#endif  // SRC_BEHAVIOR_MEMENTO_MEMENTO_H_