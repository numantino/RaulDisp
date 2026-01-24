#include "sensorLDR.hpp"

/**
 * Inicializamos la funcion
 * @param id nos indica donde esta conectado el sensor
 */
void SensorLDR::init(uint8_t id, String n)
{
  pin = id;
  nombre = n;
  resistenciaA = RESISTENCIA_A;
  resistenciaB = RESISTENCIA_B;
  resistenciaRc = RESISTENCIA_Rc;
}

/**
 * Inicializamos la funcion
 * @param id nos indica donde esta conectado el sensor
 */
void SensorLDR::init(uint8_t id)
{
  String nombreDef = "LDR_" + String(id);
  init(id, nombreDef);
}

/**
 * Podemos configurar las resistencias
 * @param ra Resistencia en oscuridad en KΩ
 * @param rb Resistencia a la luz (10 Lux) en KΩ
 * @param rc Resistencia calibracion en KΩ
 */
void SensorLDR::modificarResistencias(long ra, int rb, int rc)
{
  resistenciaA = ra;
  resistenciaB = rb;
  resistenciaRc = rc;
}

/**
 * Funcion que lee el valor del pinLDR
 * Valores comprendidos entre 0 y 1023.
 * @param intensidad dato de la intensidad de luz
 */
int SensorLDR::lecturaNormal()
{
  return analogRead(pin);
}

/**
 * Funcion que lee el valor del pinLDR, con datos de control
 * usar si LDR entre GND y A0
 * @param intensidad dato de la intensidad de luz
 */
int SensorLDR::lecturaNivelLuz(int nivel)
{
  return ((long)(1024 - nivel) * resistenciaA * 10) / ((long)resistenciaB * resistenciaRc * nivel);
}

/**
 * Funcion que nos muestra por consola los datos
 * @param intensidad dato de la intensidad de luz
 */
void SensorLDR::toConsole(int intensidad)
{
  Serial.print("Lectura datos sensor LDR: ");
  Serial.println(intensidad);
}

/**
 * Funcion que nos genera el html que queremos mostrar
 * @param intensidad dato de la intensidad de luz
 * @return htlm contenido
 */
String SensorLDR::toHtmlContent(int intensidad)
{
  String html = "<div class='title'>" + nombre + "</div>";

  html += "<div class='container'>";

  html += "<div class='row'>";
  html += "<div class='title'>Intensidad de luz</div>";
  html += "<div class='value temp'>" + String(intensidad) + " </div>";
  html += "</div>";

  html += "</div>";

  return html;
}
