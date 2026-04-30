# 🎂 Happy Birthday Buzzer — Arduino

An Arduino sketch that plays *Happy Birthday to You* on a passive buzzer using the `tone()` function. Clean, tempo-controlled, and easy to customize.

---

## Hardware Required

| Component | Quantity |
|---|---|
| Arduino (Uno / Nano / Mega) | 1 |
| Passive buzzer | 1 |
| 100Ω resistor (optional, protects buzzer) | 1 |
| Jumper wires | 2 |

> **Active vs Passive:** This sketch requires a **passive** buzzer. An active buzzer has a built-in oscillator and will not produce the correct pitches with `tone()`.

---

## Wiring

```
Buzzer (+) ──── Pin 8 ──── Arduino
Buzzer (–) ──── GND  ──── Arduino
```

To use a different pin, change the `buzzer` variable at the top of the sketch:

```cpp
int buzzer = 8; // change to your pin
```

---

## How It Works

The melody is stored as a flat integer array of `(note, duration)` pairs:

```cpp
int melody[] = {
  G4, 8,   // G4 for an eighth note
  A4, 4,   // A4 for a quarter note
  B4, -4,  // B4 for a dotted quarter note
  ...
};
```

**Duration encoding:**

| Value | Note type |
|---|---|
| `4` | Quarter note |
| `8` | Eighth note |
| `2` | Half note |
| `-4` | Dotted quarter (1.5× quarter) |
| `-2` | Dotted half |

The sketch calculates real durations in milliseconds from the `tempo` (BPM), then calls `tone()` for each note at 90% of its duration — leaving a small gap between notes for clarity.

---

## Customization

### Change the tempo

```cpp
int tempo = 140; // beats per minute — raise to speed up, lower to slow down
```

### Add a rest

Use the `REST` macro (defined as `0`) in place of a note:

```cpp
REST, 8,  // eighth-note silence
```

### Change the melody

Notes from C4 to G5 are pre-defined. To add more octaves, follow the same pattern:

```cpp
#define A5 880
#define B5 988
```

---

## Behavior

1. On power-up, the sketch plays *Happy Birthday* once.
2. After the song ends, it waits **3 seconds**, then loops and plays again.
3. To play only once, replace `loop()` contents with a single playback and an infinite `while(true)` at the end.

---

## License

MIT — free to use, modify, and share.
