# 📡 Ultrasonic Distance Sensor with LCD, LED & Buzzer Alert

An Arduino-based proximity detection system that measures distance using an HC-SR04 ultrasonic sensor and provides real-time feedback via an I2C LCD display, LED indicator, and buzzer alert.

---

## 🛠 Hardware Requirements

| Component | Quantity |
|---|---|
| Arduino (Uno / Nano / Mega) | 1 |
| HC-SR04 Ultrasonic Sensor | 1 |
| I2C LCD Display (16×2) | 1 |
| LED | 1 |
| Buzzer (passive or active) | 1 |
| 220Ω resistor (for LED) | 1 |
| Jumper wires | As needed |
| Breadboard | 1 |

---

## 📌 Pin Configuration

| Component | Arduino Pin |
|---|---|
| Ultrasonic TRIG | 9 |
| Ultrasonic ECHO | 10 |
| LED | 6 |
| Buzzer | 7 |
| LCD SDA | A4 |
| LCD SCL | A5 |

> The LCD communicates over I2C (default address `0x27`). SDA/SCL pins vary by board — A4/A5 on Uno/Nano, pins 20/21 on Mega.

---

## 📦 Dependencies

Install these libraries via the Arduino Library Manager (**Sketch → Include Library → Manage Libraries**):

- [`LiquidCrystal_I2C`](https://github.com/johnrickman/LiquidCrystal_I2C) by Frank de Brabander
- `Wire` *(built-in with Arduino IDE)*

---

## ⚙️ How It Works

1. The TRIG pin fires a 10µs ultrasonic pulse every 200ms.
2. The ECHO pin measures how long the pulse takes to return.
3. Distance is calculated using: `distance (cm) = duration × 0.034 / 2`
4. The result is displayed live on the LCD.
5. Alert logic triggers based on proximity:

| Distance | LED | Buzzer |
|---|---|---|
| < 10 cm | 🟢 ON | 🔔 ON |
| 10 – 25 cm | 🟢 ON | 🔕 OFF |
| > 25 cm | ⚫ OFF | 🔕 OFF |

---

## 🚀 Getting Started

1. Wire up the components per the pin configuration above.
2. Install the required libraries.
3. Open the `.ino` file in the Arduino IDE.
4. Select your board and COM port under **Tools**.
5. Click **Upload**.
6. Open the **Serial Monitor** at `9600` baud for debug output.

---

## 🔧 Customization

- **Alert thresholds** — Change the `10` and `25` values in the `loop()` function to adjust sensitivity.
- **LCD I2C address** — If the screen doesn't light up, try `0x3F` instead of `0x27` in `LiquidCrystal_I2C lcd(0x27, 16, 2)`.
- **Polling rate** — Adjust `delay(200)` at the end of `loop()` to make readings faster or slower.

---

## 📄 License

This project is open-source and free to use under the [MIT License](https://opensource.org/licenses/MIT).
