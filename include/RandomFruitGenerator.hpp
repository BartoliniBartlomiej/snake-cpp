#pragma once

#include "FruitGenerator.hpp"

#include <random>

class RandomFruitGenerator : public FruitGenerator {
public:
    RandomFruitGenerator();

    Position generate(const Board&, const Snake& snake) override;

private:
    std::mt19937 generator_;
};