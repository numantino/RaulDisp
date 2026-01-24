#include <RaulDisp.h>
#include "wifiConf.h"

const int LED_PIN = D1;

WebServerManager web;

void setup() {
  Serial.begin(115200);
  delay(1000);

  web.initSTA(SSID, PWD);
}

void loop() {
  WiFiClient client = web.getClient();
  if (client) {
    Serial.println("Cliente conectado");

    String request = web.readRequest(client);
    Serial.println("Petición:");
    Serial.println(request);

    // --- 1) Procesar valor numérico ---
    String valor = web.getParam(request, "valor");
    if (valor != "") {
      Serial.print("Valor recibido: ");
      Serial.println(valor);
    }

    // --- 2) Procesar control del LED ---
    String state = web.getParam(request, "state");
    if (state == "on") {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED encendido");
    }
    if (state == "off") {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED apagado");
    }

    // --- 3) Mostrar la página ---
    String html =
      "<h2>Enviar un número</h2>"
      "<form action='/set'>"
      "Introduce un número: <input type='number' name='valor'><br><br>"
      "<input type='submit' value='Enviar'>"
      "</form>"

      "<hr>"

      "<h2>Control del LED</h2>"
      "<form action='/led'>"
      "<button type='submit' name='state' value='on'>Encender LED</button>"
      "<button type='submit' name='state' value='off'>Apagar LED</button>"
      "</form>";

    web.showPage(client, html);

    client.stop();
    Serial.println("Cliente desconectado");
  }
}
