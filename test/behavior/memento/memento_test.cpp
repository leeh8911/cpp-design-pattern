/// @file memento_test.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-10-28
///
/// @copyright Copyright (c) 2022
///

#include "src/behavior/memento/memento.h"

#include <gtest/gtest.h>

#include <iostream>

namespace
{
using namespace design_pattern::behavior::memento;
TEST(MementoTest, Sample)
{
    Caretaker c;
    std::cout << c.State() << std::endl;
}

}  // namespace
