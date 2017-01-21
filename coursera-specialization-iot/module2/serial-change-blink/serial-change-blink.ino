void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void changeBlink (int sValue,int pinLed) {
  if (sValue==49) {
      digitalWrite(pinLed, HIGH);  
    } else if (sValue==48) {
      digitalWrite(pinLed, LOW);
    }
}

void loop() {
  if (Serial.available() > 0) {
    int byteRecived = Serial.read();
    changeBlink(byteRecived, LED_BUILTIN);
  }
}

//repository: https://github.com/brunocastro/Arduino/tree/master/coursera-specialization-iot/module2/serial-change-blink
