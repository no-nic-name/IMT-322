#define LED  2
#define LED1  4
#define BUTTON  3

volatile bool ledState = false; // Estado del LED (encendido/apagado)

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  // Configurar la interrupción para el pin del pulsador
  attachInterrupt(digitalPinToInterrupt(BUTTON), ISR_buttonPressed, RISING);

  // Inicializar el LED
  digitalWrite(LED, LOW);
  digitalWrite(LED1, LOW);

  // Inicializar la comunicación serial
  Serial.begin(9600);
}

void loop() {

  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
  Serial.print("Estado del LED: ");
  Serial.println(ledState ? "Encendido" : "Apagado");
}

// Función de interrupción para el pulsador
void ISR_buttonPressed() {
  // Invertir el estado del LED
  ledState = !ledState;

  // Encender o apagar el LED
  digitalWrite(LED1, ledState);
}
