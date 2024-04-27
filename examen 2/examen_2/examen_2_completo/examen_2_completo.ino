#include "funciones.h"
int saldo = 0; 

#define PRECIO1  2
#define PRECIO2  5
#define PRECIO3  7
#define BR       9600
#define SERVIR1  5000
#define SERVIR2  4000
#define SERVIR3  6000
#define DELAY    5000
#define BUTTON   2
bool ss = false;

typedef enum{
  VC,
  TE,
  CAFE,
  SODA
  
} maquina;
maquina opcion =TE;


void setup() {
  Serial.begin(BR);
  pinMode(BUTTON,INPUT_PULLUP);
}

void loop() {
  
  Serial.println("bienvenido a la maquina expendedora Ingrese el dinero:");
  while (Serial.available() == 0) {}
  int monto = Serial.parseInt();
  saldo += monto;
  delay(delay);
  Serial.print("Saldo actual: ");
  Serial.println(saldo);


  Serial.println("Seleccione una bebida con un el numero en los siguientes 5 segundos : ");
  Serial.println("1. te   - Precio: 2bs");
  Serial.println("2. cafe - Precio: 5bs");
  Serial.println("3. Soda - Precio: 7bs");
  delay(DELAY);

  
  while (Serial.available() == 0) {}
  int opcion = Serial.parseInt();
  if (opcion >= 1 && opcion <= 3) {
    int precio_bebida = 0;
    switch(opcion) {
      case TE:
        precio_bebida = PRECIO1;
        Serial.print("bebida seleccionada ");
        Serial.println(opcion);
        Serial.print("sirviendo");
        mostrarBarraDeCarga(SERVIR1);
        //delay(SERVIR1);

        break;
      case CAFE:
        precio_bebida = PRECIO2;
        Serial.print("bebida seleccionada ");
        Serial.println(opcion);
        Serial.print("sirviendo");
        mostrarBarraDeCarga(SERVIR2);
        //delay(SERVIR2);
        break;
      case SODA:
        precio_bebida = PRECIO3;
        Serial.print("bebida seleccionada ");
        Serial.println(opcion);
        Serial.print("sirviendo");
        mostrarBarraDeCarga(SERVIR3);
        //delay(SERVIR3);
        break;
    }
    if (saldo >= precio_bebida) {
      int cambio = saldo - precio_bebida;
  
      Serial.println("Su cambio es: ");
      Serial.println(cambio);
      saldo = 0; 
      ss = true;
      
    } else {
      Serial.println("Saldo insuficiente para comprar esta bebida");
    }
  } else {
    Serial.println("Opción inválida.");
  }
  
}