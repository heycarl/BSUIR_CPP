//
// Created by Alexandr on 10/13/2022.
//

#include <iostream>
#include <iomanip>

#include "Monoblock.h"
double Monoblock::GetScreenSize() const {
  return m_ScreenSize;
}
void Monoblock::SetScreenSize(double arg_screen_size) {
  m_ScreenSize = arg_screen_size;
}
std::ofstream &operator<<(std::ofstream &out, Monoblock &o) {
  out << o.m_ScreenSize << o.m_Brand << o.m_Case << o.m_Model;
  return out;
}
std::ifstream &operator>>(std::ifstream &in, Monoblock &o) {
  in >> o.m_Model >> o.m_Case >> o.m_Brand >> o.m_ScreenSize;
  return in;
}
Monoblock::Monoblock(double screen_size) : m_ScreenSize(screen_size) {

}
