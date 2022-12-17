//
// Created by Alexandr on 10/13/2022.
//

#ifndef LABS_LAB_03_MONOBLOCK_MONOBLOCK_H_
#define LABS_LAB_03_MONOBLOCK_MONOBLOCK_H_

#include <fstream>

#include "../Desktop/Desktop.h"

class Monoblock : public Desktop {
 protected:
  double m_ScreenSize = 15;
 public:
  Monoblock() = default;
  Monoblock(double);
  double GetScreenSize() const;
  void SetScreenSize(double arg_screen_size);
  friend std::ofstream &operator<<(std::ofstream &out, Monoblock &o);
  friend std::ifstream &operator>>(std::ifstream &in, Monoblock &o);
};

#endif //LABS_LAB_03_MONOBLOCK_MONOBLOCK_H_
