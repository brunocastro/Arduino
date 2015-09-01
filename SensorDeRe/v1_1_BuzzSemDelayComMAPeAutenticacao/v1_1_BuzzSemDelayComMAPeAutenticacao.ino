int echoPin = 7; //Pino 7 recebe o pulso do echo  
int trigPin = 6; //Pino 6 envia o pulso para gerar o echo  
int ledPin = 8; // Pino 8 recebe BUZZ

//  Variaveis Globais - Registro de Estados
int value = LOW;                // último valor do LED
long previousMillis = 0;        // último momento que o LED foi atualizado
long intervalo = 0;           // tempo de transição entre estados (milisegundos)
long duracao = 70;

void setup()
{
  Serial.begin(9600); //inicia a porta serial  
  pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)  
  pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)  
  pinMode(ledPin, OUTPUT);      // configura o pino digital como saída
}

void loop()
{
  //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0  
  digitalWrite(trigPin, LOW);  
  // delay de 2 microssegundos  
  delayMicroseconds(2);  
  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1  
  digitalWrite(trigPin, HIGH);  
  //delay de 10 microssegundos  
  delayMicroseconds(10);  
  //seta o pino 12 com pulso baixo novamente  
  digitalWrite(trigPin, LOW);  
  //pulseInt lê o tempo entre a chamada e o pino entrar em high  
  long duration = pulseIn(echoPin,HIGH);  
  //Esse calculo é baseado em s = v . t, lembrando que o tempo vem dobrado  
  //porque é o tempo de ida e volta do ultrassom  
  long distancia = duration /29 / 2 ;  
  intervalo = map(distancia, 0, 200, 60, 400);

  ///////////////// Monitor Serial
  Serial.print("Distancia em CM: ");  
  Serial.println(distancia); 

  if (distancia > 3 && distancia < 200){
    if (value == LOW) {
      if (millis() - previousMillis > intervalo) {
        previousMillis = millis();   // lembre-se do último tempo que piscamos o LED
        value = HIGH;
      }
    }
    if (value == HIGH) {
      if (millis() - previousMillis > duracao) {
        previousMillis = millis();   // lembre-se do último tempo que piscamos o LED
        // se o LED está apagado, acenda-o e vice-versa.
        value = LOW;
      }
    }
  }
  if (distancia < 3 && distancia > 1 ) {
    value = HIGH;
  }
  if (distancia > 200 || distancia == 0) {
    value = LOW;
  }
  digitalWrite(ledPin, value);
}




