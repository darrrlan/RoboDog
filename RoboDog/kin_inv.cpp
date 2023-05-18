#include "kin_inv.h"

Kin_inv::Kin_inv(void){
    L1 = 69;
}
 
float* Kin_inv::calc_ang(float x,float y){

  theta2rad = acos((x * x + y * y - L1 * L1 - L2 * L2) / (2 * L1 * L2));
  theta1rad = atan(y / x) - atan(L2 * sin(theta2rad) / (L1 + L2 * cos(theta2rad)));

  motor1 = 90 - (theta1rad * 180 / M_PI);
  motor2 = 90 - (theta2rad * 180 / M_PI);

  static float retorno[2];
  retorno[0] = motor1;
  retorno[1] = motor2;
  
  return (retorno);
}

float* Kin_inv::movimento(float x_futuro, float y_futuro){

  if(x_atual < x_futuro){
    x_atual++;
 }
   if(x_atual > x_futuro){
    x_atual--;
   }

   if(y_atual < y_futuro){
    y_atual++;
 }
   if(y_atual > y_futuro){
    y_atual--;
   }

 obj = calc_ang(x_atual,y_atual);
 
 return obj;
}
