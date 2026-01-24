/*
 * Clase encargada del control del sensor de humedad y temperatura ambiente
 */
#pragma once
#include <DHTesp.h>

class SensorDHT22
{
private:
  DHTesp dht;
  String nombre;

public:
  void init(uint8_t id);
  void init(uint8_t id, String nombre);

  void setNombre(String nombre);

  TempAndHumidity leer();
  float getTemperatura();
  float getHumedad();

  void toConsole(TempAndHumidity data);
  String toHtmlContent(TempAndHumidity data);
};
