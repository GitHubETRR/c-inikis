#include <Stepper.h>

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

#define PASOS 2048

Stepper motor(PASOS, IN1, IN3, IN2, IN4);

void blink(int ms);

int steps_input = 0;

void setup() {
  // put your setup code here, to run once:
  motor.setSpeed(15);

  Serial.begin(9600);

  Serial.println("Ingresar cantidad de pasos:");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    steps_input = Serial.readString().toInt();
    blink(250);
    Serial.print("Moviendo ");
    Serial.print(steps_input);
    Serial.print(" pasos.");
    motor.step(steps_input);
    blink(100);
    delay(100);
    blink(100);
    Serial.println(" Listo.");
  }
}

void blink(int ms){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(ms);
  digitalWrite(LED_BUILTIN, LOW);
}
