#include "sensorYL69.hpp"

/**
 * Inicializamos la funcion
 * @param id nos indica donde esta conectado el sensor
 * @param n nombre que que queremos poner al dispositivo
 * @param h humbral que le indicamos a este dispositivo, DEFAULT_HUMBRAL
 */
void SensorYL69::init(uint8_t id, String n, int h)
{
  pin = id;
  humbral = h;
  nombre = n;
  pinMode(id, INPUT);
}

void SensorYL69::init(uint8_t id)
{
  String nombreDef = "YL69_" + String(id);
  init(id, nombreDef, DEFAULT_HUMBRAL);
}

/**
 * Funcion que puede modificar el humbral
 * @param h nuevo dato del humbral
 */
void SensorYL69::setHumbral(int h)
{
  humbral = h;
}

/**
 * Funcion que puede modificar el nombre
 * @param n nuevo nombre
 */
void SensorYL69::setNombre(String n)
{
  nombre = n;
}

/**
 * @return devuelve la humedad
 */
float SensorYL69::getHumedad()
{
  return analogRead(pin);
}

/**
 * @return nos indica si el suelo esta seco dependiendo del humbral
 */
bool SensorYL69::isSeco()
{
  return getHumedad() >= humbral;
}

/**
 * Funcion que nos muestra por consola los datos
 * @param humedad dato de la humedad
 */
void SensorYL69::toConsole(float humedad)
{
  Serial.print("Lectura datos sensor YL69[");
  Serial.print(nombre);
  Serial.print("- humbral: ");
  Serial.print(humbral);
  Serial.print("]: ");
  Serial.print(humedad);
  if (isSeco())
    Serial.println(" --> necesita regarse");
  else
    Serial.println(" --> esta humedo, no necesita riego");
}

/**
 * Funcion que nos genera el html que queremos mostrar
 * @param humedad dato de la humedad
 * @return html contenido
 */
String SensorYL69::toHtmlContent(float humedad)
{
  String html;

  // Título principal del sensor
  html += "<div class='title'>" + nombre + "</div>";

  // Contenedor vertical
  html += "<div class='container' style='flex-direction: column; gap: 10px;'>";

  // Humedad
  html += "<div class='row'>";
  html += "<span class='title'>Humedad:</span> ";
  html += "<span class='value soil'>" + String(humedad) + "%</span>";
  html += "</div>";

  // Estado
  html += "<div class='row'>";
  html += "<span class='title'></span> ";

  if (isSeco())
    html += "<span class='value status-bad'>Necesita riego</span>";
  else
    html += "<span class='value status-ok'>No necesita riego</span>";

  html += "</div>"; // row

  html += "</div>"; // container

  return html;
}
