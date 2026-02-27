#include "WebServerManager.hpp"
#include "WifiConnector.hpp"

/**
 * Conexion de wifi
 */
void WebServerManager::init(const char* ssid, const char* password, WiFiMode_t mode) {
  WifiConnector::connect(ssid, password, mode);
  server.begin();
  Serial.print("IP local modo");
  Serial.println(mode);
  Serial.print(": ");
  Serial.println(WiFi.localIP());
}

/**
 * Conexion de wifi modo STA
 */
void WebServerManager::initSTA(const char* ssid, const char* password) {
  WifiConnector::connect(ssid, password);
  server.begin();
  Serial.print("IP local modo STA: ");
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

/**
 * Para rederigir a la pagina principal
 */
void WebServerManager::redirectToRoot(WiFiClient &client) {
  client.println("HTTP/1.1 302 Found");
  client.println("Location: /");
  client.println("Connection: close");
  client.println();
}

/**
 * Para transformar correctamente el code
 */
String WebServerManager::urlDecode(String str) {
  String decoded = "";
  char temp[] = "00";
  unsigned int len = str.length();

  for (unsigned int i = 0; i < len; i++) {
    if (str[i] == '%') {
      temp[0] = str[i + 1];
      temp[1] = str[i + 2];
      decoded += char(strtol(temp, NULL, 16));
      i += 2;
    } else if (str[i] == '+') {
      decoded += ' ';
    } else {
      decoded += str[i];
    }
  }
  return decoded;
}
