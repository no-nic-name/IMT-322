#define ROJO      2
#define AMARILLO   4
#define VERDE     7
typedef enum{
  LROJO,
  LAMARILLO,
  LVERDE
} semaforo;
semaforo estados=LROJO;
int estado = 0; 
void setup() {
  pinMode(ROJO, OUTPUT);
  pinMode(AMARILLO, OUTPUT);
  pinMode(VERDE, OUTPUT);
}

void loop() {
  switch (estados) {
    case LROJO:  
      digitalWrite(ROJO, HIGH);
      digitalWrite(AMARILLO, LOW);
      digitalWrite(VERDE, LOW);
      delay(3000);
      estados = LAMARILLO;
      break;
    case LAMARILLO:  
      digitalWrite(ROJO, LOW);
      digitalWrite(AMARILLO, HIGH);
      digitalWrite(VERDE, LOW);
      delay(1000);
      estados = LVERDE;
      break;
    case LVERDE:  
      digitalWrite(ROJO, HIGH);
      digitalWrite(AMARILLO, LOW);
      digitalWrite(VERDE, LOW);
      delay(3000);
      estados = LROJO;
      break;
  }
}


