//practica 4 punto 2

#define     BTN1  2 
#define     BTN2  3 
#define     LED1  4


volatile int cont =0;
volatile unsigned long lasttime=0;
volatile unsigned long Delay=10;
volatile bool reset = false;


typedef enum{
  v1=500,
  v2=1000,
  v3=1500
}velocidad;
velocidad velocidadActual=v1;

void setup() {

  Serial.begin(9600);
  pinMode(BTN1,INPUT_PULLUP);
  pinMode(BTN2,INPUT_PULLUP);
  pinMode(LED1,OUTPUT);

  attachInterrupt(digitalPinToInterrupt(BTN1),counter,RISING);
  attachInterrupt(digitalPinToInterrupt(BTN2),vel,RISING);
  
}

void loop() {

  digitalWrite(LED1, HIGH);
  delay(velocidadActual);
  digitalWrite(LED1,LOW);
  delay(velocidadActual);

}

void counter(){
  if (millis() - lasttime > Delay) {
    if (digitalRead(BTN1) == HIGH) { 
      cont++;
      Serial.println("contador");
      Serial.println(cont);
    } else { 
      if (millis() - lasttime >= 3000) { 
        cont=0;
        Serial.println("contador");
        Serial.println(cont);
      }
    }
    lasttime = millis();
  }
}
void vel(){
  if(millis()-lasttime>Delay){
    lasttime=millis();
    switch (velocidadActual){
      case 1:
      velocidadActual=v2;
      break;
      case 2:
      velocidadActual=v3;
      break;
      case 3:
      velocidadActual=v1;
      break;
    }
    
    Serial.print("Velocidad actual ");
    Serial.println(velocidadActual);
  }
}