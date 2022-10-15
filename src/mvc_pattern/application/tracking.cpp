/**
 * @file tracking.cpp
 * @author sangwon lee (leeh8911@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "src/mvc_pattern/application/tracking.h"

#include "src/mvc_pattern/application/input.h"
#include "src/mvc_pattern/application/output.h"

namespace design_pattern::mvc::app
{

void Tracker::Update(Input* input, Output* output)
{
    std::vector<Target> target_vector{};

    for (size_t idx = 0; idx < input->Size(); idx++)
    {
        Sensor s = input->GetItem(idx);
        target_vector.push_back(Target{s.id});
    }

    output->Update(target_vector);
}
Tracking::Tracking(Input* input, Output* output)
    : input_(input), output_(output), tracker_(nullptr)
{
    tracker_ = new Tracker;
}

Tracking::~Tracking() { delete tracker_; }

void Tracking::InputSensor(const std::vector<Sensor>& sensor_vector)
{
    input_->Update(sensor_vector);
}

void Tracking::Update() { tracker_->Update(input_, output_); }

std::vector<Target> Tracking::OutputTarget()
{
    std::vector<Target> target_vector;
    for (size_t idx = 0; idx < output_->Size(); idx++)
    {
        target_vector.push_back(output_->GetItem(idx));
    }
    return target_vector;
}

size_t Tracking::InputSize() const { return input_->Size(); }
size_t Tracking::OutputSize() const { return output_->Size(); }

}  // namespace design_pattern::mvc::app