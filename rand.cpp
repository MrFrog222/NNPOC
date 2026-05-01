#include "rand.h"
#include "bits/stdc++.h"

std::default_random_engine rand_gen;

float randFloat(float min, float max) {
    std::uniform_real_distribution<float> distrib(min, max);

    return distrib(rand_gen);
}
