void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}
void pulse (int pin, int times, int duration) {
  for (int x=0; x<times; x++) {
    digitalWrite(pin, HIGH);
    delay(200);
    digitalWrite(pin, LOW);
    delay(duration-200);
  }
}
void loop() {
 pulse(LED_BUILTIN, 5, 500);
 pulse(LED_BUILTIN, 5, 2000);
}

//repository: https://github.com/brunocastro/Arduino/tree/master/coursera-specialization-iot/module2/alternate-blink