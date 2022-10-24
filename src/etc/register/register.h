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
#include <map>
#include <string>
#include <vector>

#define CHECK_EQ(a, b) std::cout << a << " != " << b

namespace design_pattern::etc::apollo
{
class Any
{
 public:
    Any() : content_(nullptr) {}

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
        virtual ~PlaceHolder() = default;
        virtual PlaceHolder* Clone() const = 0;
    };

    template <typename ValueType>
    class Holder : public PlaceHolder
    {
     public:
        explicit Holder(const ValueType& value) : held_(value) {}
        ~Holder() override = default;
        PlaceHolder* Clone() const override { return new Holder(held_); }

        ValueType held_;
    };
    PlaceHolder* content_;
};

class ObjectFactory
{
 public:
    ObjectFactory() = default;
    virtual ~ObjectFactory() = default;
    virtual Any NewInstance() { return Any(); }

    // 복사 생성자 및 복사 할당자 제거
    ObjectFactory(const ObjectFactory&) = delete;
    ObjectFactory& operator=(const ObjectFactory&) = delete;

 private:
};

typedef std::map<std::string, ObjectFactory*> FactoryMap;
typedef std::map<std::string, FactoryMap> BaseClassMap;
BaseClassMap& GlobalFactoryMap();

bool GetRegisteredClasses(
    const std::string& base_class_name,
    std::vector<std::string>* registered_derived_classes_names);

}  // namespace design_pattern::etc::apollo

#define PERCEPTION_REGISTER_REGISTERER(base_class)                      \
    class base_class##Registerer                                        \
    {                                                                   \
        typedef design_pattern::etc::apollo::Any Any;                   \
        typedef design_pattern::etc::apollo::FactoryMap FactoryMap;     \
        using GlobalFactoryMap =                                        \
            design_pattern::etc::apollo::GlobalFactoryMap;              \
                                                                        \
     public:                                                            \
        static base_class* GetInstanceByName(const ::std::string& name) \
        {                                                               \
            FactoryMap& map1 = GlobalFactoryMap()[#base_class];         \
            FactoryMap::iterator iter = map1.find(name);                \
            if (iter == map1.end())                                     \
            {                                                           \
                for (auto c : map1)                                     \
                {                                                       \
                    std::cout << "Instance: " << c.first << std::endl;  \
                }                                                       \
                std::cout << "Get instance " << name << " failed.\n";   \
                return nullptr;                                         \
            }                                                           \
            Any object = iter->second->NewInstance();                   \
            return *(object.AnyCast<base_class*>());                    \
        }                                                               \
        static std::vector<base_class*> GetAllInstance()                \
        {                                                               \
            std::vector<base_class*> instances;                         \
            FactoryMap& map1 = GlobalFactoryMap()[#base_class];         \
            instances.reverse(map1.begin(), map1.end());                \
            for (auto item : map1)                                      \
            {                                                           \
                Any object = item.second->NewInstance();                \
                instances.push_back(*(object.AnyCast<base_class*>()));  \
            }                                                           \
            return instances;                                           \
        }                                                               \
        static const ::std::string GetUniqInstanceName()                \
        {                                                               \
            FactoryMap& map1 = GlobalFactoryMap()[#base_class];         \
            CHECK_EQ(map1.size(), 1U) << map1.size();                   \
            return map1.begin()->first;                                 \
        }                                                               \
        static base_class* GetUniqInstance()                            \
        {                                                               \
            std::string name = #base_class;                             \
            FactoryMap* map1 = GlobalFactoryMap()[name];                \
            CHECK_EQ(map1.size(), 1U) << map1.size();                   \
            Any object = map1.begin()->second->NewInstance();           \
            return *(object.AnyCast<base_class*>());                    \
        }                                                               \
        static bool IsValid(const ::std::string& name)                  \
        {                                                               \
            FactoryMap& map1 = GlobalFactoryMap()[#base_class];         \
            return map1.find(name) != map1.end();                       \
        }                                                               \
    };
#define PERCEPTION_REGISTER_CLASS(clazz, name)                       \
    namespace                                                        \
    {                                                                \
    class ObjectFactory##name                                        \
        : public design_pattern::etc::apollo::ObjectFactory          \
    {                                                                \
     public:                                                         \
        virtual ~ObjectFactory##name() {}                            \
        virtual design_pattern::etc::apollo::Any NewInstance()       \
        {                                                            \
            return design_pattern::etc::apollo::Any(new name());     \
        }                                                            \
    };                                                               \
    __attribute__((constructor)) void RegisterFactory##name()        \
    {                                                                \
        design_pattern::etc::apollo::FactoryMap& map1 =              \
            design_pattern::etc::apollo::GlobalFactoryMap()[#clazz]; \
        if (map1.find(#name) == map1.end())                          \
            map1[#name] = new ObjectFactory##name();                 \
    }                                                                \
    }   // namespace
#endif  // SRC_ETC_REGISTER_REGISTER_H_