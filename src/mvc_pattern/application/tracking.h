/**
 * @file tracking.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief MVC 패턴에서 Controller 클래스의 역할을 수행하는 Tracking
 * 클래스입니다. Tracking 클래스는 Input으로부터 입력 정보를 받아 비즈니스
 * 로직에 해당하는 Tracker에게 전달해주고, Tracker가 계산한 결과를 Output에게
 * 다시 전송해줍니다.
 * @version 0.1
 * @date 2022-10-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SRC_MVC_PATTERN_APPLICATION_TRACKING_H_
#define SRC_MVC_PATTERN_APPLICATION_TRACKING_H_

#include "src/mvc_pattern/application/input.h"
#include "src/mvc_pattern/application/output.h"

namespace design_pattern::mvc::app
{

/**
 * @brief 비즈니스 모델의 역할을 수행하는 Tracker 클래스입니다. 요구사항에 따라
 * 더 복잡한 기능을 수행하지만, MVC 모델 설명에 불필요한 내용은 생략하였습니다.
 *
 */
class Tracker
{
 public:
    void Update(Input* input, Output* output);
};

/**
 * @brief MVC 패턴에서 Controller 클래스의 역할을 수행하는 Tracking
 * 클래스입니다. Tracking 클래스는 Input으로부터 입력 정보를 받아 비즈니스
 * 로직에 해당하는 Tracker에게 전달해주고, Tracker가 계산한 결과를 Output에게
 * 다시 전송해줍니다.
 *
 */
class Tracking
{
 public:
    Tracking(Input* input, Output* output);
    ~Tracking();
    void InputSensor(const std::vector<Sensor>& sensor_vector);
    void Update();
    std::vector<Target> OutputTarget();

    size_t InputSize() const;
    size_t OutputSize() const;

 private:
    Input* input_;
    Output* output_;
    Tracker* tracker_;
};
}  // namespace design_pattern::mvc::app
#endif  // SRC_MVC_PATTERN_APPLICATION_TRACKING_H_