#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);   // connect signal to pin 9
}

void loop() {
  myServo.write(0);    // go to 0°
  delay(500);

  myServo.write(90);   // go to 90°
  delay(500);

  myServo.write(180);  // go to 180°
  delay(500);
}