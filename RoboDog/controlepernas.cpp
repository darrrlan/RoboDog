#include "controlepernas.h"



Controlepernas::Controlepernas(void) {
  estado_controle = 1;
  count = 0;
}

float* Controlepernas::valores(void) {
  return coord;
}

void Controlepernas::controle(void) {
  switch (estado_controle) {
    case 1:
      count++;
      if (count == constTempo) {
        count = 0;
        coord[0] = 40;
        coord[1] = 100;
        coord[2] = -40;
        coord[3] = 100;
        coord[4] = 40;
        coord[5] = 100;
        coord[6] = -40;
        coord[7] = 100;
        estado_controle++;
      }
      break;
    case 2:
      count++;
      if (count == constTempo) {
        count = 0;
        coord[0] = 0;
        coord[1] = 100;
        coord[2] = 0;
        coord[3] = 50;
        coord[4] = 0;
        coord[5] = 50;
        coord[6] = 0;
        coord[7] = 100;
        estado_controle++;
      }
      break;

    case 3 :
      count++;
      if (count == constTempo) {
        count = 0;
        coord[0] = -40;
        coord[1] = 100;
        coord[2] = 40;
        coord[3] = 100;
        coord[4] = -40;
        coord[5] = 100;
        coord[6] = 40;
        coord[7] = 100;
        estado_controle++;
      }
      break;

    case 4 :
      count++;
      if (count == constTempo) {
        count = 0;
        coord[0] = 0;
        coord[1] = 50;
        coord[2] = 0;
        coord[3] = 100;
        coord[4] = 0;
        coord[5] = 100;
        coord[6] = 0;
        coord[7] = 50;
        estado_controle++;
      }
      break;



    case 5:
      estado_controle = 1;
      break;
  }
}
