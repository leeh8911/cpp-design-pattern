///
///@file register.cpp
///@author sangwon (leeh8911@gmail.com)
///@brief
///@version 0.1
///@date 2022-10-24
///
///@copyright Copyright (c) 2022
///

#include "src/etc/register/register.h"

#include <iostream>
#include <string>
#include <vector>

namespace design_pattern::etc::apollo
{
BaseClassMap& GlobalFactoryMap()
{
    static BaseClassMap factory_map;
    return factory_map;
}

bool GetRegisteredClasses(
    const std::string& base_class_name,
    std::vector<std::string>* registered_derived_classes_names)
{
    if (registered_derived_classes_names == nullptr)
    {
        std::cout << "registered_derived_classes_names is not available";
        return false;
    }
    BaseClassMap& map1 = GlobalFactoryMap();
    auto iter = map1.find(base_class_name);
    if (iter == map1.end())
    {
        std::cout << "class not registered: " << base_class_name;
        return false;
    }
    for (const auto& pair : iter->second)
    {
        registered_derived_classes_names->push_back(pair.first);
    }
    return true;
}
}  // namespace design_pattern::etc::apollo