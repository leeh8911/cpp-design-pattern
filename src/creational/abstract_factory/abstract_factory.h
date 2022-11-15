/**
 * @file abstract_factory.h
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief 추상 팩토리 컨셉을 정리하기 위한 헤더파일입니다.
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef SRC_CREATIONAL_ABSTRACT_FACTORY_ABSTRACT_FACTORY_H_
#define SRC_CREATIONAL_ABSTRACT_FACTORY_ABSTRACT_FACTORY_H_

#include <iostream>
#include <memory>
#include <string>
#include <utility>

namespace design_pattern::creational::abstract_factory {
struct IProduct {
    virtual ~IProduct() = default;
};

class ConcreteProductA : public IProduct {
   public:
    ConcreteProductA() { std::cout << "Construct concrete product A instance" << std::endl; }
    ~ConcreteProductA() override {
        std::cout << "Destruct concrete product A instance" << std::endl;
    }
};

class ConcreteProductB : public IProduct {
   public:
    ConcreteProductB() { std::cout << "Construct concrete product B instance" << std::endl; }
    ~ConcreteProductB() override {
        std::cout << "Destruct concrete product B instance" << std::endl;
    }
};

struct AbstractFactory {
   public:
    virtual ~AbstractFactory() = default;
    virtual std::unique_ptr<IProduct> CreateProduct() = 0;
};

class FactoryA : public AbstractFactory {
   public:
    std::unique_ptr<IProduct> CreateProduct() override {
        return std::make_unique<IProduct>(ConcreteProductA());
    }
};

class FactoryB : public AbstractFactory {
   public:
    std::unique_ptr<IProduct> CreateProduct() override {
        return std::make_unique<IProduct>(ConcreteProductB());
    }
};

}  // namespace design_pattern::creational::abstract_factory
#endif  // SRC_CREATIONAL_ABSTRACT_FACTORY_ABSTRACT_FACTORY_H_