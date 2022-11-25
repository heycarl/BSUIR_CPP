//
// Created by Alexandr on 11/25/2022.
//

#include "uid_generator.h"
uidGenerator::UID uidGenerator::generate ()
{
  std::random_device rd;
  std::mt19937 mt (rd ());
  std::uniform_real_distribution<double> dist (1.0, std::numeric_limits<uint8_t>::max());
  return dist(mt);
}
