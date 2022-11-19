/// @file builder.h
/// @author sangwon lee (leeh8911@gmail.com)
/// @brief 빌더 패턴
/// [wiki-builder-pattern](https://en.wikipedia.org/wiki/Builder_pattern)
/// 빌더 패턴은 객체 지향 프로그래밍에서 다양한 객체를 생성이 필요할 때 유연한
/// 필요한 유연한 솔루션입니다. 빌더 패턴의 의도는 복잡한 객체의 생성자를
/// 표현으로부터 분리하는 것 입니다.
/// \n
/// 여기서는 빌더 패턴의 예시를 알아보기 위해 4가지의 객체를 구성하였습니다. \n
/// Bicycle : 빌더 패턴을 사용해 생성하고자 하는 *복잡한 객체* \n
/// IBicycleBuilder : 빌더의 인터페이스 \n
/// GTBuilder : 구체적인 복합 객체 GTBike를 생성하기 위한 빌더 \n
/// MountainBikeBuildDirector : 구체적인 빌더를 감시하는 감독 \n
/// \n
/// NOTE: wiki 문서에서의 빌더 패턴에는 `Director` 클래스가 존재하는데, 왜
/// 필요한지 구체적인 의도를 잘 모르겠음
///
/// @version 0.1
/// @date 2022-10-18
///
/// @copyright Copyright (c) 2022
///

#ifndef SRC_CREATIONAL_BUILDER_BUILDER_H_
#define SRC_CREATIONAL_BUILDER_BUILDER_H_

#include <array>
#include <optional>
#include <string>

namespace design_pattern::creational::builder {

struct DefaultMountainBike {
    static constexpr int height_{29};
    std::string color_{"Red"};
    std::string maker_{"GT"};
    std::string model_{"Avalache"};
};
/**
 * @brief 빌더 패턴에서 사용하고자 하는 "복합 객체"로서 class Bicycle을
 * 사용합니다. 해당 예제에선 단순히 getter/setter를 통해 string과 int 정보만
 * 전달 받지만, 실전에서는 더욱 복잡한 방식의 파라미터를 갖게 됩니다.
 *
 */
class Bicycle {
 public:
    std::string Make() const { return make_; }
    void Make(std::string make) { make_ = make; }
    std::string Model() const { return model_; }
    void Model(std::string model) { model_ = model; }
    std::string Color() const { return color_; }
    void Color(std::string color) { color_ = color; }
    int Height() const { return height_; }
    void Height(int height) { height_ = height; }

 private:
    std::string make_;
    std::string model_;
    std::string color_;
    int height_{};
};

/**
 * @brief class Bicycle을 생성하기 위한 Builder들의 인터페이스 클래스입니다.
 *
 */
struct IBicycleBuilder {
    virtual ~IBicycleBuilder() = default;
    virtual std::string Color() const = 0;
    virtual void Color(std::string color) = 0;
    virtual int Height() const = 0;
    virtual void Height(int height) = 0;

    virtual std::optional<Bicycle *> GetResult() = 0;
};

/**
 * @brief "GTBike"를 생성하기 위한 빌더의 구현 클래스입니다.
 *
 */
class GTBuilder : public IBicycleBuilder {
 public:
    std::string Color() const override { return color_; }
    void Color(std::string color) override { color_ = color; }
    int Height() const override { return height_; }
    void Height(int height) override { height_ = height; }

    std::optional<Bicycle *> GetResult() override {
        DefaultMountainBike bike{};
        if (height_ == bike.height_) {
            Bicycle *res = new Bicycle;
            res->Make(bike.maker_);
            res->Model(bike.model_);
            res->Height(height_);
            res->Color(color_);

            return res;
        } else {
            return std::nullopt;
        }
    }

 private:
    std::string color_;
    int height_{};
};

/**
 * @brief Builder를 통해 직접 생성을 담당하는 Director 클래스 중 MountainBike를
 * 담당하는 클래스입니다.
 *
 */
class MountainBikeBuildDirector {
 public:
    MountainBikeBuildDirector() = delete;
    explicit MountainBikeBuildDirector(IBicycleBuilder &builder)
        : builder_(builder) {}

    void Construct() {
        DefaultMountainBike bike{};
        builder_.Color(bike.color_);
        builder_.Height(bike.height_);
    }
    std::optional<Bicycle *> GetResult() { return builder_.GetResult(); }

 private:
    IBicycleBuilder &builder_;
};
}  // namespace design_pattern::creational::builder
#endif  // SRC_CREATIONAL_BUILDER_BUILDER_H_
