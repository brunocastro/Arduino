#define ECHOPIN 7
#define TRIGPIN 6
#define BUZZERPORT 8
#define LEDPORT 10

void setup()
{
  //inicia a porta serial
  Serial.begin(9600);

  //configura o ultrasom
  pinMode(ECHOPIN, INPUT); // define o pino como entrada (recebe)
  pinMode(TRIGPIN, OUTPUT); // define o pino como saida (envia)

  //configura o buzzer
  pinMode(BUZZERPORT, OUTPUT);
  pinMode(LEDPORT, OUTPUT);
}

void debugSerial(char custonText[], int value) {
  Serial.print(custonText);
  Serial.println(value);
}

int ultrasonicRead () {
  //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0
  digitalWrite(TRIGPIN, LOW);
  // delay de 2 microssegundos
  delayMicroseconds(2);
  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1
  digitalWrite(TRIGPIN, HIGH);
  //delay de 10 microssegundos
  delayMicroseconds(10);
  //seta o pino 12 com pulso baixo novamente
  digitalWrite(TRIGPIN, LOW);
  //pulseInt lê o tempo entre a chamada e o pino entrar em high
  long duration = pulseIn(ECHOPIN, HIGH);
  //Esse calculo é baseado em s = v . t, lembrando que o tempo vem dobrado
  //porque é o tempo de ida e volta do ultrassom
  long distance = duration / 29 / 2 ;
  return distance;
}

void makeBuzz (int pin, int frequence, int duration) {
  if ( frequence <= 50) {
      tone(pin,frequence * 45, duration);
  }
}

void loop()
{
  int resultado = ultrasonicRead();
  debugSerial("distancia em cm: ", resultado);
  makeBuzz(BUZZERPORT, resultado, 100);
}




