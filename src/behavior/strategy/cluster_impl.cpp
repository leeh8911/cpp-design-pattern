/// @file cluster_impl.cpp
/// @author sangwon (leeh8911@gmail.com)
/// @brief
/// @version 0.1
/// @date 2022-11-24
///
/// @copyright Copyright (c) 2022
///
//

#include "src/behavior/strategy/cluster_impl.h"

#include <algorithm>
#include <limits>
#include <unordered_map>
#include <utility>

constexpr std::size_t UNDEFINED{0};
constexpr std::size_t NOISE{std::numeric_limits<std::size_t>::max()};

namespace design_pattern::behavior::strategy {
BasicCluster::BasicCluster(double distance_threshold) : distance_threshold_{distance_threshold} {}

std::vector<std::size_t> BasicCluster::Fit(const std::vector<Point>& data) {
    auto curr = data.begin();
    auto next = std::next(curr);

    std::vector<std::size_t> label{};

    label.emplace_back(1);

    while (next != data.end()) {
        double distance = Point::Distance(*curr, *next);

        if (distance < distance_threshold_) {
            label.emplace_back(label.back());
        } else {
            label.emplace_back(label.back() + 1);
        }

        curr = next;
        next = std::next(next);
    }
    return label;
}

DBSCAN::DBSCAN(double eps, std::size_t min_samples) : eps_(eps), min_samples_(min_samples) {}

std::vector<std::size_t> DBSCAN::Fit(const std::vector<Point>& data) {
    std::vector<std::size_t> label(data.size(), UNDEFINED);

    std::size_t C = 0;
    for (std::size_t idx = 0; idx < data.size(); ++idx) {
        if (label[idx] != UNDEFINED) {
            continue;
        }
        std::deque<std::size_t> seed_group = QueryInBoundSamples(data, eps_, data[idx]);

        if (seed_group.size() < min_samples_) {
            label[idx] = NOISE;
            continue;
        }

        C += 1;
        label[idx] = C;

        auto search = std::find(std::begin(seed_group), std::end(seed_group), idx);
        if (search != seed_group.end()) {
            seed_group.erase(search);
        }

        while (!seed_group.empty()) {
            auto seed = seed_group.front();
            seed_group.pop_front();

            if (label[seed] == NOISE) {
                label[seed] = C;
            }
            if (label[seed] != UNDEFINED) {
                continue;
            }
            label[seed] = C;
            std::deque<std::size_t> subseed = QueryInBoundSamples(data, eps_, data[seed]);
            if (subseed.size() >= min_samples_) {
                for (const auto& sub : subseed) {
                    seed_group.emplace_back(sub);
                }
            }
        }
    }

    return label;
}

std::deque<std::size_t> DBSCAN::QueryInBoundSamples(const std::vector<Point>& data, double eps, const Point& p) {
    std::deque<std::size_t> subgroup{};

    for (std::size_t idx = 0; idx < data.size(); ++idx) {
        if ((p - data[idx]).Norm2() < eps) {
            subgroup.emplace_back(idx);
        }
    }

    return subgroup;
}

}  // namespace design_pattern::behavior::strategy
