/// @file time_checker_test.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-27
///
/// @copyright Copyright (c) 2022
///
///

#include "src/etc/time_checker/time_checker.h"

#include <gtest/gtest.h>

#include "test/utils/pretty_function.h"

namespace design_pattern::etc::time_checker::test {

TEST(TestTimeChecker, ASampleCase) {
    auto helper = [](void) {
        AutoElapseChecker checker(_FUNCTION_INFO);
        for (std::size_t i = 0; i < 1000000; i++) {
        }
    };

    helper();

    ElapseDataBase& db_instance = ElapseDataBase::GetInstance();
    std::list<std::string> key_list = db_instance.GetKeyList();

    std::cout << key_list.back() << "\n";
    EXPECT_NE("", key_list.back());
    EXPECT_NE(0, (db_instance[key_list.back()].Back()));
}

TEST(TestTimeChecker, Elapse10TimesCase) {
    auto helper = [](void) {
        AutoElapseChecker checker(_FUNCTION_INFO);
        for (std::size_t i = 0; i < 1000000; i++) {
        }
    };

    for (std::size_t i = 0; i < 10; ++i) {
        helper();
    }

    ElapseDataBase& db_instance = ElapseDataBase::GetInstance();
    std::list<std::string> key_list = db_instance.GetKeyList();

    EXPECT_EQ(10, (db_instance[key_list.back()].Size()));
}
TEST(TestTimeChecker, Elapse10TimesCalculateMeanCase) {
    auto helper = [](void) {
        AutoElapseChecker checker(_FUNCTION_INFO);
        for (std::size_t i = 0; i < 1000000; i++) {
        }
    };

    for (std::size_t i = 0; i < 10; ++i) {
        helper();
    }

    ElapseDataBase& db_instance = ElapseDataBase::GetInstance();
    std::list<std::string> key_list = db_instance.GetKeyList();

    std::cout << (db_instance[key_list.back()].Mean()) << "\n";
    EXPECT_NE(0, (db_instance[key_list.back()].Mean()));
}
}  // namespace design_pattern::etc::time_checker::test
