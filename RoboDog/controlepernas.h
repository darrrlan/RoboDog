#include "Arduino.h"

#define constTempo 50

class Controlepernas{
  int estado_controle;
  float coord[8];
  int count;
  public:
    Controlepernas(void);
    float* valores(void);
    void controle(void);
};
