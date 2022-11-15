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

using namespace design_pattern::behavior::visitor;  // NOLINT

namespace {

TEST(VisitorTest, Sample) {
    std::vector<std::unique_ptr<Element>> element_vector{};
    element_vector.emplace_back(std::make_unique<ConcreteElementA>());
    element_vector.emplace_back(std::make_unique<ConcreteElementB>());

    auto visitor = std::make_shared<ConcreteVisitor>();
    EXPECT_EQ(visitor->Count(), 0);
    for (auto &elm : element_vector) {
        elm->Accept(visitor);

        EXPECT_TRUE(elm->IsVisited());
        EXPECT_EQ(elm->PrintCommand(), "invoke");
    }
    EXPECT_EQ(visitor->Count(), element_vector.size());
}
}  // namespace
