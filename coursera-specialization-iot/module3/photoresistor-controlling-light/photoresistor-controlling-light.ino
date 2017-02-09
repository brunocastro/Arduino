#define LIGHTPIN 0

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);  //Begin serial communcation
}

void loop() {
  int luminosity = analogRead(LIGHTPIN);
  if (luminosity <= 300) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
