#include <RaulDisp.h>

NivelAgua nivel(D1);
Pantalla pantalla;

void setup() {
    Serial.begin(115200);
    nivel.init();
    pantalla.init(D4, D3); // SDA, SCL
}

void loop() {
    if (nivel.nivelAlto()) {
        Serial.println("Depósito lleno");
        pantalla.dibujaBarra(100, 100);
    } else {
        Serial.println("Depósito vacío");
        pantalla.dibujaBarra(10, 100);
    }

    delay(1000);
}
