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
#include <memory>

namespace design_pattern::etc::object
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
    virtual Vector2D Shape() const = 0;
    virtual double Rotation() const = 0;
    virtual void Position(const Vector2D &src) = 0;
    virtual void Velocity(const Vector2D &src) = 0;
    virtual void Shape(const Vector2D &src) = 0;
    virtual void Rotation(double src) = 0;

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
    Object(const Object &other);
    ~Object() override;

    // TODO: 중복된 함수들을 제거해야 함
    Vector2D Position() const override;
    Vector2D Velocity() const override;
    Vector2D Shape() const override;
    double Rotation() const override;
    void Position(const Vector2D &src) override;
    void Velocity(const Vector2D &src) override;
    void Shape(const Vector2D &src) override;
    void Rotation(double src) override;

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
class BoxObject : public IObject
{
  public:
    BoxObject();
    BoxObject(Vector2D position, Vector2D velocity, Vector2D shape, double rotation);
    BoxObject(const BoxObject &other);
    ~BoxObject() override = default;

    Vector2D Position() const override;
    Vector2D Velocity() const override;
    Vector2D Shape() const override;
    double Rotation() const override;
    void Position(const Vector2D &src) override;
    void Velocity(const Vector2D &src) override;
    void Shape(const Vector2D &src) override;
    void Rotation(double src) override;

    std::size_t AliveCount() const override;

    void Assignment(IObjectPtr meas) override;
    bool Update() override;

    bool HasMeasurement() const override;

  protected:
    bool UpdateByMeas(BoxObjectPtr meas);
    Vector2D position_;
    Vector2D velocity_;
    Vector2D shape_;
    double rotation_;
    std::size_t alive_count_;
    IObjectPtr meas_;
};

} // namespace design_pattern::etc::object
#endif // SRC_ETC_OBJECT_OBJECT_H_