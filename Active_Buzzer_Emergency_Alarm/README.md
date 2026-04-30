# 🔊 Active Buzzer Emergency Alarm

## 📌 Overview

This project generates an emergency siren sound using an active buzzer by alternating between two frequencies.

## ⚙️ Components

* Arduino UNO R4
* Active buzzer
* Jumper wires

## 🔌 Connection

* Buzzer → Digital Pin 8
* GND → GND

## 🧠 Working

The Arduino uses the `tone()` function to generate:

* 800 Hz tone
* 1200 Hz tone

Switching between them creates a siren effect.

## ▶️ How to Run

1. Upload code to Arduino
2. Power the circuit
3. Hear alternating siren sound

## 🚀 Features

* Simple emergency alarm simulation
* Demonstrates `tone()` function
