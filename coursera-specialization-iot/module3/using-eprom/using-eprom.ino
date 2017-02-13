#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  Serial.println("started");
}

void debugSerial(char custonText[], int value) {
  Serial.print(custonText);
  Serial.println(value);
}

void loop() {
  for (int addr = 0; addr < 12; addr++) {
    int value = random (254);
    EEPROM.update(addr, value);
    debugSerial("burn on ",addr);
  }
  for (int addr = 0; addr < 12; addr++) {
    int value = EEPROM.read(addr);
    debugSerial("the value is= ",value);
  }
}
