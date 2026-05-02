# 🌈 RGB LED Color Cycler

> **An Arduino sketch that cycles through vivid colors on an RGB LED — red, green, blue, and yellow — at a blistering 100ms per flash.**

---

## 🎨 Color Sequence

| Step | Color | R | G | B |
|------|-------|---|---|---|
| 1 | 🔴 Red | 255 | 0 | 0 |
| 2 | 🟢 Green | 0 | 255 | 0 |
| 3 | 🔵 Blue | 0 | 0 | 255 |
| 4 | 🟡 Yellow | 255 | 255 | 0 |

---

## 🔌 Pin Wiring

```
Arduino         RGB LED
───────         ───────
Pin  9  ──────► Red   (R)
Pin 10  ──────► Green (G)
Pin 11  ──────► Blue  (B)
GND     ──────► Common Cathode (−)
```

> ⚠️ **Don't forget your current-limiting resistors!** Use ~220Ω on each color leg to protect both the LED and your Arduino pins.

---

## 🚀 How It Works

```cpp
void setColor(int r, int g, int b) {
  analogWrite(redPin,   r);  // PWM → Red channel
  analogWrite(greenPin, g);  // PWM → Green channel
  analogWrite(bluePin,  b);  // PWM → Blue channel
}
```

`analogWrite()` outputs a **PWM signal (0–255)** on each pin, controlling the brightness of each color channel independently. Mix them together and you get any color in the RGB spectrum! 🎛️

---

## 📂 File Structure

```
rgb-led-cycler/
└── rgb_led_cycler.ino   ← Main sketch
```

---

## 🛠️ Requirements

| Tool | Version |
|------|---------|
| 🖥️ Arduino IDE | 1.8+ or 2.x |
| 🔧 Board | Arduino Uno / Nano / Mega |
| 💡 Component | Common-cathode RGB LED |
| ⚡ Resistors | 3× 220Ω |

---

## 🧪 Upload & Run

```bash
# 1. Open rgb_led_cycler.ino in Arduino IDE
# 2. Select your board under Tools → Board
# 3. Select your port under Tools → Port
# 4. Hit Upload ↑
```

Once uploaded, your LED will **endlessly cycle** through the four colors, each held for **100 milliseconds**.

---

## 💡 Remix Ideas

- 🎚️ **Fade between colors** — use a `for` loop to sweep PWM values gradually
- 🌊 **Breathing effect** — slowly pulse brightness up and down with `sin()`
- 🎲 **Random colors** — call `random(0, 255)` for each channel
- 🎵 **Sound-reactive** — read an analog mic and map loudness to color
- 🕹️ **Potentiometer control** — let a knob pick the hue in real time

---

## 📜 License

MIT — do whatever you like with it. Light up the world! 🌍✨ 
