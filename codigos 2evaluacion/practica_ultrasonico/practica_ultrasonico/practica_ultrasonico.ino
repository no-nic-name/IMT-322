  #define TRIG 2
  #define ECHO 9
  #define BUTTON 10
typedef enum{
  ESPERANDO,
  DISTANCIA,
  MOSTRAR
}ultrasonico;
ultrasonico estado = ESPERANDO;
  long t;
  long d;
  const int time = 50;
  long time0 = 0;
  long time1=0;
  long time2=0;
  void setup()
{
  pinMode(TRIG, INPUT_PULLUP);
  pinMode(ECHO, OUTPUT);
  pinMode(BUTTON, INPUT);
  digitalWrite(TRIG, LOW);
  attachInterrupt(digitalPinToInterrupt(BUTTON), distancia, RISING);
  Serial.begin(9600);
}
void loop()
{
  switch (estado)
  {
    case ESPERANDO:
    Serial.println("EN ESPERA PARA MEDICION");
    delay(2000);
    break;
    case DISTANCIA:
    digitalWrite(TRIG, HIGH);
    delay(10);
    digitalWrite(TRIG, LOW);
    t = pulseIn(ECHO, HIGH);
    d=t/60;
    if (time1==0)
    {
      time1=millis();
    }
    estado=MOSTRAR;
    break;
    case MOSTRAR:
    Serial.print(d);
    Serial.println(" cm.");
    time2=millis();
    if (time2-time1<5000)
    {
      estado= DISTANCIA;
    }
    else
    {
      time1=0;
      estado=ESPERANDO;
    }
    break;
  }
}
void distancia()
{
  if (millis()-time0 > time)
  {
    estado=DISTANCIA;
    Serial.println("DISTANCIA");
    time0=millis();
  }
}