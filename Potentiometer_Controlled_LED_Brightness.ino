int potPin = A0;    // Potentiometer middle pin
int ledPin = 9;     // PWM pin

void setup() {
  Serial.begin(9600);      // Start serial communication
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);          // 0–1023
  int brightness = map(potValue, 0, 1023, 0, 255);

  analogWrite(ledPin, brightness);            // Control LED

  Serial.print("Pot Value: ");
  Serial.print(potValue);
  Serial.print("  |  Brightness: ");
  Serial.println(brightness);

  delay(200);  // Stable reading
}