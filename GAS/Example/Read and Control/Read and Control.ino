#include <Gas.h>
Gas Mq6(A0,5,6,10,80);
// Led Gas(sensor_pin,Control_pin1,Control_pin2,min,max);
//sensor_pin_value < min = Control_pin1_HIGH
//sensor_pin_value > max = Control_pin2_HIGH
//Otherwise = Control_pin1_LOW / Control_pin2_LOW
void setup() {
  Serial.begin(9600);

}

void loop() {
 int c =  Mq6.Sensor();
 Mq6.Switching();
 Serial.println(c);

}