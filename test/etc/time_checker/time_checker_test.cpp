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

namespace design_pattern::etc::time_checker::test {

TEST(TestTimeChecker, ASampleCase) {
    auto helper = [](void) {
        AutoElapseChecker checker(__FUNCTION__);
        for (std::size_t i = 0; i < 1000000; i++) {
        }
    };

    std::cout << "Call function\n";
    helper();

    std::cout << "Call database\n";
    ElapseDataBase& db_instance = ElapseDataBase::GetInstance();
    std::cout << "Get key list in database\n";
    std::list<std::string> key_list = db_instance.GetKeyList();

    std::cout << "Assertion\n";
    EXPECT_EQ("", key_list.back());
}
}  // namespace design_pattern::etc::time_checker::test
