#include <RaulDisp.h>

Pantalla pantalla;

// Datos de pruebas para el parrafo
const char* texto[] = {
    "Hola",
    "Raul",
    "Prueba de parrafo"
};
// Datos de prueba para el grafico
int valores[] = {10, 20, 30, 25, 40, 50, 45};

void setup()
{
    Serial.begin(115200);
    pantalla.init(D2, D1); // SDA, SCL
}

void loop()
{
    delay(6000);
    pantalla.escribeTexto("Hola Raul");
    delay(6000);
    pantalla.borrarPantalla();
    delay(6000);
    pantalla.escribeParrafo(texto, 3);
    delay(6000);
    pantalla.dibujaBarra(75, 100);
    delay(6000);
    pantalla.dibujaGrafico(valores, 7);
}
