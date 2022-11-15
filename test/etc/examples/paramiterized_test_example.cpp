/// @file paramiterized_test_example.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-04
///
/// @copyright Copyright (c) 2022
///
//

#include <gtest/gtest.h>

namespace {
class ParameterizedTest : public testing::TestWithParam<
                              std::tuple<double, double, double, double>> {
 public:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_P(ParameterizedTest, Sample) {
    auto test_case = GetParam();
    EXPECT_EQ(0, 0);
}

INSTANTIATE_TEST_SUITE_P(
    ParameterizedObject, ParameterizedTest,
    testing::Combine(testing::Range(-1.0, 1.0), testing::Range(-1.0, 1.0),
                     testing::Range(-1.0, 1.0), testing::Range(-1.0, 1.0)),
    [](const testing::TestParamInfo<ParameterizedTest::ParamType> &info) {
        double pos0 = std::get<0>(info.param) + 1;
        double pos1 = std::get<1>(info.param) + 1;
        double vel0 = std::get<2>(info.param) + 1;
        double vel1 = std::get<3>(info.param) + 1;

        std::string dst = std::to_string(
            static_cast<int>(pos0 * 1000 + pos1 * 100 + vel0 * 10 + vel1));
        return dst;
    });
}  // namespace
