/// @file visitor.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-10
///
/// @copyright Copyright (c) 2022
///
//
#ifndef SRC_BEHAVIOR_VISITOR_VISITOR_H_
#define SRC_BEHAVIOR_VISITOR_VISITOR_H_

#include <memory>
#include <utility>

namespace design_pattern::behavior::visitor
{

class Visitor
{
  public:
    virtual ~Visitor();
    virtual std::size_t Count() const = 0;
};

class Element
{
  public:
    virtual ~Element();
    virtual void Accept(std::unique_ptr<Visitor> visitor) = 0;
    virtual bool IsVisited() = 0;
};

class ConcreteElementA : public Element
{
  public:
    void Accept(std::unique_ptr<Visitor> visitor) override;
    bool IsVisited() override;

  private:
    bool visited_{};
};
class ConcreteElementB : public Element
{
  public:
    void Accept(std::unique_ptr<Visitor> visitor) override;
    bool IsVisited() override;

  private:
    bool visited_{};
};

class ConcreteVisitor : public Visitor
{
  public:
    ConcreteVisitor(const ConcreteVisitor &other) = default;
    std::size_t Count() const override;
    void VisitA(const ConcreteElementA &A);
    void VisitB(const ConcreteElementB &B);

  private:
    std::size_t count_{};
};

} // namespace design_pattern::behavior::visitor
#endif // SRC_BEHAVIOR_VISITOR_VISITOR_H_
