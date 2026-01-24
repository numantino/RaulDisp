/*
 * Clase encargada del control de una bomba de agua por medio de un rele
 */
#pragma once
#include <Arduino.h>

// Tiempo default (Delay 20 sec.)
const int T_DEFAULT = 7000;

class BombaAgua {
private:
    int timer_encendido;
    String nombre;
    int pin;

public:
    void init(uint8_t id);
    void init(uint8_t id, String n, int t = T_DEFAULT);

    void setTiempo(int t);
    int getTiempo();
    void setNombre(String n);
    String getNombre();

    // Metodos del rele
    void releON();
    void releOFF();

    // Metodos basicos
    void riegoAutomatico();
};
