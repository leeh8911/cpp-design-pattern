/**
 * @file mvc_pattern_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "src/etc/mvc_pattern/mvc_pattern.h"

#include <gtest/gtest.h>

using namespace design_pattern::etc::mvc;

namespace design_pattern::test
{
class MvcPatternTest : public testing::Test
{
 public:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(MvcPatternTest, CreateModel)
{
    Model* student = new Model("Sangwon", "10");

    EXPECT_EQ(student->Property1(), "Sangwon");
    EXPECT_EQ(student->Property2(), "10");
}

TEST_F(MvcPatternTest, CreateController)
{
    Model* student = new Model("Sangwon", "10");
    View* view = new View();

    Controller* controller = new Controller(student, view);

    controller->UpdateView();

    controller->Property1("John");

    controller->UpdateView();
}

}  // namespace design_pattern::test
