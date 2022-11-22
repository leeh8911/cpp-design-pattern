/**
 * @file abstract_factory_test.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "src/creational/abstract_factory/abstract_factory.h"

#include <gtest/gtest.h>

namespace design_pattern::test {
using creational::abstract_factory::AbstractFactory;
using creational::abstract_factory::FactoryA;
using creational::abstract_factory::FactoryB;

TEST(AbstractFactoryTest, Sample) {
    AbstractFactory *factory_a = new FactoryA();
    AbstractFactory *factory_b = new FactoryB();

    auto product_a = factory_a->CreateProduct();
    auto product_b = factory_b->CreateProduct();

    EXPECT_EQ(1, 1);
}
}  // namespace design_pattern::test
