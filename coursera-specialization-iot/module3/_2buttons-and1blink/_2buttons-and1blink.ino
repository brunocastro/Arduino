/*
 Exercise of Coursera iot specialization - interface-with-arduino
*/

#define BTN1 8
#define BTN2 9

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BTN1, OUTPUT);
  pinMode(BTN2, OUTPUT);
}

void loop() {
  if (digitalRead(BTN1) && digitalRead(BTN2)) {
    digitalWrite(LED_BUILTIN, HIGH);   
  } else {
    digitalWrite(LED_BUILTIN, LOW); 
  }
}
