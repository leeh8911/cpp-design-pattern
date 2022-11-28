/// @file pretty_function.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-28
///
/// @copyright Copyright (c) 2022
///
///
//

#ifndef TEST_UTILS_PRETTY_FUNCTION_H_
#define TEST_UTILS_PRETTY_FUNCTION_H_
namespace design_pattern::test::utils {

#ifdef _MSC_VER
#define _FUNCTION_INFO __FUNCDNAME__
#elif __GNUC__
#define _FUNCTION_INFO __PRETTY_FUNCTION__
#else

#endif

}  // namespace design_pattern::test::utils
#endif  // TEST_UTILS_PRETTY_FUNCTION_H_
