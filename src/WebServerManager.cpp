#include "WebServerManager.hpp"

/**
 * Conexion de wifi modo STA
 */
void WebServerManager::initSTA(const char* ssid, const char* password) {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi: ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectada");
  server.begin();
  Serial.print("IP local: ");
  Serial.println(WiFi.localIP());
}

/**
 * @return Método para obtener un cliente conectado
 */
WiFiClient WebServerManager::getClient() {
  return server.available();
}

/**
 * Muestra cualquier HTML que le pases
 */
void WebServerManager::showPage(WiFiClient &client, String html) {
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html; charset=utf-8");
  client.println("Connection: close");
  client.println();
  client.println(html);
}

/**
 * Extrae un parámetro de la petición (?clave=valor)
 */
String WebServerManager::getParam(String request, String key) {
  String search = key + "=";
  int index = request.indexOf(search);
  if (index == -1) return "";
  int start = index + search.length();
  int end = request.indexOf("&", start);
  if (end == -1) end = request.indexOf(" ", start);
  return request.substring(start, end);
}

/**
 * Lee la petición HTTP completa
 */
String WebServerManager::readRequest(WiFiClient &client) {
  String request = "";
  unsigned long timeout = millis();

  while (client.connected() && millis() - timeout < 2000) {
    if (client.available()) {
      char c = client.read();
      request += c;
      if (request.endsWith("\r\n\r\n")) {
        break;
      }
    }
  }
  return request;
}
