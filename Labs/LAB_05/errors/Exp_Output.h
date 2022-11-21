//
// Created by Alexandr on 11/21/2022.
//

#ifndef LABS_LAB_05_ERRORS_EXP_OUTPUT_H_
#define LABS_LAB_05_ERRORS_EXP_OUTPUT_H_

#include "Exp.h"
class Exp_Output : public Exp{
 private:
  std::string detailed_error;
 public:
  Exp_Output(int, std::string);
  std::string output_detailed_error();
  std::string show() override;
};

#endif //LABS_LAB_05_ERRORS_EXP_OUTPUT_H_
