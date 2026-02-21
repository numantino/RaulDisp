/*
 * Clase encargada del control de una bomba de agua por medio de un rele
 */
#pragma once
#include <Arduino.h>
#include "NivelAgua.hpp"

// Tiempo default (Delay 1 minuto)
const int T_DEFAULT = 60000;

class BombaAgua {
private:
    int timer_encendido;
    String nombre;
    int pin;
    NivelAgua* nivel;

public:
    void init(uint8_t id, NivelAgua* nivelPtr);
    void init(uint8_t id, NivelAgua* nivelPtr, String n, int t = T_DEFAULT);

    void setTiempo(int t);
    int getTiempo();
    int getTiempoMinutos();
    void setNombre(String n);
    String getNombre();

    // Metodos del rele
    void releON();
    void releOFF();

    // Metodos basicos
    void riegoAutomatico();
};
