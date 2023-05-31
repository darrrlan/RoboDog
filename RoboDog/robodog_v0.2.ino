#include <TimeInterrupt.h>
#define led_pin 3
//#include "TimerInterrupt.h"
#include <math.h>
#include "kin_inv.h"
#include "controlepernas.h"
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

Kin_inv perna1(1, 2, lado_a);
Kin_inv perna2(3,4,lado_b);
Kin_inv perna3(5,6, lado_b);
Kin_inv perna4(6,7, lado_a);
float *coordenada;
int *servo1, *servo2, *servo3, *servo4;
Controlepernas robodog;

int countdown = 10;

void setup()
{
  Serial.begin(115200);
  TimeInterrupt.begin(PRECISION); //Initialize the interrupt with high precision timing
  pinMode(led_pin, OUTPUT);

  TimeInterrupt.addInterrupt(baseTempo, 10); //Call 'printMessage' every second
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
}

void loop()
{

  pwm.writeMicroseconds(2, 1500 );
  pwm.writeMicroseconds(3, 1500 );
  pwm.writeMicroseconds(12, 1500 );
  pwm.writeMicroseconds(13, 1500 );
  pwm.writeMicroseconds(0, 1500);
  pwm.writeMicroseconds(1, 1500);
  pwm.writeMicroseconds(5,1500);
  pwm.writeMicroseconds(4, 1500);
  pwm.writeMicroseconds(10, 1500);
  pwm.writeMicroseconds(11, 1500);
  pwm.writeMicroseconds(15,1500);
  pwm.writeMicroseconds(14, 1500);
//  pwm.writeMicroseconds(2, 1500 );
//  pwm.writeMicroseconds(3, 1500 );
//  pwm.writeMicroseconds(12, 1500 );
//  pwm.writeMicroseconds(13, 1500 );
//  pwm.writeMicroseconds(0, servo1[1]);
//  pwm.writeMicroseconds(1, servo1[0]);
//  pwm.writeMicroseconds(5, servo2[1]);
//  pwm.writeMicroseconds(4, servo2[0]);
//  pwm.writeMicroseconds(10, servo3[1]);
//  pwm.writeMicroseconds(11, servo3[0]);
//  pwm.writeMicroseconds(15, servo4[1]);
//  pwm.writeMicroseconds(14, servo4[0]);
}

void baseTempo()
{
  robodog.controle();
  coordenada = robodog.valores();

  servo1 = perna1.movimento(coordenada[0], coordenada[1]);
  servo2 = perna2.movimento(coordenada[2], coordenada[3]);
  servo3 = perna3.movimento(coordenada[4], coordenada[5]);
  servo4 = perna4.movimento(coordenada[6], coordenada[7]);
  Serial.print(" ");
  Serial.print(servo1[0]);
  Serial.print(" ");
  Serial.println(servo1[1]);

}
