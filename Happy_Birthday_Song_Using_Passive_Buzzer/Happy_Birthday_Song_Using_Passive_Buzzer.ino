int buzzer = 8;

// ---- Note frequencies (Hz) ----
#define C4 262
#define D4 294
#define E4 330
#define F4 349
#define G4 392
#define A4 440
#define B4 494

#define C5 523
#define D5 587
#define E5 659
#define F5 698
#define G5 784

#define REST 0

// ---- Tempo control ----
// Increase tempo → faster; decrease → slower
int tempo = 140;  // tuned for recognizability

// ---- Melody (note, duration) ----
// duration: 4=quarter, 8=eighth, -4=dotted quarter, etc.
int melody[] = {
  // Happy Birthday to you
  G4,8, G4,8, A4,4, G4,4, C5,4, B4,-4,
  // Happy Birthday to you
  G4,8, G4,8, A4,4, G4,4, D5,4, C5,-4,
  // Happy Birthday dear ___
  G4,8, G4,8, G5,4, E5,4, C5,4, B4,4, A4,-4,
  // Happy Birthday to you
  F5,8, F5,8, E5,4, C5,4, D5,4, C5,-2
};

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int notes = sizeof(melody) / sizeof(melody[0]) / 2;

  // Quarter note duration (ms)
  int wholenote = (60000 * 4) / tempo;

  for (int i = 0; i < notes * 2; i += 2) {

    int note = melody[i];
    int divider = melody[i + 1];

    int duration;
    if (divider > 0) {
      duration = wholenote / divider;
    } else {
      // dotted note (e.g., -4)
      duration = (wholenote / abs(divider)) * 1.5;
    }

    if (note == REST) {
      noTone(buzzer);
    } else {
      tone(buzzer, note, duration * 0.9); // slight cut for clarity
    }

    delay(duration);
    noTone(buzzer);
  }

  delay(3000); // repeat gap
}