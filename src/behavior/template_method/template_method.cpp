/// @file template_method.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-10-30
///
/// @copyright Copyright (c) 2022
///

#include "src/behavior/template_method/template_method.h"

#include <memory>
#include <utility>

namespace design_pattern::behavior::template_method
{
Object::Object()
    : position_(Vector2D{}),
      velocity_(Vector2D{}),
      alive_count_(1),
      meas_(nullptr)
{
}

Object::~Object()
{
    ObjectPtr temp = nullptr;
    std::swap(meas_, temp);
}

Vector2D Object::Position() const { return position_; }
void Object::Position(const Vector2D& src) { position_ = src; }

Vector2D Object::Velocity() const { return velocity_; }
void Object::Velocity(const Vector2D& src) { velocity_ = src; }

std::size_t Object::AliveCount() const { return alive_count_; }

void Object::Assignment(ObjectPtr meas) { std::swap(meas, meas_); }
bool Object::Update()
{
    if (!HasMeasurement())
    {
        return false;
    }
    alive_count_ += 1;
    Position(meas_->Position());
    Velocity(meas_->Velocity());

    ObjectPtr temp = nullptr;
    std::swap(meas_, temp);

    return true;
}

bool Object::HasMeasurement() const { return meas_ != nullptr; }
}  // namespace design_pattern::behavior::template_method
