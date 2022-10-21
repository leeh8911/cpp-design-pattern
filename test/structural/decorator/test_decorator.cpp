/**
 * @file test_decorator.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <gtest/gtest.h>

#include <iostream>

#include "src/structural/decorator/decorator.h"

namespace
{

using namespace design_pattern::structural::decorator;

TEST(DecoratorTest, Sample)
{
    Circle circle1;

    std::cout << circle1.Name() << std::endl;

    ColoredShape colored_circle("RED", &circle1);

    std::cout << colored_circle.Name() << std::endl;
}
}  // namespace
