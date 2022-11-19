//
// Created by Alexandr on 11/19/2022.
//

#ifndef LABS_LAB_05_ERRORS_EXP_INPUT_H_
#define LABS_LAB_05_ERRORS_EXP_INPUT_H_

#include "Exp.h"
class Exp_Input : public Exp{
//  Exp_Input(int, std::string);
 private:
  std::string exp_value;
 public:
  Exp_Input(int, std::string);
  std::string expected_value();
  std::string show() override;
};

#endif //LABS_LAB_05_ERRORS_EXP_INPUT_H_
