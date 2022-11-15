/**
 * @file decorator.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-21
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SRC_STRUCTURAL_DECORATOR_DECORATOR_H_
#define SRC_STRUCTURAL_DECORATOR_DECORATOR_H_

#include <iostream>
#include <string>

namespace design_pattern::structural::decorator {
class Shape {
   public:
    Shape() = default;
    virtual ~Shape() = default;
    virtual std::string Name() const = 0;
};

class Circle : public Shape {
   public:
    void Resize(float factor) { radius_ *= factor; }

    std::string Name() const override {
        return std::string("A circle of radius " + std::to_string(radius_));
    };

   private:
    float radius_ = 10.0f;
};

class ColoredShape : public Shape {
   public:
    ColoredShape(const std::string &&color, Shape *shape) : color_(color), shape_(shape) {}

    std::string Name() const override { return shape_->Name() + " which is colored " + color_; }

   private:
    std::string color_;
    Shape *shape_;
};

class PunchedShape : public Shape {
   public:
    PunchedShape(const std::pair<float, float> &&position, Shape *shape)
        : position_(position), shape_(shape) {}

    std::string Name() const override { return shape_->Name() + " punched "; }

   private:
    std::pair<float, float> position_;
    Shape *shape_;
};

}  // namespace design_pattern::structural::decorator
#endif  // SRC_STRUCTURAL_DECORATOR_DECORATOR_H_