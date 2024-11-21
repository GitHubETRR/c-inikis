#include <UTFT.h>

#define IZQUIERDA 11 // ARRIBA
#define SELECCION 12 // SELECCIONAR
#define DERECHA 13 // ABAJO
#define LAMPARA 10 // 

#define opcion1 0
#define opcion2 1
#define opcion3 2
#define opcion4 3
#define opcion5 4 //easter egg

#define SECUENCIA_EASTER_EGG_MAX 7

using namespace std;

UTFT myGLCD(ITDB32S, 38, 39, 40, 41);

// Declarar la fuente
extern uint8_t BigFont[];

const char* opciones[] = {
  "Opcion 1",
  "Opcion 2",
  "Opcion 3",
  "Lamparita"
};
int totalOpciones = 4;

int Lampara = 0;

int opcionSeleccionada = 0;
bool enMenuPrincipal = true;

unsigned long lastMillis = 0;
const long debounceTime = 200;

//easter egg
const int SECUENCIA_EASTER_EGG[SECUENCIA_EASTER_EGG_MAX] = {IZQUIERDA, IZQUIERDA, DERECHA, DERECHA, IZQUIERDA, DERECHA, SELECCION};
int secuenciaUsuario[SECUENCIA_EASTER_EGG_MAX] = {0, 0, 0, 0, 0, 0, 0};

void evaluarEasterEgg(int opcionUsuario);

void setup() {
  pinMode(IZQUIERDA, INPUT_PULLUP);
  pinMode(SELECCION, INPUT_PULLUP);
  pinMode(DERECHA, INPUT_PULLUP);
  pinMode(LAMPARA, OUTPUT);

  myGLCD.InitLCD();
  myGLCD.setFont(BigFont);
  myGLCD.clrScr();
  myGLCD.setBrightness(16);
  myGLCD.setContrast(64);
  mostrarMenu();

  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  int izquierda = digitalRead(IZQUIERDA);
  int derecha = digitalRead(DERECHA);
  int seleccion = digitalRead(SELECCION);

  if (currentMillis - lastMillis >= debounceTime) {
    if (izquierda == LOW) {
      evaluarEasterEgg(IZQUIERDA);
      opcionSeleccionada--;  //
      if (opcionSeleccionada < 0) {
        opcionSeleccionada = totalOpciones - 1;
      }
      mostrarMenu();
      lastMillis = currentMillis;
    }

    if (derecha == LOW) {
      evaluarEasterEgg(DERECHA);
      opcionSeleccionada++;
      if (opcionSeleccionada >= totalOpciones) {
        opcionSeleccionada = 0;
      }
      mostrarMenu();
      lastMillis = currentMillis;
    }

    if (seleccion == LOW) {
      evaluarEasterEgg(SELECCION);
      ejecutarAccion();
      enMenuPrincipal = false;
      lastMillis = currentMillis;
    }
  }

  if (!enMenuPrincipal && currentMillis - lastMillis >= 2000) {
    enMenuPrincipal = true;
    mostrarMenu();
  }
}

void mostrarMenu() {
  myGLCD.clrScr();
  myGLCD.fillScr(255, 255, 255);
  myGLCD.setColor(0, 0, 0);
  myGLCD.setBackColor(255, 255, 255);

  myGLCD.print("Menu Principal", CENTER, 30);

  // Mostrar las opciones
  for (int i = 0; i < totalOpciones; i++) {
    if (i == opcionSeleccionada) {
      myGLCD.setColor(255, 0, 0);
    } else {
      myGLCD.setColor(0, 0, 0);
    }
    myGLCD.print(opciones[i], CENTER, 60 + i * 30);
  }

  myGLCD.setColor(0, 0, 0);
}

void ejecutarAccion() {
  myGLCD.clrScr();
  myGLCD.fillScr(255, 255, 255);

  switch (opcionSeleccionada) {
    case opcion1:
      myGLCD.print("Ejecutando Opcion 1", CENTER, 110);
      break;
    case opcion2:
      myGLCD.print("Ejecutando Opcion 2", CENTER, 110);
      break;
    case opcion3:
      myGLCD.print("Ejecutando Opcion 3", CENTER, 110);
      break;
    case opcion4:
      if (Lampara == 0) {
        myGLCD.print("Lampara prendida", CENTER, 110);
        digitalWrite (LAMPARA, HIGH);
        Lampara = 1;
        delay(500);

      } else if (Lampara == 1) {
        myGLCD.print("Lampara apagada", CENTER, 110);
        digitalWrite (LAMPARA, LOW);
        Lampara = 0;
        delay(500);
      }
      break;
     case opcion5:
      myGLCD.print("XD", CENTER, 110);
      break;
    default:
      break;
  }

  delay(4000);
  mostrarMenu();
}

void evaluarEasterEgg(int opcionUsuario) {
  // añadir la opcion del usuario
  for (int i = 0; i <= SECUENCIA_EASTER_EGG_MAX; i++) {
    if (secuenciaUsuario[i] == 0) {
      secuenciaUsuario[i] = opcionUsuario;
      break;
    }
  }
  
  for (int i = 0; i <= SECUENCIA_EASTER_EGG_MAX - 1; i++) {
    Serial.print(secuenciaUsuario[i]);
    Serial.print(" ");
  }
  Serial.println("");
  
  for (int i = 0; i <= SECUENCIA_EASTER_EGG_MAX; i++) {
    if (secuenciaUsuario[i] == SECUENCIA_EASTER_EGG[i]) {
      continue;
    } else if (secuenciaUsuario[i] == 0) {
      // no se termino de llenar la secuencia del usuario, OMITIR!!!!!
      return;
    } else { //secuencia usuario no es igual a la secuencia
      //el usuario ingreso mal un caracter, reiniciar
      for (int i = 0; i <= SECUENCIA_EASTER_EGG_MAX; i++) {
        secuenciaUsuario[i] = 0;
      }
      return;
    }
  }
  //EASTER EGG INGRESADO
  opcionSeleccionada = opcion5;
}
