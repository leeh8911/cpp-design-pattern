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
};
} // namespace data

namespace entity
{
template <class T> class Identifiable
{
  public:
    Identifiable();

    // Identifiable class cannot copy
    Identifiable(const Identifiable &) = delete;
    Identifiable &operator=(const Identifiable &) = delete;

    bool operator==(Identifiable &&other);

  private:
    std::size_t id_;
    static std::map<std::size_t, Identifiable<T>> assigned;
};

class Object
{
  public:
    Object(const data::ObjectData &data);

    bool operator==(const data::ObjectData &other) const;

    std::size_t Id() const;

  private:
    data::ObjectData data_;
};
} // namespace entity

} // namespace design_pattern::etc::object
#endif // SRC_ETC_OBJECT_OBJECT_H_