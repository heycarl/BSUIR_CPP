//
// Created by Alexandr on 11/25/2022.
//

#ifndef _UID_GENERATOR_H_
#define _UID_GENERATOR_H_

#include <random>

typedef uint8_t UID;

class uid_generator {
 public:
  static UID generate();
};

#endif //_UID_GENERATOR_H_
