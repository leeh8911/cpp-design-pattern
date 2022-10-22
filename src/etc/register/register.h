/**
 * @file register.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief apollo 에서 사용하는 register의 기능을 구현해보기 위한 헤더파일
 * @version 0.1
 * @date 2022-10-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SRC_ETC_REGISTER_REGISTER_H_
#define SRC_ETC_REGISTER_REGISTER_H_

#include <iostream>

namespace design_pattern::etc::apollo
{
class Any
{
 public:
    Any() : content_(NULL) {}

 private:
    class PlaceHolder
    {
     public
        virtual ~PlaceHolder() {}
    };
    PlaceHolder* content_;
};
}  // namespace design_pattern::etc::apollo

#endif  // SRC_ETC_REGISTER_REGISTER_H_