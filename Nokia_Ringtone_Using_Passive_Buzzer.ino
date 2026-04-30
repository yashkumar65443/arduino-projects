int buzzer = 8;

// Notes (Hz)
#define E5 659
#define D5 587
#define FS4 370
#define GS4 415
#define CS5 554
#define B4 494
#define D4 294
#define E4 330
#define B3 247
#define CS4 277

// Melody
int melody[] = {
  E5, D5, FS4, GS4,
  CS5, B4, D4, E4,
  B4, A4, CS4, E4,
  A4
};

// Durations (smaller = faster)
int durations[] = {
  8, 8, 4, 4,
  8, 8, 4, 4,
  8, 8, 4, 4,
  2
};

// Missing notes
#define A4 440

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int size = sizeof(melody) / sizeof(melody[0]);

  for (int i = 0; i < size; i++) {
    int noteDuration = 1000 / durations[i];

    tone(buzzer, melody[i], noteDuration);

    delay(noteDuration * 1.3);
    noTone(buzzer);
  }

  delay(2000);
}