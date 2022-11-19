//
// Created by Alexandr on 11/19/2022.
//

#include "Exp.h"
Exp::Exp() {
  code = 1;
  msg = "Unnamed error";
}

Exp::Exp(int code, std::string msg) {
  this->code = code;
  this->msg = msg;
}

std::string Exp::show() {
  return msg;
}

Exp &Exp::operator<<(const std::string& arg_msg) {
  msg = arg_msg;
  code = 1;
  return *this;
}
int Exp::GetCode() {
  return code;
}
