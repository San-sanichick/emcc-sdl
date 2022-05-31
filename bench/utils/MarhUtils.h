#ifndef MATHUTILS_H
#define MATHUTILS_H

#include <stdint.h>
// #include <cstdlib>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

int64_t randomInRange(int64_t &min, int64_t &max) {
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(gen);
}

uint16_t randomInRange(uint16_t &min, uint16_t &max) {
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(gen);
}

int64_t randomInRange(int64_t &max) {
    std::uniform_int_distribution<> distribution(0, max);
    return distribution(gen);
}

uint16_t randomInRange(uint16_t &max) {
    std::uniform_int_distribution<> distribution(0, max);
    return distribution(gen);
}

int32_t randomInRange(int32_t min, int32_t max) {
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(gen);
}

#endif