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

    template <typename ValueType>
    explicit Any(const ValueType& value)
        : content_(new Holder<ValueType>(value))
    {
    }

    Any(const Any& other)
        : content_(other.content_ ? other.content_->Clone() : nullptr)
    {
    }

    template <typename ValueType>
    ValueType* AnyCast()
    {
        return content_ ? &(static_cast<Holder<ValueType>*>(content_)->held_)
                        : nullptr;
    }

 private:
    class PlaceHolder
    {
     public:
        virtual ~PlaceHolder() {}
        virtual PlaceHolder* Clone() const = 0;
    };

    template <typename ValueType>
    class Holder : public PlaceHolder
    {
     public:
        explicit Holder(const ValueType& value) : held_(value) {}
        virtual ~Holder() {}
        virtual PlaceHolder* Clone() const { return new Holder(held_); }

        ValueType held_;
    };
    PlaceHolder* content_;
};

class ObjectFactory
{
 public:
    ObjectFactory() {}
    virtual ~ObjectFactory() {}
    virtual Any NewInstance() { return Any(); }

    // 복사 생성자 및 복사 할당자 제거
    ObjectFactory(const ObjectFactory&) = delete;
    ObjectFactory& operator=(const ObjectFactory&) = delete;

 private:
}
}  // namespace design_pattern::etc::apollo

#endif  // SRC_ETC_REGISTER_REGISTER_H_