#include "BombaAgua.hpp"

/**
 * Inicializamos la funcion
 * @param id nos indica donde esta conectado el sensor
 * @param nivelPtr puntero al objeto que controla el nivel de agua
 * @param n nombre que que queremos poner al dispositivo
 * @param h tiempo que esta activo el BombaAgua
 */
void BombaAgua::init(uint8_t id, NivelAgua* nivelPtr, String n, int t) {
    pin = id;
    timer_encendido = t;
    nombre = n;
    nivel = nivelPtr;
    pinMode(id, OUTPUT);
    releOFF();
}

/**
 * Inicializamos la funcion
 * @param id nos indica donde esta conectado el sensor
 */
void BombaAgua::init(uint8_t id, NivelAgua* nivelPtr) {
    String nombreDef = "Bomba_" + String(id);
    init(id, nivelPtr, nombreDef, T_DEFAULT);
}

/**
 * @param t tiempo valor del tiempo de bombeo de agua
 */
void BombaAgua::setTiempo(int t) {
    timer_encendido = t;
}

/**
 * @return tiempo valor del tiempo de bombeo de agua
 */
int BombaAgua::getTiempo() {
    return timer_encendido;
}

/**
 * @return tiempo valor del tiempo de bombeo de agua en minutos
 */
int BombaAgua::getTiempoMinutos() {
    return timer_encendido / (1000 * 60);
}

/**
 * @param nombre de la bomba de agua
 */
void BombaAgua::setNombre(String n) {
    nombre = n;
}

/**
 * @return nombre de la bomba de agua
 */
String BombaAgua::getNombre() {
    return nombre;
}

/**
 * Funcion que activa el rele
 */
void BombaAgua::releON() {
    digitalWrite(pin, LOW);
}

/**
 * Funcion que desactiva el rele
 */
void BombaAgua::releOFF() {
    digitalWrite(pin, HIGH);
}

/**
 * Funcion que realiza el riego automatico segun los parametros de configuracion
 * El tiempo de riego esta en milisegundos
 */
void BombaAgua::riegoAutomatico() {
    Serial.print("Inicio del riego [");
    Serial.print(nombre);
    Serial.println("]");
    Serial.print("Tiempo:");
    Serial.println(String(timer_encendido));

    if (nivel->nivelBajo()) {
        Serial.println("Riego cancelado: depósito vacío");
        return;
    }

    releON();

    unsigned long inicio = millis();
    while (millis() - inicio < timer_encendido) {

        if (nivel->nivelBajo()) {
            Serial.println("Nivel bajo detectado, deteniendo riego");
            break;
        }

        delay(100);
    }

    releOFF();
    Serial.println("Fin del riego");
}
