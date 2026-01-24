/*
 * Clase encargada para el control del flotador de nivel de agua
 */
#pragma once
#include <Arduino.h>

class NivelAgua {
private:
    uint8_t pin;

public:
    NivelAgua(uint8_t pinSensor);
    void init();
    bool nivelAlto();
    bool nivelBajo();
};
