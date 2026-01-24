#include "BombaAgua.hpp"

/**
 * Inicializamos la funcion
 * @param id nos indica donde esta conectado el sensor
 * @param n nombre que que queremos poner al dispositivo
 * @param h tiempo que esta activo el BombaAgua
 */
void BombaAgua::init(uint8_t id, String n, int t) {
    pin = id;
    timer_encendido = t;
    nombre = n;
    pinMode(id, OUTPUT);
    releOFF();
}

/**
 * Inicializamos la funcion
 * @param id nos indica donde esta conectado el sensor
 */
void BombaAgua::init(uint8_t id) {
    String nombreDef = "Bomba_" + String(id);
    init(id, nombreDef, T_DEFAULT);
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
 */
void BombaAgua::riegoAutomatico() {
    Serial.print("Inicio del riego [");
    Serial.print(nombre);
    Serial.println("]");    
    releON();
    delay(timer_encendido);

    releOFF();    
    Serial.println("Fin del riego");
}
