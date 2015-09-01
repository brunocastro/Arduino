#include <IRremote.h>

int RECV_PIN = 11;
int ledPin = 7;
int led2Pin = 8;
int estado = 0;
int estado2 = 0;
IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); 
  pinMode(led2Pin, OUTPUT); 
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  estado = digitalRead (ledPin);
  estado2 = digitalRead (led2Pin);
  if (irrecv.decode(&results)) {
    // para ler resultados do controle;
    Serial.println(results.value, HEX);

//Power autonomia máxima

    if (results.value == 0x76044FC0 ) {
      if (estado == HIGH || estado2 ==HIGH ) {
        digitalWrite (ledPin, LOW);
        digitalWrite (led2Pin, LOW);
      } 
      else {
        digitalWrite (ledPin, HIGH);
        digitalWrite (led2Pin, HIGH);
      }
    }
//Alternador de estado do circuito 1 de leds      
    if (results.value == 0x76044FE0 ) {
      if (estado == HIGH) {
        digitalWrite (ledPin, LOW);
      }
      if (estado == LOW) {
        digitalWrite (ledPin, HIGH);
      }
    }
//Alternador de estado do circuito 2 de leds      
    if (results.value == 0x76044FD0 ) {
      if (estado2 == HIGH) {
        digitalWrite (led2Pin, LOW);
      }
      if (estado2 == LOW) {
        digitalWrite (led2Pin, HIGH);
      }
    }
    irrecv.resume(); // Receive the next value
  }
}




