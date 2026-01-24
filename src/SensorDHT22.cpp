
#include "sensorDHT22.hpp"

/**
 * Inicializacion
 */
void SensorDHT22::init(uint8_t id, String n)
{
  dht.setup(id, DHTesp::DHT22);
  nombre = n;
}

void SensorDHT22::init(uint8_t id)
{
  String nombreDef = "DHT22_" + String(id);
  init(id, nombreDef);
}

/**
 * @param n nombre del dispositivo si se le quiere dar
 */
void SensorDHT22::setNombre(String n)
{
  nombre = n;
}

/**
 * Recupera los datos del sensor
 * @return valores del sensor
 */
TempAndHumidity SensorDHT22::leer()
{
  return dht.getTempAndHumidity();
}

/**
 * @return devuelve la temperatura
 */
float SensorDHT22::getTemperatura()
{
  return leer().temperature;
}

/**
 * @return devuelve la humedad
 */
float SensorDHT22::getHumedad()
{
  return leer().humidity;
}

/**
 * Funcion que nos muestra por consola los datos
 * @param data datos del dispositivo
 */
void SensorDHT22::toConsole(TempAndHumidity data)
{
  Serial.print("Lectura datos sensor DHT22[t= ");
  Serial.print(data.temperature);
  Serial.print("ºC, h= ");
  Serial.print(data.humidity);
  Serial.println("%]");
}

/**
 * Parte comun del HTML
 * @param data datos del dispositivo
 * @return html contenido
 */
String SensorDHT22::toHtmlContent(TempAndHumidity data)
{
  String html = "<div class='title'>" + nombre + "</div>";

  html += "<div class='container'>";
  
  html += "<div class='col'>";
  html += "<div class='value temp'>" + String(data.temperature, 1) + " °C</div>";
  html += "</div>";

  html += "<div class='separator'></div>";

  html += "<div class='col'>";
  html += "<div class='value hum'>" + String(data.humidity, 1) + " %</div>";
  html += "</div>";

  html += "</div>";

  return html;
}
