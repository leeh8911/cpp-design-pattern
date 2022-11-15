/// @file visitor.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// [refactoring.guru/visitor](https://refactoring.guru/ko/design-patterns/visitor)
/// @version 0.1
/// @date 2022-11-10
///
/// @copyright Copyright (c) 2022
///
//
#ifndef SRC_BEHAVIOR_VISITOR_VISITOR_H_
#define SRC_BEHAVIOR_VISITOR_VISITOR_H_

#include <memory>
#include <string>
#include <utility>

namespace design_pattern::behavior::visitor {

struct Visitor;

/// @brief Interface of Elements
struct Element {
    Element() = default;
    virtual ~Element() = default;
    virtual void Accept(const std::shared_ptr<Visitor> &visitor) = 0;
    virtual bool IsVisited() = 0;
    virtual void Invoke(std::string command) = 0;
    virtual std::string PrintCommand() = 0;
};

class ConcreteElementA : public Element {
 public:
    void Accept(const std::shared_ptr<Visitor> &visitor) override;
    bool IsVisited() override;
    void Invoke(std::string command) override;
    std::string PrintCommand() override;

 private:
    bool visited_{};
    std::string command_{};
};
class ConcreteElementB : public Element {
 public:
    void Accept(const std::shared_ptr<Visitor> &visitor) override;
    bool IsVisited() override;
    void Invoke(std::string command) override;
    std::string PrintCommand() override;

 private:
    bool visited_{};
    std::string command_{};
};

/// @brief Interface of Visitors
struct Visitor {
    virtual ~Visitor() = default;
    virtual std::size_t Count() const = 0;
    virtual void VisitA(ConcreteElementA &A) = 0;
    virtual void VisitB(ConcreteElementB &B) = 0;
};

class ConcreteVisitor : public Visitor {
 public:
    ConcreteVisitor() = default;
    ConcreteVisitor(const ConcreteVisitor &other) = default;
    std::size_t Count() const override;
    void VisitA(ConcreteElementA &A) override;
    void VisitB(ConcreteElementB &B) override;

 private:
    std::size_t count_{};
};

}  // namespace design_pattern::behavior::visitor
#endif  // SRC_BEHAVIOR_VISITOR_VISITOR_H_
