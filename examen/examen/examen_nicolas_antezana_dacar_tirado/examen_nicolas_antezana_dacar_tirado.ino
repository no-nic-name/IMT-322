#include <stdlib.h> // librería para generar números aleatorios

#define PLAY_PAUSE_BTN 2
#define SIGUIENTE_CANCION_BTN 3
#define ANTERIOR_CANCION_BTN 4
#define VOLUMEN_BTN 5

#define TIEMPO_CANCION 30000 // 30 segundos
#define NUMERO_CANCIONES 50

#define DEBOUNCE_DELAY 200 // Tiempo de antirrebote (ms)

volatile bool btnPlayPausePressed = false;
volatile bool btnSiguienteCancionPressed = false;
volatile bool btnAnteriorCancionPressed = false;
volatile bool btnVolumenPressed = false;

volatile bool isPlaying = false;
volatile bool isPaused = false;

volatile uint8_t indiceCancion = 0;
volatile unsigned long tiempoInicioCancion = 0;
volatile unsigned long tiempoUltimoPulsador = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PLAY_PAUSE_BTN, INPUT_PULLUP);
  pinMode(SIGUIENTE_CANCION_BTN, INPUT_PULLUP);
  pinMode(ANTERIOR_CANCION_BTN, INPUT_PULLUP);
  pinMode(VOLUMEN_BTN, INPUT_PULLUP);
}

void loop() {
  unsigned long tiempoActual = millis();
  if (tiempoActual - tiempoUltimoPulsador >= DEBOUNCE_DELAY) {
    btnPlayPausePressed = digitalRead(PLAY_PAUSE_BTN) == LOW;
    btnSiguienteCancionPressed = digitalRead(SIGUIENTE_CANCION_BTN) == LOW;
    btnAnteriorCancionPressed = digitalRead(ANTERIOR_CANCION_BTN) == LOW;
    btnVolumenPressed = digitalRead(VOLUMEN_BTN) == LOW; // Opcional
    tiempoUltimoPulsador = tiempoActual;
  }

  if (isPlaying && !isPaused) {
    if (millis() - tiempoInicioCancion >= TIEMPO_CANCION) {
      siguienteCancion();
    }
  }

  if (btnPlayPausePressed) {
    if (isPlaying) {
      pausarReproduccion();
    } else {
      reanudarReproduccion();
    }
    btnPlayPausePressed = false;
  }

  if (btnSiguienteCancionPressed) {
    siguienteCancion();
    btnSiguienteCancionPressed = false;
  }

  if (btnAnteriorCancionPressed) {
    anteriorCancion();
    btnAnteriorCancionPressed = false;
  }

  if (btnVolumenPressed) {
    // Implementar control de volumen (opcional)
    btnVolumenPressed = false;
  }

  // Mostrar el tiempo transcurrido de la canción actual
  Serial.print("Tiempo transcurrido: ");
  Serial.print((millis() - tiempoInicioCancion) / 1000);
  Serial.println(" segundos");

  delay(100); // Evitar bucle infinito
}

void siguienteCancion() {
  indiceCancion++;
  if (indiceCancion >= NUMERO_CANCIONES) {
    indiceCancion = 0;
  }
  // Agregar un número aleatorio al segundo de la canción
  int aleatorio = random(1, 10); // Número aleatorio entre 1 y 10
  tiempoInicioCancion = millis() + aleatorio * 1000; // Aumentar el segundo de la canción
  Serial.print("Reproduciendo canción ");
  Serial.print(indiceCancion + 1);
  Serial.print(" - Segundo: ");
  Serial.println((tiempoInicioCancion - millis()) / 1000);
}

void anteriorCancion() {
  if (indiceCancion > 0) {
    indiceCancion--;
  } else {
    indiceCancion = NUMERO_CANCIONES - 1;
  }
  int aleatorio = random(1, 10); // Número aleatorio entre 1 y 10
  tiempoInicioCancion = millis() + aleatorio * 1000; // Aumentar el segundo de la canción
  Serial.print("Reproduciendo canción ");
  Serial.print(indiceCancion + 1);
  Serial.print(" - Segundo: ");
  Serial.println((tiempoInicioCancion - millis()) / 1000);
}

void pausarReproduccion() {
  isPlaying = false;
  isPaused = true;
  Serial.println("Reproducción pausada");
}

void reanudarReproduccion() {
  isPlaying = true;
  isPaused = false;
  Serial.println("Reproducción reanudada");
}
