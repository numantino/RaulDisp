/*
 * Clase encargada del control del sensor de la cantidad de luz
 */
#pragma once
#include <DHTesp.h>

// Resistencia en oscuridad en KΩ
const long RESISTENCIA_A = 1000;
// Resistencia a la luz (10 Lux) en KΩ
const int RESISTENCIA_B = 15;
// Resistencia calibracion en KΩ
const int RESISTENCIA_Rc = 10;

class SensorLDR
{
private:
  uint8_t pin;
  String nombre;
  long resistenciaA;
  int resistenciaB;
  int resistenciaRc;

public:
  void init(uint8_t id);
  void init(uint8_t id, String nombre);

  void modificarResistencias(long ra, int rb, int rc);

  int lecturaNormal();
  int lecturaNivelLuz(int nivel);
  
  void toConsole(int intensidad);
  String toHtmlContent(int intensidad);
};
