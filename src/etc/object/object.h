/// @file object.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-10-30
///
/// @copyright Copyright (c) 2022
///

#ifndef SRC_ETC_OBJECT_OBJECT_H_
#define SRC_ETC_OBJECT_OBJECT_H_

#include <array>
#include <map>
#include <memory>

namespace design_pattern::etc::object
{
constexpr double kPi = 3.14159265358979323846264338327950288;

namespace data
{
struct ObjectData
{
    std::size_t id;
    friend std::ostream &operator<<(std::ostream &os, const ObjectData &object_data);
};

} // namespace data

namespace entity
{

class Object
{
  public:
    Object(const data::ObjectData &data);

    bool operator==(const data::ObjectData &other) const;
    bool operator!=(const data::ObjectData &other) const;

    std::size_t Id() const;
    friend std::ostream &operator<<(std::ostream &os, const Object &object);

  private:
    data::ObjectData data_;
};
} // namespace entity

} // namespace design_pattern::etc::object
#endif // SRC_ETC_OBJECT_OBJECT_H_