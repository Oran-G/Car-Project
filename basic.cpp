#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
	
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
}

void loop() {
  forward(1000, 255);
  delay(500);
}

void forward(int time, int p)
{
    analogWrite(5, p);
    analogWrite(9, p);
    delay(time);
    analogWrite(5, 0);
    analogWrite(9, 0);

}