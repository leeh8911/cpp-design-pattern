/**
 * @file mvc_pattern.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief Model-View-Control(MVC) pattern example. \n
 * MVC 패턴은 사용자 인터페이스로부터 비즈니스 로직을 분리하여, 애플리케이션의
 * 시각적 요소나 그 이면에서 실행되는 비즈니스 로직을 서로 영향없이 쉽게 고칠 수
 * 있는 애플리케이션을 구현할 수 있습니다. MVC에서 모델은 애플리케이션의
 * 정보(데이터)를 나타내며, 뷰는 텍스트, 체크박스 항목 등과 같은 인터페이스
 * 요소를 나타내고, 컨트롤러는 데이터와 비즈니스 로직 사이의 상호동작을
 * 관리합니다.
 *
 *
 * @version 0.1
 * @date 2022-10-14
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SRC_MVC_PATTERN_MVC_PATTERN_H_
#define SRC_MVC_PATTERN_MVC_PATTERN_H_

#include <iostream>
#include <string>
#include <utility>
#include <vector>

namespace design_pattern::etc::mvc
{
/**
 * @brief MVC 패턴에서의 Model 클래스입니다.
 * MVC 패턴에서 Model은 애플리케이션의 정보(데이터)를 의미합니다.
 * Model 클래스는 자신의 상태 변화가 있을 때, 컨트롤러와 뷰에 이를 통보합니다.
 *
 */
class Model
{
 public:
    Model(const std::string&& property1, const std::string&& property2)
        : property1_(property1), property2_(property2)
    {
    }

    void Property1(std::string property1) { property1_ = property1; }
    std::string Property1() const { return property1_; }

    void Property2(std::string property2) { property2_ = property2; }
    std::string Property2() const { return property2_; }

 private:
    std::string property1_;
    std::string property2_;
};

/**
 * @brief MVC 패턴에서의 View 클래스입니다.
 * View 클래스는 텍스트, 체크박스 항목 등과 같은 사용자 인터페이스 요소를
 * 나타냅니다. View 클래스는 사용자가 볼 결과물을 생성하기 위해 Model로부터
 * 정보를 획득합니다.
 *
 */
class View
{
 public:
    View() = default;
    void Print(std::pair<std::string, std::string> src)
    {
        std::cout << "--------------------------\n";
        std::cout << "Property1 : " << src.first << "\n";
        std::cout << "Property2 : " << src.second << "\n";
        std::cout << std::endl;
    }
};

/**
 * @brief MVC 패턴에서의 Controller 클래스입니다.
 * Controller 클래스는 데이터와 비즈니스 로직 사이의 상호 동작을 관리합니다.
 * Controller 클래스는  Model에 명령을 보냄으로써 Model의 상태를 변경할 수
 * 있습니다.
 *
 */
class Controller
{
 public:
    Controller(const Controller& other)
    {
        model_ = other.model_;
        view_ = other.view_;
    }
    Controller(Model* model, View* view) : model_(model), view_(view) {}

    void UpdateView()
    {
        std::string property1 = model_->Property1();
        std::string property2 = model_->Property2();
        std::pair<std::string, std::string> result{property1, property2};
        view_->Print(result);
    }

    void Property1(std::string property1) { model_->Property1(property1); }
    void Property2(std::string property2) { model_->Property2(property2); }

 private:
    Model* model_;
    View* view_;
};

}  // namespace design_pattern::etc::mvc
#endif  // SRC_MVC_PATTERN_MVC_PATTERN_H_