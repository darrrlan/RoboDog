#include "kin_inv.h"



Kin_inv::Kin_inv(int joelho, int ombro, int lado) {
  servonum1 = joelho;
  servonum2 = ombro;
  _lado = lado;
}

void Kin_inv::calc_ang(float x, float y) {

  theta2rad = acos((x * x + y * y - L1 * L1 - L2 * L2) / (2 * L1 * L2));
  theta1rad = atan(y / x) - atan(L2 * sin(theta2rad) / (L1 + L2 * cos(theta2rad)));
  if(theta1rad < -M_PI/2){
    theta1rad = M_PI + theta1rad;
  }else if(theta1rad > M_PI/2){
    theta1rad = theta1rad - M_PI;
    
  }

  Moto.motor1 = 90 - (theta1rad * 180 / M_PI);
  Moto.motor2 = 90 - (theta2rad * 180 / M_PI);

  //  return Moto;
}

int*  Kin_inv::movimento(float x_futuro, float y_futuro) {
  if (x_atual < x_futuro) {
    x_atual++;
  }
  if (x_atual > x_futuro) {
    x_atual--;
  }
  if (y_atual < y_futuro) {
    y_atual++;
  }
  if (y_atual > y_futuro) {
    y_atual--;
  }
  calc_ang(x_atual, y_atual);
  if(_lado == lado_a){
  servo[0] = map(Moto.motor1, -90, 90, 2280, 550);
  servo[1] = map(Moto.motor2, -90, 90, 2280, 550);
  }else{
  servo[0] = map(Moto.motor1, -90, 90, 550, 2280);
  servo[1] = map(Moto.motor2, -90, 90, 550, 2280);
  }


  return servo;

}
