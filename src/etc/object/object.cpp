/// @file object.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-10-30
///
/// @copyright Copyright (c) 2022
///

#include "src/etc/object/object.h"

#include <iostream>
#include <memory>
#include <utility>

namespace design_pattern::etc::object
{
} // namespace design_pattern::etc::object

namespace design_pattern::etc::object
{

namespace data
{
std::ostream &operator<<(std::ostream &os, const data::ObjectData &object_data)
{
    os << "Id(" << object_data.id << ")";
    return os;
}
} // namespace data
namespace entity
{

Object::Object(const data::ObjectData &data) : data_(data)
{
}

bool Object::operator==(const data::ObjectData &other) const
{
    std::cout << Id() << ", " << other.id << std::endl;
    return Id() == other.id;
}

bool Object::operator!=(const data::ObjectData &other) const
{
    return !(operator==(other));
}

std::size_t Object::Id() const
{
    return data_.id;
}

std::ostream &operator<<(std::ostream &os, const Object &object)
{
    os << "Id(" << object.data_.id << ")";
    return os;
}

} // namespace entity
} // namespace design_pattern::etc::object