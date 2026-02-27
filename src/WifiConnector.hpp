#pragma once
#include <ESP8266WiFi.h>

class WifiConnector {
public:
    static void connect(const char* ssid, const char* pwd, WiFiMode_t mode = WIFI_STA);
};
