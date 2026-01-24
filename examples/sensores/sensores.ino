#include <RaulDisp.h>
#include "wifiConf.h"
#include "HtmlUtils.hpp"


// Conectores de los sensores
const int PIN_DHT22 = D1;
const int PIN_ANALOGICO = A0;

// Componentes
WebServerManager web;
SensorDHT22 sensorDHT22;
SensorYL69 sensorYL69;
SensorLDR sensorLDR;

void setup()
{
  // Inicializacion logs
  Serial.begin(115200);

  web.initSTA(SSID, PWD);
  // Inicializamos el sensor SensorDHT22
  sensorDHT22.init(PIN_DHT22);
  // Inicializamos el sensor de control de humedad del suelo
  sensorYL69.init(PIN_ANALOGICO);
  // Inicializamos el sensor de luminosidad
  sensorLDR.init(PIN_ANALOGICO);
}

void loop()
{

  WiFiClient client = web.getClient();

  if (client)
  {
    Serial.println("Cliente conectado");
    web.showPage(client, paginaPrincipal());

    client.stop();
    Serial.println("Cliente desconectado");
  }

  delay(50);
}

String paginaPrincipal()
{
  String html = htmlHeader("Panel de Sensores");

  html += "<div class='container'>";
  html += "<div class='grid'>";

  // Sensor 1: DHT22
  html += "<div class='card'>";
  html += sensorDHT22.toHtmlContent(sensorDHT22.leer());
  html += "</div>";

  // Sensor 2: YL69
  html += "<div class='card'>";
  html += sensorYL69.toHtmlContent(sensorYL69.getHumedad());
  html += "</div>";

  // Sensor 3: LDR
  html += "<div class='card'>";
  html += sensorLDR.toHtmlContent(sensorLDR.lecturaNivelLuz(sensorLDR.lecturaNormal()));
  html += "</div>";

  html += "</div>"; // grid
  html += "</div>"; // container

  html += htmlFooter();
  return html;
}
