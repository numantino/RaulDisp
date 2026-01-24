#include "NivelAgua.hpp"

NivelAgua::NivelAgua(uint8_t pinSensor)
: pin(pinSensor)
{
}

void NivelAgua::init() {
    pinMode(pin, INPUT_PULLUP);
}

/**
 * Flotador cerrado
 */
bool NivelAgua::nivelAlto() {
    return digitalRead(pin) == HIGH;
}

/**
 * Flotador abierto
 */
bool NivelAgua::nivelBajo() {
    return digitalRead(pin) == LOW;
}
