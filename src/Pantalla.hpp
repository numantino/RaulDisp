/*
 * Clase encargada de poder escribir en  una pantalla
 */
#pragma once
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO 128
#define ALTO 64

class Pantalla
{
private:
    Adafruit_SSD1306 display;

public:
    Pantalla(); // constructor
    void init(uint8_t SDA, uint8_t SCL);

    void escribeTexto(const String &texto);
    void escribeParrafo(const char *lineas[], uint8_t numLineas);

    void borrarPantalla();

    // Graficos
    void dibujaLinea(int x0, int y0, int x1, int y1);
    void dibujaRect(int x, int y, int w, int h, bool relleno = false);
    void dibujaCirculo(int x, int y, int r, bool relleno = false);
    void dibujaBarra(int valor, int maximo, bool dato = true);
    void dibujaGrafico(const int datos[], uint8_t n);
};
