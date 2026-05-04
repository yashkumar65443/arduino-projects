# I2C LCD Full Demo — Arduino Sketch

A comprehensive demonstration of every method in the `LiquidCrystal_I2C` library, written for a 16×2 I2C LCD. Run it once and the `setup()` function walks through all 15 features sequentially; `loop()` then plays an animated ticker with scrolling text and backlight blink.

---

## Hardware Requirements

| Component | Details |
|---|---|
| Microcontroller | Any Arduino (Uno, Nano, Mega, etc.) |
| Display | 16×2 character LCD with I2C backpack |
| I2C address | `0x27` (change in code if yours differs — `0x3F` is also common) |
| Wiring | SDA → A4, SCL → A5 (Uno/Nano); see your board's I2C pins |

---

## Dependencies

Install both libraries via the Arduino Library Manager (**Sketch → Include Library → Manage Libraries**):

- **Wire** *(built-in)* — I2C communication
- **LiquidCrystal_I2C** by Frank de Brabander (or compatible fork)

---

## Features Demonstrated

The sketch demos every major `LiquidCrystal_I2C` method in order:

| Step | Method(s) | What it shows |
|---|---|---|
| 1 | `init()` | Initialise the LCD hardware |
| 2 | `backlight()` / `noBacklight()` | Toggle the LED backlight on and off |
| 3 | `display()` / `noDisplay()` | Hide and restore all displayed content |
| 4 | `clear()` | Wipe the screen and home the cursor |
| 5 | `home()` | Reset cursor to column 0, row 0 |
| 6 | `setCursor(col, row)` | Arbitrary cursor positioning |
| 7 | `print()` | Print strings, integers, and floats |
| 8 | `write()` | Write individual characters |
| 9 | `createChar()` | Define and display 8 custom 5×8 bitmaps |
| 10 | `cursor()` / `noCursor()` | Underscore cursor visibility |
| 11 | `blink()` / `noBlink()` | Blinking block cursor |
| 12 | `scrollDisplayLeft()` | Shift display content left |
| 13 | `scrollDisplayRight()` | Shift display content right |
| 14 | `autoscroll()` / `noAutoscroll()` | Auto-push text as it is typed |
| 15 | `leftToRight()` / `rightToLeft()` | Change text print direction |

### Custom Characters

Eight 5×8 bitmaps are loaded into the LCD's CGRAM (slots 0–7):

| Slot | Icon |
|---|---|
| 0 | Heart |
| 1 | Smiley |
| 2 | Up-arrow |
| 3 | Lock |
| 4 | Bell |
| 5 | Music note |
| 6 | Battery |
| 7 | Checkmark |

---

## Loop Behaviour

After `setup()` completes, `loop()` runs indefinitely:

- **Row 0** — displays all 8 custom characters as an icon bar.
- **Row 1** — scrolls the message `"  I2C LCD Full Demo  |  Heart "` across the display one character at a time.
- **End of each cycle** — blinks the backlight off and on once.

---

## Configuration

| Constant / Value | Location | Description |
|---|---|---|
| `0x27` | `LiquidCrystal_I2C lcd(0x27, 16, 2)` | I2C address — change to match your module |
| `16, 2` | same constructor | Display columns and rows |
| `9600` | `Serial.begin(9600)` | Serial baud rate for debug output |
| `delay()` values | throughout `setup()` | Timing between demo steps (adjust freely) |

---

## Getting Started

1. Wire the LCD to your Arduino's I2C pins and power rails.
2. Install the `LiquidCrystal_I2C` library.
3. Open the sketch in the Arduino IDE.
4. If needed, update the I2C address (`0x27`) to match your display.
5. Upload to your board.
6. Open **Serial Monitor** at **9600 baud** — `init() done` confirms the LCD initialised.

---

## Troubleshooting

| Symptom | Likely cause | Fix |
|---|---|---|
| Blank screen, backlight on | Wrong I2C address | Try `0x3F`; run an I2C scanner sketch |
| No backlight | Contrast pot or bad connection | Check wiring; adjust the trimpot on the backpack |
| Garbled characters | Wrong library version | Ensure LiquidCrystal_I2C (not the base LiquidCrystal) is installed |
| Nothing on Serial Monitor | Baud mismatch | Set Serial Monitor to 9600 baud |

---

## License

Released into the public domain. Use freely in personal and commercial projects.
