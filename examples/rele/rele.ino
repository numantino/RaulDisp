#include <RaulDisp.h>
#include "wifiConf.h"
#include "HtmlUtils.hpp"

// Constantes
const int RELE_1 = D2;
const int PIN_FLOTADOR = D2;

// Componentes
WebServerManager web;
NivelAgua nivel(PIN_FLOTADOR);
BombaAgua bombaRiego;

// Variables
bool regando = false;

void setup()
{
  // Inicializacion logs
  Serial.begin(115200);
  web.initSTA(SSID, PWD);
  // Flotador de nivel de agua
  nivel.init();
  // Inicializamos el rele con el control de las bombas de agua
  bombaRiego.init(RELE_1, nivel);
}

void loop()
{
  WiFiClient client = web.getClient();

  if (client)
  {
    Serial.println("Cliente conectado");

    String request = web.readRequest(client);
    Serial.println(request);

    if (request.startsWith("GET / "))
    {
      web.showPage(client, paginaPrincipal(regando));
    }
    else if (request.startsWith("GET /inicioRiego"))
    {
      regando = true;

      // Ejecutamos el riego SIN enviar HTML
      bombaRiego.riegoAutomatico();
      regando = false;

      // Redirigimos al usuario a la página principal
      client.println("HTTP/1.1 302 Found");
      client.println("Location: /");
      client.println("Connection: close");
      client.println();
    }
    else
    {
      web.showPage(client, "<h1>404 - Página no encontrada</h1>");
    }

    client.stop();
    Serial.println("Cliente desconectado");
  }

  delay(50);
}

String paginaPrincipal(bool regando)
{
  String refresh = regando ? "<meta http-equiv='refresh' content='2'>" : "";
  String html = htmlHeader("Ejemplo bomba de agua", refresh);

  html += "<div class='container'>";
  html += "</div>";
  // Columna derecha: riego
  html += "<div class='card'>";
  html += "<h2>Control de Riego</h2>";
  html += "<a class='btn' href='/inicioRiego'>Iniciar riego</a>";
  html += "<div class='estado'>" + String(regando ? "Regando..." : "Riego finalizado") + "</div>";
  html += "</div>";

  html += "</div>"; // container

  html += htmlFooter();
  return html;
}
