#include <IRremote.hpp>

#define IR_RECEIVE_PIN 2
#define LED_PIN 7

#define BUTTON_CODE 0x32F9A0

bool ledState = false;

unsigned long lastPressTime = 0;

void setup() {

  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  Serial.println("Ready");
}

void loop() {

  if (IrReceiver.decode()) {

    uint32_t code = IrReceiver.decodedIRData.decodedRawData;

    Serial.println(code, HEX);

    // Ignore rapid repeats
    if (millis() - lastPressTime > 500) {

      if (code == BUTTON_CODE) {

        ledState = !ledState;

        digitalWrite(LED_PIN, ledState);

        Serial.println(ledState ? "LED ON" : "LED OFF");
      }

      lastPressTime = millis();
    }

    IrReceiver.resume();
  }
}
