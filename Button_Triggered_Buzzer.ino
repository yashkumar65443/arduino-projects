const int buttonPin = 2;
const int buzzerPin = 8;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // internal pull-up
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {   // pressed (because of pull-up logic)
    digitalWrite(buzzerPin, HIGH);  // buzzer ON
  } else {
    digitalWrite(buzzerPin, LOW);   // buzzer OFF
  }
}