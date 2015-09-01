#define echoPin 7 //Pino 7 recebe o pulso do echo  
#define trigPin 6 //Pino 6 envia o pulso para gerar o echo  
int ledPin = 8;                // LED conectado ao pino digital 13
int value = LOW;                // último valor do LED
long previousMillis = 0;        // último momento que o LED foi atualizado
long intervalo = 1;           // tempo de transição entre estados (milisegundos)

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
    intervalo = map(distancia, 0, 150, 50, 500);
      
Serial.print("Distancia em CM: ");  
Serial.println(distancia);  

  if (millis() - previousMillis > intervalo) {
    previousMillis = millis();   // lembre-se do último tempo que piscamos o LED
    // se o LED está apagado, acenda-o e vice-versa.
    if (value == LOW)
      value = HIGH;
    else
      value = LOW;
    digitalWrite(ledPin, value);
  }
}
