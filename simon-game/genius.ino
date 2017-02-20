#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5

#define BTN1 8
#define BTN2 9
#define BTN3 10
#define BTN4 11

unsigned long previousMillis = 0;
unsigned long currentMillis = 0;

void debugSerial(char custonText[], int value) {
  Serial.print(custonText);
  Serial.println(value);
}

//void blink (int pin, int duration) {
//  digitalWrite (pin, HIGH);
//  currentMillis = millis();
//  if (currentMillis - previousMillis >= duration) {
//    previousMillis = currentMillis;
//    digitalWrite (pin, LOW);
//  }
//}

void blink (int pin, int duration) {
  digitalWrite (pin, HIGH);
  delay (duration);
  digitalWrite (pin, LOW);
}

void setup() {
  Serial.begin(9600); //inicia a porta serial  
  // define leds
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  
  pinMode(BTN1, OUTPUT);
  pinMode(BTN2, OUTPUT);
  pinMode(BTN3, OUTPUT);
  pinMode(BTN4, OUTPUT);
  
}

int state[ ] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int turnOff (int pin) {
  int pinState = digitalRead(pin);  
  if (pinState == HIGH && state[pin]==0) {
    state[pin] = 1;
    return false;
  } else if (pinState == LOW && state[pin]==1) {
    state[pin] =0;
    delay(50);
    return true;
  } else {
    return false;
  }
}

void loop() {
  if (turnOff(BTN1)) {
  debugSerial ("unpressed bt 1 na porta:",BTN1);
  blink (LED1, 200);
  } else if (turnOff(BTN2)) {
  debugSerial ("unpressed bt 2 na porta:",BTN2);
  blink (LED2, 200);
  } else if (turnOff(BTN3)) {
  debugSerial ("unpressed bt 3 na porta:",BTN3);
  blink (LED3, 200);
  } else if (turnOff(BTN4)) {
  debugSerial ("unpressed bt 4 na porta:",BTN4);
  blink (LED4, 200);
  }
}
