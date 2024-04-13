#define   LED  2
#define   BUTTON  3 

volatile int counter = 0; 

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(BUTTON), ISR_buttonPressed, RISING);

  digitalWrite(LED, LOW);

  Serial.begin(9600);
  Serial.print("INCICIO");
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
  //Serial.println(counter);
}

void ISR_buttonPressed() {

  counter++;

  //Serial.print("Contador: ");
  Serial.println(counter);
}