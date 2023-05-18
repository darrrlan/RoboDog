#include "Arduino.h"
#include <math.h>

class Kin_inv {
    float L1;
    float L2 = 47;
    float theta1rad;
    float theta2rad;
    float x = 40;
    float y = 80;
    float motor1;
    float motor2;
     float x_atual, x_futuro, y_atual, y_futuro;
     float *obj;
  public:
    Kin_inv(void);
    float* calc_ang(float, float);
    float* movimento(float,float);
};
