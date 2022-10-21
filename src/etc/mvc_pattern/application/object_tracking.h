/**
 * @file object_tracking.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief MVC 패턴을 객체 추적 애플리케이션(이하 객체 추적) 구현에 적용한
 * 예시입니다. 객체 추적은 센서로부터 환경 정보를 입력 받아, 내부에서 관리하고
 * 있는 타겟 정보를 업데이트하여 외부로 전송하는 애플리케이션입니다.
 * 객체 추적에 MVC 패턴을 적용한다면 다음과 같습니다. 외부 환경을 인지한 센서의
 * 입력 정보는 저장하는 곳은 Model 클래스가 됩니다. 입력 정보를 비즈니스 로직에
 * 해당하는 추적 알고리즘에 넣어주고 그 결과로 타겟 정보들을 받는 역할을
 * 수행하는 곳은 Controller 클래스가 됩니다. 마지막으로 컨트롤러에서 생성한 타겟
 * 정보를 객체 추적의 클라이언트에게 송출하는 역할은 View 클래스가 담당하게
 * 됩니다.
 * 각각의 Model, View, 그리고 Controller 클래스의 이름을 객체 추적에 맞게
 * 변경하면 순서대로 Input, Output, 그리고 Tracking에 해당하게 됩니다.
 * @version 0.1
 * @date 2022-10-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SRC_MVC_PATTERN_APPLICATION_OBJECT_TRACKING_H_
#define SRC_MVC_PATTERN_APPLICATION_OBJECT_TRACKING_H_

#include <vector>

#include "src/etc/mvc_pattern/application/input.h"
#include "src/etc/mvc_pattern/application/output.h"
#include "src/etc/mvc_pattern/application/tracking.h"

namespace design_pattern::etc::mvc::app
{
/**
 * @brief 객체 추적을 모사하기 위한 클래스입니다. 객체 추적의 세부 클래스인
 * Input, Output, 그리고 Tracking을 통합하는 역할을 수행합니다.
 *
 */
class ObjectTracking
{
 public:
    ObjectTracking();
    ~ObjectTracking();

    void InputSensor(const std::vector<Sensor>& sensor_vector);
    std::vector<Target> OutputTarget();

    size_t InputSize() const;
    size_t OutputSize() const;

    void Update();

 private:
    Input* input_;
    Output* output_;
    Tracking* tracking_;
};
}  // namespace design_pattern::etc::mvc::app
#endif  // SRC_MVC_PATTERN_APPLICATION_OBJECT_TRACKING_H_