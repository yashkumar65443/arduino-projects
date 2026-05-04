
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ── LCD object: address, columns, rows ──────────────────────
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ── Custom character bitmaps (5×8 pixels each) ───────────────
byte heart[8]     = {0b00000,0b01010,0b11111,0b11111,0b01110,0b00100,0b00000,0b00000};
byte smiley[8]    = {0b00000,0b01010,0b00000,0b00000,0b10001,0b01110,0b00000,0b00000};
byte arrow[8]     = {0b00100,0b01110,0b11111,0b00100,0b00100,0b00100,0b00000,0b00000};
byte lock[8]      = {0b01110,0b10001,0b10001,0b11111,0b11011,0b11011,0b11111,0b00000};
byte bell[8]      = {0b00100,0b01110,0b01110,0b01110,0b11111,0b00000,0b00100,0b00000};
byte music[8]     = {0b01111,0b01001,0b01001,0b01011,0b11011,0b11000,0b00000,0b00000};
byte battery[8]   = {0b01110,0b11111,0b10001,0b10001,0b10001,0b11111,0b11111,0b00000};
byte checkmark[8] = {0b00000,0b00001,0b00011,0b10110,0b11100,0b01000,0b00000,0b00000};

// ── Helper: clear + show section title ───────────────────────
void showTitle(const char* title) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(title);
  delay(1200);
  lcd.clear();
}

// ────────────────────────────────────────────────────────────
void setup() {
  Serial.begin(9600);

  // ── 1. init() ─────────────────────────────────────────────
  lcd.init();               // initialise the LCD hardware
  Serial.println("init() done");

  // ── 2. backlight() / noBacklight() ───────────────────────
  showTitle("1. Backlight");
  lcd.backlight();          // turn backlight ON
  lcd.setCursor(0, 0);
  lcd.print("Backlight ON");
  delay(1200);

  lcd.noBacklight();        // turn backlight OFF
  delay(800);

  lcd.backlight();          // back ON for rest of demo
  delay(600);

  // ── 3. display() / noDisplay() ───────────────────────────
  showTitle("2. Display Tog");
  lcd.setCursor(0, 0);
  lcd.print("noDisplay() off");
  lcd.noDisplay();          // hide everything (keeps content)
  delay(900);
  lcd.display();            // show content again
  lcd.setCursor(0, 1);
  lcd.print("display() on");
  delay(1200);

  // ── 4. clear() ────────────────────────────────────────────
  showTitle("3. clear()");
  lcd.print("Before clear...");
  delay(800);
  lcd.clear();              // wipe all chars, cursor → (0,0)
  lcd.print("After clear!");
  delay(1200);

  // ── 5. home() ─────────────────────────────────────────────
  showTitle("4. home()");
  lcd.print("home() resets");
  lcd.setCursor(8, 1);
  lcd.print("cursor");
  delay(800);
  lcd.home();               // move cursor to column 0, row 0
  lcd.print("*");           // overwrites first char
  delay(1200);

  // ── 6. setCursor(col, row) ────────────────────────────────
  showTitle("5. setCursor()");
  lcd.setCursor(0,  0); lcd.print("Row0 Col0");
  lcd.setCursor(6,  1); lcd.print("Row1 Col6");
  delay(1500);

  // ── 7. print() — strings, integers, floats ───────────────
  showTitle("6. print()");
  lcd.setCursor(0, 0); lcd.print("Str: Hello!");
  lcd.setCursor(0, 1); lcd.print("Int:");
  lcd.print(2025);
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("Float:");
  lcd.print(3.14159, 4);    // 4 decimal places
  delay(1500);

  // ── 8. write() — single character ────────────────────────
  showTitle("7. write()");
  lcd.setCursor(0, 0); lcd.print("write() chars:");
  lcd.setCursor(0, 1);
  for (char c = 'A'; c <= 'P'; c++) {
    lcd.write(c);           // write one character at a time
    delay(60);
  }
  delay(800);

  // ── 9. createChar() + custom character display ────────────
  showTitle("8. createChar()");
  lcd.createChar(0, heart);      // slot 0
  lcd.createChar(1, smiley);     // slot 1
  lcd.createChar(2, arrow);      // slot 2
  lcd.createChar(3, lock);       // slot 3
  lcd.createChar(4, bell);       // slot 4
  lcd.createChar(5, music);      // slot 5
  lcd.createChar(6, battery);    // slot 6
  lcd.createChar(7, checkmark);  // slot 7

  lcd.setCursor(0, 0); lcd.print("Custom chars:");
  lcd.setCursor(0, 1);
  for (byte i = 0; i < 8; i++) {
    lcd.write(byte(i));     // display each custom char
    lcd.write(' ');
    delay(200);
  }
  delay(1200);

  // ── 10. cursor() / noCursor() ────────────────────────────
  showTitle("9. cursor()");
  lcd.setCursor(0, 0); lcd.print("cursor() = line");
  lcd.cursor();             // show underscore cursor
  delay(1500);
  lcd.noCursor();           // hide cursor
  lcd.setCursor(0, 1); lcd.print("noCursor() done");
  delay(1200);

  // ── 11. blink() / noBlink() ──────────────────────────────
  showTitle("10. blink()");
  lcd.setCursor(0, 0); lcd.print("blink() = block");
  lcd.setCursor(15, 1);
  lcd.blink();              // blinking block cursor
  delay(2500);
  lcd.noBlink();            // stop blinking
  lcd.setCursor(0, 1); lcd.print("noBlink() done ");
  delay(1200);

  // ── 12. scrollDisplayLeft() ───────────────────────────────
  showTitle("11. ScrollLeft");
  lcd.setCursor(0, 0); lcd.print("<<< Scrolling left content...");
  for (byte i = 0; i < 14; i++) {
    lcd.scrollDisplayLeft();   // shift everything left by 1
    delay(200);
  }
  delay(800);

  // ── 13. scrollDisplayRight() ─────────────────────────────
  showTitle("12. ScrollRight");
  lcd.setCursor(0, 0); lcd.print("Scrolling right>>>");
  for (byte i = 0; i < 8; i++) {
    lcd.scrollDisplayRight();  // shift everything right by 1
    delay(200);
  }
  delay(800);

  // ── 14. autoscroll() / noAutoscroll() ────────────────────
  showTitle("13. autoscroll");
  lcd.setCursor(15, 0);
  lcd.autoscroll();         // text pushes itself left as typed
  lcd.print("AutoScroll!!");
  delay(200);
  lcd.noAutoscroll();       // back to normal printing
  delay(1000);

  // ── 15. leftToRight() / rightToLeft() ────────────────────
  showTitle("14. Direction");
  lcd.setCursor(0, 0); lcd.print("L->R (default)");
  lcd.leftToRight();        // default: print left→right
  delay(800);

  lcd.clear();
  lcd.setCursor(15, 0);     // start from right edge
  lcd.rightToLeft();        // print right→left
  lcd.print("reversed");    // appears mirrored
  delay(1200);
  lcd.leftToRight();        // ALWAYS restore to normal!

  // ────────────────────────────────────────────────────────
  // FINAL: Loop demo — custom chars + scrolling message
  // ────────────────────────────────────────────────────────
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(byte(0)); lcd.print(" All done! ");  lcd.write(byte(1));
  lcd.setCursor(0, 1);
  lcd.write(byte(4)); lcd.print(" Loop start "); lcd.write(byte(7));
  delay(2000);
}

// ────────────────────────────────────────────────────────────
void loop() {
  // Animated ticker: custom icons + scrolling text
  String msg = "  I2C LCD Full Demo  |  Heart ";
  lcd.clear();

  // Row 0: animated icon bar
  lcd.setCursor(0, 0);
  for (byte i = 0; i < 8; i++) {
    lcd.write(byte(i));
    lcd.write(' ');
  }

  // Row 1: scroll the message string across
  String padded = "                " + msg + "                ";
  for (int pos = 0; pos <= (int)padded.length() - 16; pos++) {
    lcd.setCursor(0, 1);
    lcd.print(padded.substring(pos, pos + 16));
    delay(220);
  }

  // Blink backlight once between cycles
  lcd.noBacklight(); delay(150);
  lcd.backlight();   delay(150);
}