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

#include <chrono>
#include <deque>
#include <memory>
#include <string>

namespace design_pattern::behavior::memento
{
using Timepoint = std::chrono::time_point<std::chrono::system_clock>;

class IMemento
{
 public:
    IMemento() = default;
    IMemento(std::string state, Timepoint timestamp);
    virtual ~IMemento() = default;
    virtual std::string State() const = 0;
    virtual std::string Timestamp() const = 0;
    virtual Timepoint RawTimestamp() const = 0;
};

using IMementoPtr = std::unique_ptr<IMemento>;

class Memento : public IMemento
{
 public:
    Memento() = default;
    Memento(std::string state);
    Memento(std::string state, Timepoint timestamp);

    ~Memento() override = default;

    std::string State() const override;
    std::string Timestamp() const override;
    Timepoint RawTimestamp() const override;

 private:
    std::string state_;
    Timepoint timestamp_;
};

using MementoPtr = std::unique_ptr<Memento>;

class Originator : public Memento
{
 public:
    Originator() = default;
    explicit Originator(std::string state);

    MementoPtr Save() const;
    void Restore(IMementoPtr m);

    std::string State() const override;
    std::string Timestamp() const override;
    Timepoint RawTimestamp() const override;

 private:
    std::string state_;
    Timepoint timestamp_;
};

class Caretaker
{
 public:
    void Update(std::string state);
    std::string State() const;
    std::string Timestamp() const;
    void Undo();

 private:
    Originator originator_;
    std::deque<IMementoPtr> history;
};

}  // namespace design_pattern::behavior::memento
#endif  // SRC_BEHAVIOR_MEMENTO_MEMENTO_H_