#define POTPIN 2
#define LED 9
int val = 0;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  val = analogRead(POTPIN);
  val = map(val, 0, 1023, 0, 255);
  analogWrite(LED, val);
  
}
