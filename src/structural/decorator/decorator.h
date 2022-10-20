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
#include <pair>
#include <string>

namespace design_pattern::structural::decorator
{

class Shape
{
 public:
    virtual ~Shape() = default;
    virtual std::string name() const = 0;
};

class Circle : public Shape
{
    void Resize(float factor) { radius_ *= factor; }

    std::string name() const override{
        return std::string("A circle of radius " + std::to_string(radius_))};

    float radius_ = 10.0f;
};

class ColoredShape : public Shape
{
    ColoredShape(const std::string& color, Shape* shape)
        : color_(color), shape_(shape)
    {
    }

    std::string name() const override
    {
        return shape->name() + " which is colored " + color;
    }

    std::string color_;
    Shape* shape_;
};

class PunchedShape : public Shape
{
    PunchedShape(std::pair<float, float> position, Shape* shape)
        : position_(position), shape_(shape)
    {
    }

    std::string name() const override { return shape->name() + " punched " }
};

}  // namespace design_pattern::structural::decorator
#endif  // SRC_STRUCTURAL_DECORATOR_DECORATOR_H_