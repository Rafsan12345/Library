#ifndef GAS_H
#define GAS_H

#include <Arduino.h>

int addTwoInts(int a, int b);
int subTwoInts(int a, int b);
class Gas {
  
  private:
    byte pin1;   
    byte pin2;
    byte pin3;
    int min1;
    int max1;
  public:
    // Setup pin LED and call init()
    Gas(byte pin1,byte pin2,byte pin3,int min1,int max1);
    // Setup the pin led as OUTPUT
    // and power off the LED - default state
    void init();
    void Switching();
    int Sensor();
};
#endif
