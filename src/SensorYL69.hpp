/*
 * Clase encargada del control del sensor de humedad de la tierra
 */
#include <DHTesp.h>

// Nos indica el humbrar de humedad (para la sensibilidad del sensor)
const int DEFAULT_HUMBRAL = 800;

class SensorYL69
{
private:
  int humbral;
  uint8_t pin;
  String nombre;

public:
  void init(uint8_t id);
  void init(uint8_t id, String n, int h);

  void setHumbral(int h);
  void setNombre(String n);

  float getHumedad();
  bool isSeco();

  void toConsole(float humedad);
  String toHtmlContent(float humedad);
};
