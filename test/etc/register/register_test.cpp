///
///@file register_test.cpp
///@author sangwon (leeh8911@gmail.com)
///@brief
///@version 0.1
///@date 2022-10-23
///
///@copyright Copyright (c) 2022
///

#include "src/etc/register/register.h"

#include <gtest/gtest.h>

#include <string>

namespace
{
using namespace design_pattern::etc::apollo;

class BaseClass
{
 public:
    BaseClass() = default;
    ~BaseClass() = default;
    virtual std::string Name() const { return "BaseClass1"; }
};

class DerivedClass : BaseClass
{
 public:
    DerivedClass() = default;
    ~DerivedClass() = default;
    std::string Name() const override { return "DerivedClass1"; }
};

TEST(RegistererTest, Test)
{
    BaseClass* ptr = nullptr;
    ptr = BaseClassRegisterer::GetInstanceByName("DerivedClass1")
        ASSERT_TRUE(ptr != nullptr);
    EXPECT_EQ(ptr->Name(), "DerivedClass1");

    ptr = BaseClassRegisterer::GetInstanceByName("NetExists");
    ASSERT_TRUE(ptr == nullptr);
    EXPECT_TRUE(BaseClassRegisterer::IsValid("DerivedClass1"));
    EXPECT_FALSE(BaseClassRegisterer::IsValid("NotExists"));
    EXPECT_EQ(BaseClassRegisterer::GetUniqInstanceName(), "DerivedClass1");

    BaseClass* ptr1 = BaseClassRegisterer::GetUniqInstance();
    EXPECT_NE(ptr1, nullptr);

    std::vector<std::string> derived_classes;
    EXPECT_TRUE(GetRegisteredClasses("BaseClass", &derived_classes));
}
}  // namespace