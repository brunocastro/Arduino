#include <IRremote.h>

int RECV_PIN = 11;
int relePin = 7;
int rele2Pin = 8;
int estado = 0;
int estado2 = 0;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(relePin, OUTPUT); 
  pinMode(rele2Pin, OUTPUT); 
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  estado = digitalRead (relePin);
  estado2 = digitalRead (rele2Pin);
  if (irrecv.decode(&results)) {
    // para ler resultados do controle;
    // Serial.println(results.value, HEX);

//Power autonomia máxima

    if (results.value == 0xFFA25D ) {
      if (estado == HIGH || estado2 ==HIGH ) {
        digitalWrite (relePin, LOW);
        digitalWrite (rele2Pin, LOW);
      } 
      else {
        digitalWrite (relePin, HIGH);
        digitalWrite (rele2Pin, HIGH);
      }
    }
//Alternador de estado do circuito 1 de leds      
    if (results.value == 0xFF30CF ) {
      if (estado == HIGH) {
        digitalWrite (relePin, LOW);
      }
      if (estado == LOW) {
        digitalWrite (relePin, HIGH);
      }
    }
//Alternador de estado do circuito 2 de leds      
    if (results.value == 0xFF18E7 ) {
      if (estado2 == HIGH) {
        digitalWrite (rele2Pin, LOW);
      }
      if (estado2 == LOW) {
        digitalWrite (rele2Pin, HIGH);
      }
    }
    irrecv.resume(); // Receive the next value
  }
}




