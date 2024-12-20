//
// Created by Jamie Briggs on 18/12/2024.
//

#ifndef CORRUPTEDBYTE_H
#define CORRUPTEDBYTE_H

#include "Byte.h"

namespace solutions {

  class CorruptedByte : public Byte {
  public:
    CorruptedByte(int x, int y) : Byte(x, y, false) {}
  };

}


#endif //CORRUPTEDBYTE_H
