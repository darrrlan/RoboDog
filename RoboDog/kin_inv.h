#include "Arduino.h"
#include <math.h>

#define lado_a 20
#define lado_b 30

class Kin_inv {
    
    int _lado;
    float L1 = 69;
    float L2 = 47;
    float theta1rad;
    float theta2rad;
    float x = 40;
    float y = 80;
    float motor1;
    float motor2;
    float x_atual, y_atual, x_futuro, y_futuro;
    int servo[2], servonum1,servonum2;
    typedef struct {
      float motor1;
      float motor2;
    }Motores;
    Motores Moto;

  public:
    Kin_inv(int, int, int);
    void calc_ang(float, float);
    int* movimento(float, float);
};
