#include <Stepper.h>

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

#define PASOS 2048

Stepper motor(PASOS, IN1, IN3, IN2, IN4);

void setup() {
  // put your setup code here, to run once:
  motor.setSpeed(15);

  pinMode(IN1, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.step(PASOS);
  delay(2000);
  motor.step(-PASOS);
  delay(2000);
  motor.step(PASOS/4);
  delay(1000);
  motor.step(PASOS/4);
  delay(1000);
  motor.step(PASOS/4);
  delay(1000);
  motor.step(PASOS/4);
  delay(4000);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW);

  for(int i = 0; i <=10; i++){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
