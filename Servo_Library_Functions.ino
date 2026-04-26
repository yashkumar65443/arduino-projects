#include <Servo.h>

Servo myServo;   // 1️⃣ create object

void setup() {
  Serial.begin(9600);

  // 2️⃣ attach(pin)
  myServo.attach(9);  
  Serial.println("Servo attached to pin 9");

  delay(1000);

  // 3️⃣ write(angle)
  myServo.write(0);
  Serial.println("Moved to 0 degrees");
  delay(1000);

  myServo.write(90);
  Serial.println("Moved to 90 degrees");
  delay(1000);

  // 5️⃣ read()
  int pos = myServo.read();
  Serial.print("Last written angle: ");
  Serial.println(pos);

  delay(1000);

  // 6️⃣ attached()
  if (myServo.attached()) {
    Serial.println("Servo is attached");
  }

  delay(1000);

  // 4️⃣ writeMicroseconds(us)
  myServo.writeMicroseconds(1000);
  Serial.println("Microseconds: 1000 (one extreme)");
  delay(1000);

  myServo.writeMicroseconds(1500);
  Serial.println("Microseconds: 1500 (center)");
  delay(1000);

  myServo.writeMicroseconds(2000);
  Serial.println("Microseconds: 2000 (other extreme)");
  delay(1000);

  // 7️⃣ detach()
  myServo.detach();
  Serial.println("Servo detached (no signal sent)");
}

void loop() {
  // Nothing here — everything runs once in setup
}