const int ldrPin = A0;
const int ledPin = 9;

// LED turns ON when light drops below this value
const int threshold = 200;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Night Lamp Ready — threshold fixed at 200");
}

void loop() {
  // Read light level (0 = dark, 1023 = bright)
  int lightValue = analogRead(ldrPin);

  // Turn LED ON if dark, OFF if bright
  if (lightValue < threshold) {
    digitalWrite(ledPin, HIGH);  // Dark → LED ON
  } else {
    digitalWrite(ledPin, LOW);   // Bright → LED OFF
  }

  // Debug output
  Serial.print("Light: ");
  Serial.print(lightValue);
  Serial.print(" | LED: ");
  Serial.println(lightValue < threshold ? "ON" : "OFF");

  delay(200);
}