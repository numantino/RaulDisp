#include <NewPing.h>

const int TRIG_PIN = D1;
const int ECHO_PIN = D2;
const long MAX_DISTANCIA = 200;

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCIA);

void setup() {
    Serial.begin(9600);
}

void loop() {
    delay(50);
    Serial.print("Distancia ");
    Serial.print(sonar.ping_cm());
    Serial.println(" cm");
}