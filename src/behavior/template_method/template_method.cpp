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

Object::Object(const Object& other)
    : position_(other.Position()),
      velocity_(other.Velocity()),
      alive_count_(other.AliveCount()),
      meas_(nullptr)
{
}

Object::Object(Vector2D position, Vector2D velocity)
    : position_(position), velocity_(velocity), alive_count_(1), meas_(nullptr)
{
}

Object::~Object()
{
    IObjectPtr temp = nullptr;
    std::swap(meas_, temp);
}

Vector2D Object::Position() const { return position_; }
void Object::Position(const Vector2D& src) { position_ = src; }

Vector2D Object::Velocity() const { return velocity_; }
void Object::Velocity(const Vector2D& src) { velocity_ = src; }

std::size_t Object::AliveCount() const { return alive_count_; }

void Object::Assignment(IObjectPtr meas) { std::swap(meas, meas_); }
bool Object::Update()
{
    if (!HasMeasurement())
    {
        return false;
    }

    auto meas = std::make_unique<Object>(*(dynamic_cast<Object*>(meas_.get())));
    IObjectPtr temp = nullptr;
    std::swap(meas_, temp);
    return UpdateByMeas(std::move(meas));
}

bool Object::HasMeasurement() const { return meas_ != nullptr; }

bool Object::UpdateByMeas(ObjectPtr meas)
{
    alive_count_ += 1;
    Position(meas->Position());
    Velocity(meas->Velocity());

    ObjectPtr temp = nullptr;
    std::swap(meas, temp);

    return true;
}

Vector2D BoxObject::Shape() const { return shape_; }

double BoxObject::Rotation() const { return rotation_; }

void BoxObject::Shape(const Vector2D& src) { shape_ = src; }

void BoxObject::Rotation(double src) { rotation_ = src; }

bool BoxObject::Update()
{
    if (!HasMeasurement())
    {
        return false;
    }

    auto meas =
        std::make_unique<BoxObject>(*(dynamic_cast<BoxObject*>(meas_.get())));
    IObjectPtr temp = nullptr;
    std::swap(meas_, temp);
    return UpdateByMeas(std::move(meas));
}

bool BoxObject::UpdateByMeas(BoxObjectPtr meas)
{
    alive_count_ += 1;
    Position(meas->Position());
    Velocity(meas->Velocity());
    Shape(meas->Shape());
    Rotation(meas->Rotation());

    BoxObjectPtr temp = nullptr;
    std::swap(meas, temp);

    return true;
}

BoxObject::BoxObject() : Object(), shape_(Vector2D{}), rotation_(0.0) {}

BoxObject::BoxObject(Vector2D position, Vector2D velocity, Vector2D shape,
                     double rotation)
    : Object(position, velocity), shape_(shape), rotation_(rotation)
{
}
BoxObject::BoxObject(const BoxObject& other)
    : Object(other), shape_(other.Shape()), rotation_(other.Rotation())
{
}

}  // namespace design_pattern::behavior::template_method
