/**
 * @file output.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief MVC 패턴에서 View 클래스의 역할을 수행하는 Output 클래스입니다. Output
 * 클래스는 Tracking으로부터 전달 받은 정보를 외부로 출력해주는 역할을
 * 수행합니다.
 * @version 0.1
 * @date 2022-10-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef SRC_ETC_MVC_PATTERN_APPLICATION_OUTPUT_H_
#define SRC_ETC_MVC_PATTERN_APPLICATION_OUTPUT_H_

#include <vector>

namespace design_pattern::etc::mvc::app {
/**
 * @brief 타겟 정보를 모사하기 위한 임시 구조체입니다. 실제 구현사항은 더
 * 복잡하겠지만, MVC 패턴을 설명하는데 불필요한 내용은 생략하였습니다.
 *
 */
struct Target {
    size_t id;

    bool operator==(const Target &other) const { return id == other.id; }
};

/**
 * @brief MVC 패턴에서 View 클래스의 역할을 수행하는 Output 클래스입니다. Output
 * 클래스는 Tracking으로부터 전달 받은 정보를 외부로 출력해주는 역할을
 * 수행합니다.
 *
 */
class Output {
 public:
    Output() = default;
    void Update(const std::vector<Target> &target_vector);
    Target GetItem(size_t idx) const;
    size_t Size() const;

 private:
    std::vector<Target> container_;
};
}  // namespace design_pattern::etc::mvc::app
#endif  // SRC_ETC_MVC_PATTERN_APPLICATION_OUTPUT_H_