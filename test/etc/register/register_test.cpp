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

class DerivedClass1 : BaseClass
{
 public:
    DerivedClass1() = default;
    ~DerivedClass1() = default;
    std::string Name() const override { return "DerivedClass1"; }
};

PERCEPTION_REGISTER_REGISTERER(BaseClass);
#define PERCEPTION_REGISTER_TEST(name) \
    PERCEPTION_REGISTER_CLASS(BaseClass, name)

PERCEPTION_REGISTER_TEST(DerivedClass1);

TEST(RegistererTest, Test)
{
    BaseClass* ptr = nullptr;
    ptr = BaseClassRegisterer::GetInstanceByName("DerivedClass1");
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
    EXPECT_FALSE(GetRegisteredClasses("BaseClass2", &derived_classes));
    EXPECT_EQ(derived_classes.size(), 1u);
    EXPECT_EQ(derived_classes[0], "DerivedClass1");
    ObjectFactoryDerivedClass1 obj_factory_drived1;
    obj_factory_drived1.NewInstance();
    Any any;
    // TODO(all) enable this check
    // EXPECT_EQ(any.content_, nullptr);
}
}  // namespace