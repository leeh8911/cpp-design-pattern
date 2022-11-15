/**
 * @file input.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief MVC 패턴에서 Model 클래스의 역할을 수행하는 Input 클래스입니다.
 * Input 클래스에서는 센서로부터 들어오는 입력 정보를 받아 저장하고, 필요한
 * 정보를 Tracking 클래스에 전달하는 역할을 수행합니다.
 * @version 0.1
 * @date 2022-10-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef SRC_MVC_PATTERN_APPLICATION_INPUT_H_
#define SRC_MVC_PATTERN_APPLICATION_INPUT_H_

#include <vector>

namespace design_pattern::etc::mvc::app {
/**
 * @brief 센서 입력 정보를 모사하기 위한 임시 구조체입니다. 실제 구현사항은 더
 * 복잡하겠지만, MVC 패턴을 설명하는데 불필요한 내용은 생략하였습니다.
 *
 */
struct Sensor {
    size_t id;
    bool operator==(const Sensor &other) const { return id == other.id; }
};

/**
 * @brief Input 클래스는 센서에서 전송한 정보들을 입력 받아 저장해주는 역할을
 * 수행합니다.
 *
 */
class Input {
 public:
    Input() = default;
    void Update(const std::vector<Sensor> &sensor_vector);
    const Sensor &GetItem(size_t idx) const;
    size_t Size() const;

 private:
    std::vector<Sensor> container_;
};

}  // namespace design_pattern::etc::mvc::app
#endif  // SRC_MVC_PATTERN_APPLICATION_INPUT_H_