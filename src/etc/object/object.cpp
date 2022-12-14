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

namespace design_pattern::etc::object {
Object::Object()
    : position_(Vector2D{}),
      velocity_(Vector2D{}),
      alive_count_(1),
      meas_(nullptr) {}

Object::Object(const Object &other)
    : position_(other.Position()),
      velocity_(other.Velocity()),
      alive_count_(other.AliveCount()),
      meas_(nullptr) {}

Object::Object(Vector2D position, Vector2D velocity)
    : position_(position),
      velocity_(velocity),
      alive_count_(1),
      meas_(nullptr) {}

Object::~Object() {
    IObjectPtr temp = nullptr;
    std::swap(meas_, temp);
}

Vector2D Object::Position() const { return position_; }
void Object::Position(const Vector2D &src) { position_ = src; }

Vector2D Object::Velocity() const { return velocity_; }
void Object::Velocity(const Vector2D &src) { velocity_ = src; }

Vector2D Object::Shape() const { return Vector2D{}; }
void Object::Shape(const Vector2D &) {}

double Object::Rotation() const { return 0.0; }
void Object::Rotation(double) {}

std::size_t Object::AliveCount() const { return alive_count_; }

void Object::Assignment(IObjectPtr meas) { std::swap(meas, meas_); }

bool Object::Update() {
    if (!HasMeasurement()) {
        return false;
    }

    auto meas =
        std::make_unique<Object>(*(dynamic_cast<Object *>(meas_.get())));
    IObjectPtr temp = nullptr;
    std::swap(meas_, temp);
    return UpdateByMeas(std::move(meas));
}

bool Object::HasMeasurement() const { return meas_ != nullptr; }

bool Object::UpdateByMeas(ObjectPtr meas) {
    alive_count_ += 1;
    Position(meas->Position());
    Velocity(meas->Velocity());

    ObjectPtr temp = nullptr;
    std::swap(meas, temp);

    return true;
}

Vector2D BoxObject::Position() const { return position_; }
void BoxObject::Position(const Vector2D &src) { position_ = src; }

Vector2D BoxObject::Velocity() const { return velocity_; }
void BoxObject::Velocity(const Vector2D &src) { velocity_ = src; }

Vector2D BoxObject::Shape() const { return shape_; }
double BoxObject::Rotation() const { return rotation_; }

void BoxObject::Shape(const Vector2D &src) { shape_ = src; }
void BoxObject::Rotation(double src) { rotation_ = src; }

std::size_t BoxObject::AliveCount() const { return alive_count_; }

bool BoxObject::Update() {
    if (!HasMeasurement()) {
        return false;
    }

    auto meas =
        std::make_unique<BoxObject>(*(dynamic_cast<BoxObject *>(meas_.get())));
    IObjectPtr temp = nullptr;
    std::swap(meas_, temp);
    return UpdateByMeas(std::move(meas));
}

void BoxObject::Assignment(IObjectPtr meas) { std::swap(meas, meas_); }

bool BoxObject::UpdateByMeas(BoxObjectPtr meas) {
    alive_count_ += 1;
    Position(meas->Position());
    Velocity(meas->Velocity());
    Shape(meas->Shape());
    Rotation(meas->Rotation());

    BoxObjectPtr temp = nullptr;
    std::swap(meas, temp);

    return true;
}

bool BoxObject::HasMeasurement() const { return meas_ != nullptr; }

BoxObject::BoxObject()
    : position_(Vector2D{}),
      velocity_(Vector2D{}),
      shape_(Vector2D{}),
      rotation_(0.0),
      alive_count_(1),
      meas_(nullptr) {}

BoxObject::BoxObject(Vector2D position, Vector2D velocity, Vector2D shape,
                     double rotation)
    : position_(position),
      velocity_(velocity),
      shape_(shape),
      rotation_(rotation),
      alive_count_(1),
      meas_(nullptr) {}
BoxObject::BoxObject(const BoxObject &other)
    : position_(other.Position()),
      velocity_(other.Velocity()),
      shape_(other.Shape()),
      rotation_(other.Rotation()),
      alive_count_(1),
      meas_(nullptr) {}

}  // namespace design_pattern::etc::object
