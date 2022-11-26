//
// Created by Alexandr on 11/25/2022.
//

#include "uid_generator.h"
UID uidGenerator::generate ()
{
  std::random_device rd;
  std::mt19937 mt (rd ());
  std::uniform_int_distribution<UID> dist (1, std::numeric_limits<UID>::max());
  return dist(mt);
}
