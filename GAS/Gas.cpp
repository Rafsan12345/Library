#include "Arduino.h"
#include "Gas.h"

int addTwoInts(int a, int b) {
  return a + b;
}
int subTwoInts(int a, int b) {
  return a - b;
}
////////////////////////////////////////////////////////////////
Gas::Gas(byte pin1, byte pin2, byte pin3,int min1, int max1) {
  this->pin1 = pin1;
  this->pin2 = pin2;
  this->pin3 = pin3;
  this->min1 = min1;
  this->max1 = max1;
  init();
}


void Gas::init() {
  pinMode(pin1, INPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
}


int Gas::Sensor() {
  int x = analogRead(pin1);
  x = map(x, 0, 1024, 0, 100);
  return x;
}

void Gas::Switching() {
  int cv = Sensor();
  if (cv > max1) {
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
  } 
  else if (cv < min1) {
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, LOW);
  }
  else {
  {digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);}
  }
}



//////////////////////////////////////////////////////////////
