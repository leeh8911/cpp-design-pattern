/// @file visitor_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-10
///
/// @copyright Copyright (c) 2022
///
//
#include "src/behavior/visitor/visitor.h"

#include <gtest/gtest.h>

#include <memory>
#include <vector>

using namespace design_pattern::behavior::visitor; // NOLINT

namespace
{

TEST(VisitorTest, Sample)
{
    ConcreteVisitor visitor;

    ConcreteElementA A;
    ConcreteElementB B;

    std::vector<std::unique_ptr<Element>> v;
    v.emplace_back(std::make_unique<ConcreteElementA>());
    v.emplace_back(std::make_unique<ConcreteElementB>());

    EXPECT_TRUE(visitor.Count(), 0);
    for (auto *&elm : v)
    {
        elm.Accept(visitor);

        EXPECT_TRUE(elm.IsVisited());
    }
    EXPECT_TRUE(visitor.count(), v.size());
}
} // namespace
