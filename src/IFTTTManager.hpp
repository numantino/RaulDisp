#pragma once
#include <ESP8266WiFi.h>

class IFTTTManager {
public:
    static void begin(const char* ssid, const char* pwd, const char* apiKey, const char* server);
    static void sendReading(String request);
    static String getRequestIFTTT(String valores[], int nValores, String evento);
private:
    static WiFiClient _client;
    static const char* _apiKey;
    static const char* _server;
};
