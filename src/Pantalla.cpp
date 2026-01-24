#include "Pantalla.hpp"

Pantalla::Pantalla()
    : display(ANCHO, ALTO, &Wire, -1)
{
}

/**
 * Inicializa la pantalla
 */
void Pantalla::init(uint8_t SDA, uint8_t SCL)
{
    Wire.begin(SDA, SCL);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println("Pantalla no encontrada");
        while (true)
            ;
    }

    display.clearDisplay();
    display.display();
}

/**
 * Escribe texto en la pantalla
 */
void Pantalla::escribeTexto(const String &texto)
{
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(texto);
    display.display();
}

/**
 * Escribe un parrafo
 */
void Pantalla::escribeParrafo(const char *lineas[], uint8_t numLineas)
{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    int y = 0;

    for (uint8_t i = 0; i < numLineas; i++)
    {
        display.setCursor(0, y);
        display.println(lineas[i]);
        y += 10;
    }

    display.display();
}

/**
 * Borra la pantalla
 */
void Pantalla::borrarPantalla()
{
    display.clearDisplay();
    display.display();
}

/**
 * Dibuja una linea
 */
void Pantalla::dibujaLinea(int x0, int y0, int x1, int y1)
{
    display.drawLine(x0, y0, x1, y1, SSD1306_WHITE);
    display.display();
}

/**
 * Dibuja una recta
 */
void Pantalla::dibujaRect(int x, int y, int w, int h, bool relleno)
{
    if (relleno)
        display.fillRect(x, y, w, h, SSD1306_WHITE);
    else
        display.drawRect(x, y, w, h, SSD1306_WHITE);

    display.display();
}

/**
 * Dibuja un circulo
 */
void Pantalla::dibujaCirculo(int x, int y, int r, bool relleno)
{
    if (relleno)
        display.fillCircle(x, y, r, SSD1306_WHITE);
    else
        display.drawCircle(x, y, r, SSD1306_WHITE);

    display.display();
}

/**
 * Dibuja una barra de progreso
 */
void Pantalla::dibujaBarra(int valor, int maximo, bool dato)
{
    display.clearDisplay();

    int ancho = map(valor, 0, maximo, 0, 120);

    display.drawRect(4, 20, 120, 20, SSD1306_WHITE);
    display.fillRect(4, 20, ancho, 20, SSD1306_WHITE);

    display.setCursor(4, 0);
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    if (dato)
    {
        display.print("Valor: ");
        display.println(valor);
    }

    display.display();
}

/**
 * Dibuja un grafico
 */
void Pantalla::dibujaGrafico(const int datos[], uint8_t n)
{
    display.clearDisplay();

    for (uint8_t i = 1; i < n; i++)
    {
        int x0 = (i - 1) * (128 / n);
        int y0 = 64 - datos[i - 1];
        int x1 = i * (128 / n);
        int y1 = 64 - datos[i];

        display.drawLine(x0, y0, x1, y1, SSD1306_WHITE);
    }

    display.display();
}
