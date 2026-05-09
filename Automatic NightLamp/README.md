# 📡 IR Remote LED Toggle

### 🔴 Toggle an LED wirelessly with any IR remote — built for Arduino


</div>

---

## 📖 Overview

This Arduino sketch turns any standard IR remote into a **wireless LED switch**. Point your remote, press a button, and the LED toggles. No wires, no physical switches — just infrared magic.

> Built on the powerful [IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote) library, it decodes raw 32-bit IR signals and matches them against a configurable button code.

---

## ✨ Features

| Feature | Details |
|---|---|
| 📡 IR Signal Decoding | Reads raw 32-bit codes from any NEC-compatible remote |
| 💡 LED Toggle | Single button flips the LED state each press |
| 🛡️ Debounce Guard | 500 ms cooldown prevents phantom repeats |
| 🖥️ Serial Logging | Prints received codes and LED state to Serial Monitor |
| ⚙️ Easy Config | Change pin and button code with two `#define` lines |

---

## 🔁 How It Works

```
┌─────────────┐     IR Signal      ┌──────────────────┐     Match?     ┌─────────┐
│  IR Remote  │ ──────────────────▶│  IR Receiver     │ ─────────────▶ │   LED   │
│  (any key)  │                    │  Pin 2 (Arduino) │    Toggle!     │  Pin 7  │
└─────────────┘                    └──────────────────┘                └─────────┘
                                           │
                                           ▼
                                   ┌──────────────┐
                                   │Serial Monitor│
                                   │ Code: 32F9A0 │
                                   │   LED ON ✅  │
                                   └──────────────┘
```

**Step-by-step flow:**

1. 🔍 `IrReceiver.decode()` watches for incoming IR pulses on **Pin 2**
2. 📥 On signal arrival, the raw **32-bit hex code** is extracted and printed
3. ⏱️ A **500 ms debounce** check filters out accidental rapid repeats
4. 🔑 If the code matches `BUTTON_CODE`, the LED **toggles** on/off
5. 🔄 `IrReceiver.resume()` arms the receiver for the next press

---

## 🧰 Hardware Requirements

### Components

| # | Component | Spec |
|---|---|---|
| 1 | Arduino Board | Uno, Nano, Mega, or compatible |
| 1 | IR Receiver Module | VS1838B / TSOP4838 (38 kHz) |
| 1 | LED | Any standard 5 mm LED |
| 1 | Resistor | 220 Ω – 330 Ω |
| 1 | IR Remote | NEC protocol (most TV remotes work) |
| — | Jumper Wires | As needed |

### 🔌 Wiring Diagram

```
Arduino               IR Receiver (VS1838B)
───────               ─────────────────────
5V        ────────▶   VCC
GND       ────────▶   GND
Pin 2     ◀────────   DATA / OUT


Arduino               LED
───────               ───────────────────
Pin 7     ────[330Ω]────▶ Anode  (+)
GND       ────────────── Cathode (-)
```

---

## 💻 Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software) (v1.8+ or v2.x)
- **IRremote** library — install in one of two ways:

**Option A — Library Manager (recommended)**
```
Arduino IDE → Sketch → Include Library → Manage Libraries
Search: "IRremote" → Install (by shirriff / ArminJo)
```

**Option B — Manual**
```bash
# Clone into your Arduino libraries folder
git clone https://github.com/Arduino-IRremote/Arduino-IRremote.git
```

---

## ⚙️ Configuration

All tuneable settings live at the top of the sketch:

```cpp
#define IR_RECEIVE_PIN  2         // 👈 Pin connected to IR receiver DATA
#define LED_PIN         7         // 👈 Pin connected to LED
#define BUTTON_CODE     0x32F9A0  // 👈 Hex code of your chosen remote button
```

### 🔍 How to Find Your Button Code

> Don't know your remote's code? The sketch tells you automatically!

1. Upload the sketch without changing `BUTTON_CODE`
2. Open **Serial Monitor** → set baud rate to **9600**
3. Point your remote at the receiver → press any button
4. Copy the printed hex value (e.g. `32F9A0`)
5. Paste it into `#define BUTTON_CODE 0x______`
6. Re-upload — done!

---

## 🚀 Getting Started

```
1. Wire components as shown above
      ↓
2. Install the IRremote library
      ↓
3. Set BUTTON_CODE to match your remote
      ↓
4. Upload the sketch to your Arduino
      ↓
5. Open Serial Monitor at 9600 baud
      ↓
6. Press the button → LED toggles! 🎉
```

---

## 🖥️ Serial Output Example

```
Ready
32F9A0
LED ON
32F9A0
LED OFF
32F9A0
LED ON
```

---

## 🌍 Use Cases

- 🎓 **Learning Project** — great first step into IR communication and digital I/O on Arduino
- 💡 **Wireless Light Switch** — control a desk lamp or indicator light from across the room
- ⚡ **Relay Trigger** — swap the LED for a relay module to switch real mains-voltage devices
- 🎮 **Multi-Button Controller** — extend `BUTTON_CODE` logic to map multiple buttons to multiple actions
- 🎭 **Escape Room Prop** — trigger visual effects wirelessly from a hidden remote

---

## 🗂️ Project Structure

```
ir-remote-led/
├── ir_remote_led.ino   ← Main Arduino sketch
└── README.md           ← This file
```

---

## 📜 License

```
MIT License — free to use, modify, and distribute.
Give credit if you build something cool with it! 🙌
```

---

<div align="center">

Made with ❤️ for the Arduino community

⭐ Star this repo if it helped you!

</div>
