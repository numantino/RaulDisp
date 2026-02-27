#include <RaulDisp.h>

// Conectores de los sensores
const int PIN_DHT22 = D1;
const int PIN_ANALOGICO = A0;

// Componentes
SensorDHT22 sensorDHT22;
SensorYL69 sensorYL69;
SensorLDR sensorLDR;

void setup()
{
  // Inicializacion logs
  Serial.begin(115200);

  // Inicializamos el sensor SensorDHT22
  sensorDHT22.init(PIN_DHT22);
  // Inicializamos el sensor de control de humedad del suelo
  sensorYL69.init(PIN_ANALOGICO);
  // Inicializamos el sensor de luminosidad
  // TODO solo podemos tener uno conectado al pin analogico
  // sensorLDR.init(PIN_ANALOGICO);
}

void loop()
{

  sensorDHT22.toConsole(sensorDHT22.leer());
  sensorYL69.toConsole(sensorYL69.getHumedad());
  // sensorLDR.toConsole(sensorLDR.lecturaNivelLuz(sensorLDR.lecturaNormal()));

  delay(50);
}
