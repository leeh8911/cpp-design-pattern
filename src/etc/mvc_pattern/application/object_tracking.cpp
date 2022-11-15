/**
 * @file object_tracking.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "src/etc/mvc_pattern/application/object_tracking.h"

#include "src/etc/mvc_pattern/application/input.h"
#include "src/etc/mvc_pattern/application/output.h"
#include "src/etc/mvc_pattern/application/tracking.h"

namespace design_pattern::etc::mvc::app {
ObjectTracking::ObjectTracking() {
    input_ = new Input;
    output_ = new Output;
    tracking_ = new Tracking(input_, output_);
}

ObjectTracking::~ObjectTracking() {
    delete input_;
    delete output_;
    delete tracking_;
}

void ObjectTracking::InputSensor(const std::vector<Sensor> &sensor_vector) {
    tracking_->InputSensor(sensor_vector);
}

std::vector<Target> ObjectTracking::OutputTarget() { return tracking_->OutputTarget(); }

size_t ObjectTracking::InputSize() const { return tracking_->InputSize(); }
size_t ObjectTracking::OutputSize() const { return tracking_->OutputSize(); }

void ObjectTracking::Update() { tracking_->Update(); }
}  // namespace design_pattern::etc::mvc::app