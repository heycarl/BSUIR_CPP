//
// Created by Alexandr on 10/13/2022.
//

#ifndef LABS_LAB_03_MONOBLOCK_MONOBLOCK_H_
#define LABS_LAB_03_MONOBLOCK_MONOBLOCK_H_

#include "../Desktop/Desktop.h"
#include "../Serializer/Serializer.h"
 class Monoblock : public Desktop, public Serializer{
 protected:
  double m_ScreenSize = 15;
 public:
  double GetScreenSize() const;
  void SetScreenSize(double arg_screen_size);
  std::string Serialize() override;
  std::string SerializeHeader() override;
};

#endif //LABS_LAB_03_MONOBLOCK_MONOBLOCK_H_
