#include <gtest/gtest.h>

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

#ifndef TEST_ALL
    ::testing::GTEST_FLAG(filter) = "TemplateMethodTest*";
#endif
    return RUN_ALL_TESTS();
}