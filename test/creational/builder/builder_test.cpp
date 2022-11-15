///
/// @file builder_test.cpp
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-10-18
///
/// @copyright Copyright (c) 2022
///
///

#include "src/creational/builder/builder.h"

#include <gtest/gtest.h>

namespace design_pattern::creational::builder::test {
class BuilderTest : public testing::Test {
 public:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(BuilderTest, Sample) {
    GTBuilder *builder = new GTBuilder();
    MountainBikeBuildDirector director(*builder);

    director.Construct();
    std::optional<Bicycle *> opt_bicycle = director.GetResult();

    EXPECT_EQ(opt_bicycle.has_value(), true);

    Bicycle *bicycle = opt_bicycle.value();
    EXPECT_EQ(bicycle->Height(), 29);
    EXPECT_EQ(bicycle->Color(), "Red");
    EXPECT_EQ(bicycle->Make(), "GT");
    EXPECT_EQ(bicycle->Model(), "Avalache");
}
}  // namespace design_pattern::creational::builder::test
