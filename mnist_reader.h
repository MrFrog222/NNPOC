#pragma once

#include <cstdint>
#include <fstream>
#include <vector>

typedef struct {
  std::vector<float> pixels;
  uint8_t label;
} Sample;

extern uint32_t readBigEndian(std::ifstream& file);
extern std::vector<Sample> loadMNIST(std::string& imagePath, std::string& labelPath);
