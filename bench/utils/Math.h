#pragma once

#include <stdint.h>
#include <random>

inline std::random_device rd;
inline std::mt19937 gen(rd());

inline int64_t randomInRange(int64_t &min, int64_t &max) {
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(gen);
}

inline uint16_t randomInRange(uint16_t &min, uint16_t &max) {
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(gen);
}

inline int64_t randomInRange(int64_t &max) {
    std::uniform_int_distribution<> distribution(0, max);
    return distribution(gen);
}

inline uint16_t randomInRange(uint16_t &max) {
    std::uniform_int_distribution<> distribution(0, max);
    return distribution(gen);
}

inline int32_t randomInRange(int32_t min, int32_t max) {
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(gen);
}