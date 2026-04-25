// traffic light system
// using pins 2,3,4 for red, blue, green

int red = 2;
int blue = 3;
int green = 4;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);

  // just making sure everything starts OFF
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(green, LOW);
}

void loop() {

  // green ON (cars go)
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  digitalWrite(red, LOW);
  delay(5000);  

  // blue ON (warning)
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  delay(2000);  

  // red ON (stop)
  digitalWrite(blue, LOW);
  digitalWrite(red, HIGH);
  delay(5000);  

}