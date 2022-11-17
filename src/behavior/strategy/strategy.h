/// @file strategy.h
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-16
///
/// @copyright Copyright (c) 2022
///
//
#ifndef SRC_BEHAVIOR_STRATEGY_STRATEGY_H_
#define SRC_BEHAVIOR_STRATEGY_STRATEGY_H_
namespace design_pattern::behavior::strategy {

struct ITransportation {
    virtual ~ITransportation() = default;
    virtual double EstimateMoney() = 0;
    virtual double EstimateTime() = 0;
    virtual void Distance(double distance) = 0;
    virtual double Distance() const = 0;
    virtual double TimeDistanceRatio() const;
    virtual double MoneyDistanceRatio() const;
};

class Transportation : public ITransportation {
 public:
    void Distance(double distance) override;
    double Distance() const override;
    double EstimateMoney() override;
    double EstimateTime() override;

 private:
    double TimeDistanceRatio() const override;
    double MoneyDistanceRatio() const override;
    double distance_{};
    double time_distance_ratio{1.0};   // NOLINT
    double money_distance_ratio{1.0};  // NOLINT
};

class Car : public Transportation {
 public:
 private:
    double time_distance_ratio{0.25};  // NOLINT
    double money_distance_ratio{1.0};  // NOLINT
};

}  // namespace design_pattern::behavior::strategy
#endif  // SRC_BEHAVIOR_STRATEGY_STRATEGY_H_
