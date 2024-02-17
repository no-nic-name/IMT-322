/*
	Capitulo 33 de Arduino desde cero en Español.
	Simple programa para controlar un motor del tipo bipolar NEMA 17 mediante el
	controlador driver A4988 logrando un giro de media vuelta en un sentido y en otro

	Autor: bitwiseAr  

*/

#define STEP 10			// pin STEP de A4988 a pin 4
#define DIR 9		// pin DIR de A4988 a pin 5

void setup() 
{
  pinMode(STEP, OUTPUT);	// pin 4 como salida
  pinMode(DIR, OUTPUT);		// pin 5 como salida
}

void loop() 
{
  digitalWrite(DIR, HIGH);		// giro en un sentido
  for(int i = 0; i < 1000; i++){   	// 200 pasos para motor de 0.9 grados de angulo de paso
    digitalWrite(STEP, HIGH);     	// nivel alto
    delay(1);			  	// por 10 mseg
    digitalWrite(STEP, LOW);      	// nivel bajo
    delay(1);			  	// por 10 mseg
  }
  delay(2000);			  	// demora de 2 segundos

  digitalWrite(DIR, LOW);	  	// giro en sentido opuesto
  for(int i = 0; i < 1000; i++){
    digitalWrite(STEP, HIGH); 
    delay(1);
    digitalWrite(STEP, LOW);
    delay(1);
  }
  delay(2000);			  	// demora de 2 segundos
}