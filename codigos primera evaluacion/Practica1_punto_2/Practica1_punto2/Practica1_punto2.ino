
#define   LED  2
#define   LED1  3
#define   LED2  4
#define   BUTTON  5 

int ledState = 0;

bool secuenciaNormal = true;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  digitalWrite(LED, LOW);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}

void loop() {
  
  if (digitalRead(BUTTON) == LOW) {
    secuenciaNormal = !secuenciaNormal;
  }

 
  if (secuenciaNormal) {
    switch (ledState) {
      case 1:
        digitalWrite(LED, HIGH);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        break;
      case 2:
        digitalWrite(LED, LOW);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        break;
      case 3:
        digitalWrite(LED, LOW);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        break;
    }
  } else {
    switch (ledState) {
      case 1:
        digitalWrite(LED, LOW);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        break;
      case 2:
        digitalWrite(LED, LOW);
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        break;
      case 3:
        digitalWrite(LED, HIGH);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        break;
    }
  }

  
  ledState++;
  if (ledState > 3) {
    ledState = 1;
  }

  delay(200);
}
