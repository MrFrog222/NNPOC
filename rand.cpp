#include "rand.h"
#include "bits/stdc++.h"

float randFloat(float min, float max) {
    std::default_random_engine gen;
    std::uniform_real_distribution<float> distrib(min, max);

    return distrib(gen);
}