//
// Created by Alexandr on 11/21/2022.
//

#include "Exp_Output.h"

#include <utility>
Exp_Output::Exp_Output(int code,std::string detailed):Exp(code, "Invalid input") {
  detailed_error = std::move(detailed);
}
std::string Exp_Output::output_detailed_error() {
  return detailed_error;
}
std::string Exp_Output::show() {
  return "Error code: " + std::to_string(GetCode()) + "\n" + Exp::show() + ": " + detailed_error;
}
