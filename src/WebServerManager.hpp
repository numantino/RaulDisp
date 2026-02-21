#pragma once
#include <ESP8266WiFi.h>

class WebServerManager {
private:
  WiFiServer server = WiFiServer(80);

public:
  void initSTA(const char* ssid, const char* password);
  WiFiClient getClient();
  void showPage(WiFiClient &client, String html);
  String getParam(String request, String key);
  String readRequest(WiFiClient &client);
  void redirectToRoot(WiFiClient &client);
  String urlDecode(String str);
};
