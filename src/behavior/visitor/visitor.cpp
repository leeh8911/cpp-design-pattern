/// @file visitor.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-10
///
/// @copyright Copyright (c) 2022
///
//

#include "src/behavior/visitor/visitor.h"

#include <iostream>
#include <memory>
#include <string>
#include <utility>

namespace design_pattern::behavior::visitor {
std::size_t ConcreteVisitor::Count() const { return count_; }

void ConcreteElementA::Invoke(std::string command) { command_ = command; }
std::string ConcreteElementA::PrintCommand() { return command_; }

void ConcreteElementB::Invoke(std::string command) { command_ = command; }
std::string ConcreteElementB::PrintCommand() { return command_; }

void ConcreteVisitor::VisitA(ConcreteElementA &A) {
    A.Invoke("invoke");
    count_ += 1;
}

void ConcreteVisitor::VisitB(ConcreteElementB &B) {
    B.Invoke("invoke");
    count_ += 1;
}

void ConcreteElementA::Accept(const std::shared_ptr<Visitor> &visitor) {
    visitor->VisitA(*this);
    visited_ = true;
}

bool ConcreteElementA::IsVisited() { return visited_; }

void ConcreteElementB::Accept(const std::shared_ptr<Visitor> &visitor) {
    visitor->VisitB(*this);
    visited_ = true;
}

bool ConcreteElementB::IsVisited() { return visited_; }

}  // namespace design_pattern::behavior::visitor
