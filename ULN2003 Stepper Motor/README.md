# 28BYJ-48 + ULN2003 Stepper Motor Demo

A comprehensive Arduino demo for the **28BYJ-48** stepper motor driven by the **ULN2003** driver board. Covers full-step and half-step modes, speed control, acceleration ramping, angle positioning, and oscillation.

---

## Hardware

| Component | Details |
|---|---|
| Microcontroller | Arduino (Uno, Nano, Mega, etc.) |
| Motor | 28BYJ-48 (5V unipolar stepper) |
| Driver | ULN2003 breakout board |

### Wiring

| ULN2003 Pin | Arduino Pin |
|---|---|
| IN1 | 8 |
| IN2 | 9 |
| IN3 | 10 |
| IN4 | 11 |
| VCC | 5 V |
| GND | GND |

> **Note:** Power the motor from the Arduino's 5 V rail for bench testing, or from an external 5 V supply for sustained use.

---

## Motor Specs

| Property | Value |
|---|---|
| Internal step angle | 5.625° (full-step) |
| Gear ratio | ~1 : 64 |
| Full steps / revolution | 2048 |
| Half steps / revolution | 4096 |

---

## Step Modes

### Full-Step (4-step sequence)
Higher torque, slightly coarser resolution. Uses a 4-phase sequence cycling through two coils active at a time.

### Half-Step (8-step sequence)
Smoother motion, double the angular resolution. Alternates between single-coil and dual-coil activation. **This is the default mode for angle control in this sketch.**

---

## Demos

The sketch runs 8 demos in sequence on startup, then halts.

| # | Demo | Description |
|---|---|---|
| 1 | Full-Step CW | 1 full revolution clockwise at 3 ms/step |
| 2 | Full-Step CCW | 1 full revolution counter-clockwise at 3 ms/step |
| 3 | Half-Step CW | 1 full revolution CW at 2 ms/step (smoother) |
| 4 | Speed Control | Slow → Medium → Fast in thirds of one revolution |
| 5 | Accel Ramp | Accelerate, cruise, then decelerate over half a revolution |
| 6 | Angle Control | Sequential 90° and 180° moves with `rotateDegrees()` |
| 7 | Position Tracking | Moves by angle, then reports current step count and shaft angle |
| 8 | Oscillation | 5× back-and-forth swings of 45° each |

Progress and position data are printed to the **Serial Monitor at 9600 baud**.

---

## API Reference

### Core rotation

```cpp
// Full-step rotation
rotate_fullStep(int steps, bool clockwise, int delayMs);

// Half-step rotation
rotate_halfStep(int steps, bool clockwise, int delayMs);
```

### Angle-based control

```cpp
// Converts degrees to half-steps and rotates
rotateDegrees(float degrees, bool clockwise, int delayMs);
```

**Example** — rotate 90° clockwise:
```cpp
rotateDegrees(90, true, 3);
```

### Power management

```cpp
coilsOff();  // De-energise all coils — reduces heat and current draw
```

Call this whenever the motor is not actively moving.

### Position tracking

The global `currentPosition` (in half-steps) is updated by every rotation call. Reset it at any point:

```cpp
currentPosition = 0;
```

Derive the shaft angle from it:

```cpp
float angle = (currentPosition % HALF_STEPS_PER_REV) * 360.0 / HALF_STEPS_PER_REV;
```

---

## Tuning Tips

- **Minimum step delay** — the 28BYJ-48 typically stalls below ~2 ms/step. Start at 3 ms if you see missed steps.
- **Coils off after moves** — leaving coils energised generates heat and drains current. Always call `coilsOff()` when done.
- **Backlash** — the plastic gearbox has a small amount of backlash (~1–2°). Account for this in precision positioning by always approaching a target from the same direction.
- **External power** — for continuous operation or high-load applications, use a dedicated 5 V supply rather than the Arduino's onboard regulator.

---

## File Structure

```
sketch/
└── stepper_demo.ino   # Main sketch (all code in one file)
```

---

## License

MIT — free to use, modify, and distribute.
