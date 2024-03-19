// practica 3 punto 1

#define CONT  2
#define RESET 3
#define LED1  4

volatile unsigned long lasttime = 0;
volatile unsigned long Delay = 10; 

volatile int contador = 0;

void setup() {
  
  pinMode(CONT, INPUT_PULLUP);
  pinMode(RESET, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(CONT), counter, RISING);
  attachInterrupt(digitalPinToInterrupt(RESET), reset, RISING);
 
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(LED1, HIGH);
  delay(200);
  digitalWrite(LED1, LOW);
  delay(200);
}

void counter() {

  if (millis() - lasttime > Delay) {
    contador++;
    lasttime = millis();
    Serial.println("Contador");
    Serial.println(contador);
  }
}

void reset() {
  if (millis() - lasttime > Delay) {
    contador=0;
    lasttime = millis();
    Serial.println("Contador");
    Serial.println(contador);
  }
}
