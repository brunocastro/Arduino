#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  Serial.println("started! Write read our wirte for manipulate te eprom ports.");
}

void loop() {
  if (Serial.available() > 0) {
    String stringRecive = Serial.readString();
    if (stringRecive.substring(0,4) == "read") {
      String parameters= stringRecive.substring(5);
      int firstBracket = parameters.indexOf(" ");
      if (firstBracket == -1) {
        int addr = atoi(parameters.c_str()); //STRING to INT converter
        int value = EEPROM.read(addr); //EPROM READ
        Serial.print("Read a value ");
        Serial.print(value);
        Serial.print(" in EPROM port ");
        Serial.println(addr);
      } else {
        Serial.println("To use the 'read' command, you must enter one parameter sample: read 2");
      }
    } else if (stringRecive.substring(0,5) == "write") {
      String parameters= stringRecive.substring(6);
      int firstBracket = parameters.indexOf(" ");
      int otherBracket = parameters.indexOf(" ", firstBracket+1);
      if (otherBracket == -1 and firstBracket != -1) {
        int addr = atoi(parameters.substring(0,firstBracket).c_str());
        int value = atoi(parameters.substring(firstBracket+1).c_str());
        EEPROM.update(addr, value);
        Serial.print("Done! write in EPROM port ");
        Serial.print(addr);
        Serial.print(" the value ");
        Serial.println(value);
      } else {
        Serial.println("To use the 'write' command, you must enter two parameters sample: write 2 4");
      }
    } else {
      Serial.println("This is not a valid command. Try use erase or write.");
    }
  }
}
