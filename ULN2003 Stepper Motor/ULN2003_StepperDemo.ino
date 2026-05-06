/*
 * =====================================================
 *  ULN2003 + 28BYJ-48 Stepper Motor — Full Demo
 *  Arduino Uno R4 Minima
 * =====================================================
 *  DEMOS:
 *   1. Full-Step Mode (CW & CCW)
 *   2. Half-Step Mode (smoother, more torque positions)
 *   3. Speed Control (slow → fast → slow)
 *   4. Acceleration & Deceleration Ramp
 *   5. Precise Angle Positioning (e.g. 90°, 180°, 270°)
 *   6. Step Counting & Position Tracking
 *   7. Coil Power-Off (energy saving between moves)
 *   8. Oscillation / Back-and-Forth
 * =====================================================
 */

// ── Pin Definitions ──────────────────────────────────
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

// ── Motor Constants ───────────────────────────────────
// 28BYJ-48 specs:
//   Internal step angle : 5.625° per step (full-step)
//   Gear ratio          : ~1:64
//   Full steps/rev      : 2048
//   Half steps/rev      : 4096

const int FULL_STEPS_PER_REV = 2048;
const int HALF_STEPS_PER_REV = 4096;

// ── Step Sequences ────────────────────────────────────

// Full-Step (4-step sequence) — higher torque, slightly coarser
const byte fullStep[4][4] = {
  {1, 0, 1, 0},
  {0, 1, 1, 0},
  {0, 1, 0, 1},
  {1, 0, 0, 1}
};

// Half-Step (8-step sequence) — smoother motion, finer resolution
const byte halfStep[8][4] = {
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

// ── State Tracking ────────────────────────────────────
long currentPosition = 0;  // tracks absolute step position

// ─────────────────────────────────────────────────────
//  SETUP
// ─────────────────────────────────────────────────────
void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
  while (!Serial);  // wait for Serial Monitor

  coilsOff();  // start with coils off (save power)

  Serial.println("====================================");
  Serial.println(" ULN2003 + 28BYJ-48 Full Demo");
  Serial.println("====================================\n");
  delay(1000);

  runAllDemos();
}

void loop() {

}

// ─────────────────────────────────────────────────────
//  MASTER DEMO RUNNER
// ─────────────────────────────────────────────────────
void runAllDemos() {

  // ── DEMO 1: Full-Step CW ────────────────────────────
  Serial.println("DEMO 1: Full-Step Mode — Clockwise (1 full revolution)");
  rotate_fullStep(FULL_STEPS_PER_REV, true, 3);
  // true = CW, 3ms delay per step
  coilsOff();
  delay(1500);

  // ── DEMO 2: Full-Step CCW ───────────────────────────
  Serial.println("DEMO 2: Full-Step Mode — Counter-Clockwise (1 full revolution)");
  rotate_fullStep(FULL_STEPS_PER_REV, false, 3);
  coilsOff();
  delay(1500);

  // ── DEMO 3: Half-Step (smoother) ────────────────────
  Serial.println("DEMO 3: Half-Step Mode — Smoother rotation (1 full revolution CW)");
  rotate_halfStep(HALF_STEPS_PER_REV, true, 2);
  coilsOff();
  delay(1500);

  // ── DEMO 4: Speed Control (Slow → Fast → Slow) ──────
  Serial.println("DEMO 4: Speed Control — Slow to Fast to Slow (half-step)");
  demo_speedControl();
  coilsOff();
  delay(1500);

  // ── DEMO 5: Acceleration Ramp ────────────────────────
  Serial.println("DEMO 5: Acceleration & Deceleration Ramp");
  demo_accelerationRamp(HALF_STEPS_PER_REV / 2, 2, 10);
  // (steps, fastest delay ms, slowest delay ms)
  coilsOff();
  delay(1500);

  // ── DEMO 6: Precise Angle Positioning ───────────────
  Serial.println("DEMO 6: Precise Angle Control");
  rotateDegrees(90,  true,  3);   Serial.println("  → Moved 90° CW");   delay(800);
  rotateDegrees(90,  true,  3);   Serial.println("  → Moved 90° CW");   delay(800);
  rotateDegrees(180, false, 3);   Serial.println("  → Moved 180° CCW"); delay(800);
  rotateDegrees(180, false, 3);   Serial.println("  → Back to start");  delay(800);
  coilsOff();
  delay(1500);

  // ── DEMO 7: Position Tracking ────────────────────────
  Serial.println("DEMO 7: Step Position Tracking");
  currentPosition = 0;
  demo_positionTracking();
  coilsOff();
  delay(1500);

  // ── DEMO 8: Oscillation (Back and Forth) ─────────────
  Serial.println("DEMO 8: Oscillation — Back and Forth x5");
  demo_oscillation(5, 45, 3);
  // (repetitions, degrees per swing, step delay ms)
  coilsOff();
  delay(1500);

  Serial.println("\n====================================");
  Serial.println(" All Demos Complete!");
  Serial.println("====================================");
}

// ─────────────────────────────────────────────────────
//  CORE DRIVER FUNCTIONS
// ─────────────────────────────────────────────────────

// Write one step to the coils
void writeCoils(byte in1, byte in2, byte in3, byte in4) {
  digitalWrite(IN1, in1);
  digitalWrite(IN2, in2);
  digitalWrite(IN3, in3);
  digitalWrite(IN4, in4);
}

// Turn off all coils (saves power, reduces heat)
void coilsOff() {
  writeCoils(0, 0, 0, 0);
}

// ── Full-Step Rotation ───────────────────────────────
// steps    : number of steps to move
// clockwise: direction
// delayMs  : delay between steps (controls speed)
void rotate_fullStep(int steps, bool clockwise, int delayMs) {
  for (int i = 0; i < steps; i++) {
    int idx = clockwise ? (i % 4) : (3 - (i % 4));
    writeCoils(fullStep[idx][0], fullStep[idx][1],
               fullStep[idx][2], fullStep[idx][3]);
    delay(delayMs);
    currentPosition += clockwise ? 1 : -1;
  }
}

// ── Half-Step Rotation ───────────────────────────────
void rotate_halfStep(int steps, bool clockwise, int delayMs) {
  for (int i = 0; i < steps; i++) {
    int idx = clockwise ? (i % 8) : (7 - (i % 8));
    writeCoils(halfStep[idx][0], halfStep[idx][1],
               halfStep[idx][2], halfStep[idx][3]);
    delay(delayMs);
    currentPosition += clockwise ? 1 : -1;
  }
}

// ─────────────────────────────────────────────────────
//  ANGLE CONTROL
// ─────────────────────────────────────────────────────
// Convert degrees → half-steps and rotate
void rotateDegrees(float degrees, bool clockwise, int delayMs) {
  int steps = (int)((degrees / 360.0) * HALF_STEPS_PER_REV);
  rotate_halfStep(steps, clockwise, delayMs);
}

// ─────────────────────────────────────────────────────
//  DEMO FUNCTIONS
// ─────────────────────────────────────────────────────

// DEMO 4 — Speed Control
void demo_speedControl() {
  int totalSteps = HALF_STEPS_PER_REV;
  int third = totalSteps / 3;

  Serial.println("  Slow (8ms/step)...");
  rotate_halfStep(third, true, 8);

  Serial.println("  Medium (4ms/step)...");
  rotate_halfStep(third, true, 4);

  Serial.println("  Fast (2ms/step)...");
  rotate_halfStep(third, true, 2);
}

// DEMO 5 — Acceleration + Deceleration Ramp
void demo_accelerationRamp(int totalSteps, int fastDelay, int slowDelay) {
  int rampSteps = totalSteps / 3;       // 1/3 accel, 1/3 cruise, 1/3 decel

  // Accelerate: slowDelay → fastDelay
  for (int i = 0; i < rampSteps; i++) {
    int d = map(i, 0, rampSteps, slowDelay, fastDelay);
    int idx = i % 8;
    writeCoils(halfStep[idx][0], halfStep[idx][1],
               halfStep[idx][2], halfStep[idx][3]);
    delay(d);
  }

  // Cruise at full speed
  for (int i = 0; i < rampSteps; i++) {
    int idx = (rampSteps + i) % 8;
    writeCoils(halfStep[idx][0], halfStep[idx][1],
               halfStep[idx][2], halfStep[idx][3]);
    delay(fastDelay);
  }

  // Decelerate: fastDelay → slowDelay
  for (int i = 0; i < rampSteps; i++) {
    int d = map(i, 0, rampSteps, fastDelay, slowDelay);
    int idx = (2 * rampSteps + i) % 8;
    writeCoils(halfStep[idx][0], halfStep[idx][1],
               halfStep[idx][2], halfStep[idx][3]);
    delay(d);
  }
}

// DEMO 7 — Position Tracking
void demo_positionTracking() {
  currentPosition = 0;
  Serial.print("  Start position: "); Serial.println(currentPosition);

  rotateDegrees(180, true, 3);
  Serial.print("  After +180°: step position = "); Serial.println(currentPosition);

  rotateDegrees(90, false, 3);
  Serial.print("  After -90°:  step position = "); Serial.println(currentPosition);

  // Calculate current angle from step count
  float angle = (currentPosition % HALF_STEPS_PER_REV) * 360.0 / HALF_STEPS_PER_REV;
  Serial.print("  Current shaft angle ≈ "); Serial.print(angle); Serial.println("°");
}

// DEMO 8 — Oscillation
void demo_oscillation(int reps, float degrees, int delayMs) {
  for (int i = 0; i < reps; i++) {
    Serial.print("  Swing "); Serial.print(i + 1);
    Serial.print(" → CW "); Serial.print(degrees); Serial.println("°");
    rotateDegrees(degrees, true, delayMs);
    delay(300);

    Serial.print("  Swing "); Serial.print(i + 1);
    Serial.print(" → CCW "); Serial.print(degrees); Serial.println("°");
    rotateDegrees(degrees, false, delayMs);
    delay(300);
  }
}