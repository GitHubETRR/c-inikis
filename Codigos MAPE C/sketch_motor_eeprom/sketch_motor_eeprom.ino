#include <Stepper.h>
#include <EEPROM.h>

#define PRINT(x) Serial.print(x)

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

#define PASOS 2048

Stepper motor(PASOS, IN1, IN3, IN2, IN4);

void movimiento_func(int cantidad);
int leer_movimiento_eeprom(int direccion); //lee los bytes en la EEPROM del struct movimiento
int buscar_progreso_anterior(); //busca en la EEPROM el progreso guardado
void verificar_movimiento_terminado(); //verifica si el movimiento guardado en la eeprom se terminó
int vueltas_input = 0;

typedef struct {
  int pos_actual = 0;
  int cantidad = 0;
}movimiento_struct;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor.setSpeed(15);
  
  verificar_movimiento_terminado()
  
  PRINT("Ingrese la cantida de octavos de vuelta que desea:");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    vueltas_input = Serial.readString().toInt() * (PASOS/8); //esto lo convierte a los pasos necesarios
    movimiento_func(vueltas_input);
    verificar_movimiento_terminado();
  }
}

void movimiento_func(int cantidad){
  PRINT("\nSe va a crear un nuevo movimiento de cantidad ");
  PRINT(cantidad);
  PRINT("\n");
  
  movimiento_struct nuevoMovimiento;
  nuevoMovimiento.cantidad = cantidad; //avanza a un cuarto de una vuelta
  
  for (int i = 0; i <= nuevoMovimiento.cantidad; i++){
    motor.step(1);
    nuevoMovimiento.pos_actual = i;
    EEPROM.put(0, nuevoMovimiento);
    PRINT(nuevoMovimiento.pos_actual);
    PRINT(" ; ");
    PRINT(nuevoMovimiento.cantidad);
    PRINT("\n");
  }
  
  PRINT("Movimiento terminado.\n");
}

int leer_movimiento_eeprom(int direccion){
  byte lowByte = EEPROM.read(direccion);
  byte highByte = EEPROM.read(direccion + 1);
  return (highByte << 8) | lowByte;
}

int buscar_progreso_anterior(){
  int progreso = leer_movimiento_eeprom(0);
  int cantidad = leer_movimiento_eeprom(2);

  if (progreso!=cantidad){
    if (progreso>cantidad){
      return 0;
    }
    return cantidad - progreso;
  }
  return 0;
}

void verificar_movimiento_terminado(){
  PRINT("\nBuscando movimientos anteriores...\n");
  int progreso_anterior = buscar_progreso_anterior();
  
  if (progreso_anterior) {
    movimiento_func(progreso_anterior);
  }
  else{ PRINT("No se encontró ningún movimiento\n"); }
}
