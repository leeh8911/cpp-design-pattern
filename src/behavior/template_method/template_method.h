/// @file template_method.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-10-30
///
/// @copyright Copyright (c) 2022
///

#ifndef SRC_BEHAVIOR_TEMPLATE_METHOD_TEMPLATE_METHOD_H_
#define SRC_BEHAVIOR_TEMPLATE_METHOD_TEMPLATE_METHOD_H_

#include <array>
#include <memory>

namespace design_pattern::behavior::template_method
{
constexpr double kPi = 3.14159265358979323846264338327950288;

using Vector2D = std::array<double, 2>;

struct IObject;
using IObjectPtr = std::unique_ptr<IObject>;
struct IObject
{
    virtual ~IObject() = default;

    virtual Vector2D Position() const = 0;
    virtual Vector2D Velocity() const = 0;
    virtual void Position(const Vector2D& src) = 0;
    virtual void Velocity(const Vector2D& src) = 0;

    virtual std::size_t AliveCount() const = 0;

    virtual void Assignment(IObjectPtr meas) = 0;
    virtual bool Update() = 0;

    virtual bool HasMeasurement() const = 0;
};

class Object;
using ObjectPtr = std::unique_ptr<Object>;
class Object : public IObject
{
 public:
    Object();
    Object(Vector2D position, Vector2D velocity);
    Object(const Object& other);
    ~Object() override;

    Vector2D Position() const override;
    Vector2D Velocity() const override;
    void Position(const Vector2D& src) override;
    void Velocity(const Vector2D& src) override;

    std::size_t AliveCount() const override;

    void Assignment(IObjectPtr meas) override;
    bool Update() override;

    bool HasMeasurement() const override;

 protected:
    bool UpdateByMeas(ObjectPtr meas);
    Vector2D position_;
    Vector2D velocity_;
    std::size_t alive_count_;
    IObjectPtr meas_;
};

class BoxObject;
using BoxObjectPtr = std::unique_ptr<BoxObject>;
class BoxObject : public Object
{
 public:
    BoxObject();
    BoxObject(Vector2D position, Vector2D velocity, Vector2D shape,
              double rotation);
    BoxObject(const BoxObject& other);
    ~BoxObject() override = default;

    virtual Vector2D Shape() const;
    virtual double Rotation() const;
    virtual void Shape(const Vector2D& src);
    virtual void Rotation(double src);

    bool Update() override;

 protected:
    bool UpdateByMeas(BoxObjectPtr meas);
    Vector2D shape_;
    double rotation_;
};

}  // namespace design_pattern::behavior::template_method
#endif  // SRC_BEHAVIOR_TEMPLATE_METHOD_TEMPLATE_METHOD_H_