
int saldo = 0;

#define PRECIO1  10
#define PRECIO2  20
#define PRECIO3  30

typedef enum{
  bebida0 = 0,
  bebida1 = 1,
  bebida2 = 2,
  bebida3 = 3
}bebidas;
bebidas opcion = bebida0;


void setup() {
  Serial.begin(9600);
}
void loop() {
  if (Serial.available()>0){

  }
  Serial.print(" bebida seleccionada : ");
  Serial.println(opcion);
  opcion = Serial.read();
  delay(2000);
  
  switch (opcion){
    case bebida1:
       if(opcion == '1'){
        Serial.println("sirviendo");
       }
       if(opcion == '2'){
        Serial.println("Subiendo...");
        piso = piso2;
       }
       if(opcion == '3'){
        Serial.println("Subiendo...");
        piso = piso3;
       }
    break;

    case piso2:
       if(opcion == '1'){
        Serial.println("bajando...");
        piso = piso1;
       }
      
    break;

    case piso3:
       if(opcion == '1'){
        Serial.println("bajando...");
        piso = piso1;
       }
       if(opcion == '2'){
        Serial.println("bajando...");
        piso = piso2;
       }
       if(opcion == '3'){
        Serial.println("piso actual 3");
       }
    break;
  }
}