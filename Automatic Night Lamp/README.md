# 🌙 Arduino Night Lamp

An automatic night lamp built with Arduino. It reads ambient light through an LDR (Light Dependent Resistor) and switches an LED on when the environment gets dark — no manual intervention needed.

---

## How It Works

An LDR is connected to analog pin `A0`. Its resistance increases as light decreases, which drives the analog reading down. Every 200ms the Arduino samples that reading and compares it against a fixed threshold:

- **Below threshold** → dark → LED turns **ON**
- **Above threshold** → bright → LED turns **OFF**

Each cycle also prints a debug line to the Serial Monitor so you can watch the light level in real time.

---

## Hardware Required

| Component | Quantity |
|---|---|
| Arduino (Uno or compatible) | 1 |
| LDR (photoresistor) | 1 |
| LED | 1 |
| 10kΩ resistor (LDR pull-down) | 1 |
| 220Ω resistor (LED current limiting) | 1 |
| Breadboard + jumper wires | — |

---

## Wiring

```
LDR voltage divider → A0
       5V ──┬── LDR ──┬── A0
            │         │
           GND      10kΩ
                      │
                     GND

LED → D9
  D9 ── 220Ω ── LED(+) ── LED(-) ── GND
```

---

## Pin Reference

| Pin | Role |
|---|---|
| `A0` | LDR analog input |
| `D9` | LED output |

---

## Configuration

A single constant controls the trigger point:

```cpp
const int threshold = 200;  // 0 (dark) – 1023 (bright)
```

Raise it to make the lamp turn on in brighter conditions; lower it to require deeper darkness. Open the Serial Monitor at **9600 baud** and watch the `Light:` readings to find the right value for your environment.

---

## Serial Monitor Output

```
Night Lamp Ready — threshold fixed at 200
Light: 87  | LED: ON
Light: 312 | LED: OFF
Light: 145 | LED: ON
```

---

## Getting Started

1. Wire up the circuit as shown above.
2. Open the sketch in the **Arduino IDE**.
3. Select your board and port under **Tools**.
4. Click **Upload**.
5. Open **Serial Monitor** (9600 baud) to observe live readings.
6. Cover the LDR with your hand — the LED should turn on.

---

## License

MIT — free to use, modify, and share.
