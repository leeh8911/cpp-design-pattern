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

namespace design_pattern::behavior::visitor
{
std::size_t ConcreteVisitor::Count() const
{
    return count_;
}

void ConcreteVisitor::VisitA(const ConcreteElementA &A)
{
}

void ConcreteVisitor::VisitB(const ConcreteElementB &B)
{
}

void ConcreteElementA::Accept(std::unique_ptr<Visitor> visitor)
{
}

bool ConcreteElementA::IsVisited()
{
    return visited_;
}

void ConcreteElementB::Accept(std::unique_ptr<Visitor> visitor)
{
}

bool ConcreteElementB::IsVisited()
{
    return visited_;
}

} // namespace design_pattern::behavior::visitor
