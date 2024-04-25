int opcion;
typedef enum{
  piso1 = 1,
  piso2 = 2,
  piso3 = 3
}ascensor;
ascensor piso = piso1;

void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.print(" piso: ");
  Serial.println(piso);
  opcion = Serial.read();
  delay(2000);
  
  switch (piso){
    case piso1:
       if(piso == '1'){
        Serial.println("piso actual: 1");
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
       if(opcion == '2'){
        Serial.println("piso actual: 2");
       }
       if(opcion == '3'){
        Serial.println("Subiendo...");
        piso = piso3;
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