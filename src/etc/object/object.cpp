/// @file object.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-10-30
///
/// @copyright Copyright (c) 2022
///

#include "src/etc/object/object.h"

#include <memory>
#include <utility>

namespace design_pattern::etc::object
{
} // namespace design_pattern::etc::object

namespace design_pattern::etc::object
{
namespace entity
{
template <class T> bool Identifiable<T>::operator==(Identifiable &&other)
{
    return true;
}

Object::Object(const data::ObjectData &data) : data_(data)
{
}

bool Object::operator==(const data::ObjectData &other) const
{
    return Id() == data_.id;
}

std::size_t Object::Id() const
{
    return data_.id;
}
} // namespace entity
} // namespace design_pattern::etc::object