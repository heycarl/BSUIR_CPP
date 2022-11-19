//
// Created by Alexandr on 11/19/2022.
//

#ifndef LABS_LAB_05_ERRORS_EXP_H_
#define LABS_LAB_05_ERRORS_EXP_H_

#include <iostream>

class Exp /* : std::exception */ {
 private:
  int code;
 private:
  std::string msg;
 public:
  Exp();
  Exp(int, std::string);
  Exp(const Exp&) = default;
  Exp& operator=(const Exp&) = default;
  Exp &operator<<(const std::string&);
  virtual std::string show();
  int GetCode();
};

#endif //LABS_LAB_05_ERRORS_EXP_H_
