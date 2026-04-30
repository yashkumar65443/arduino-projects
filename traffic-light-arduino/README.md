# 🚦 Traffic Light Arduino Project

## 📌 Overview

This project simulates a real-world traffic light system using an Arduino board. It cycles through **Red → Yellow → Green** LEDs with proper timing delays, mimicking an actual traffic signal.

---

## ⚙️ Components Used

* Arduino UNO R4 (or compatible board)
* Red LED
* Yellow LED
* Green LED
* Resistors (220Ω recommended)
* Breadboard
* Jumper wires

---

## 🔌 Circuit Connections

* Red LED → Digital Pin (e.g., 8)
* Yellow LED → Digital Pin (e.g., 9)
* Green LED → Digital Pin (e.g., 10)
* All LED cathodes → GND via resistors

---

## 🧠 Working Principle

The Arduino controls LEDs using digital output pins:

* **Red ON** → Stop
* **Yellow ON** → Wait
* **Green ON** → Go

The program uses `delay()` to maintain timing between transitions.

---

## 💻 Code File

* `traffic_light.ino` → Main Arduino sketch controlling LED sequence

---

## ▶️ How to Run

1. Open the `.ino` file in Arduino IDE
2. Select correct board & port
3. Upload code to Arduino
4. Observe LED sequence on hardware

---

## 🚀 Features

* Simple traffic light simulation
* Beginner-friendly logic
* Demonstrates timing control using Arduino

---

## 🔧 Future Improvements

* Add pedestrian button input
* Use buzzer for sound signals
* Replace delay with non-blocking timing (`millis()`)
* Expand to 4-way traffic system

---

## 📎 Author

Yash Kumar
Electronics & Communication Engineering Student

