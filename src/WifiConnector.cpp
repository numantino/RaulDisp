#include "WifiConnector.hpp"

/**
 * Conector de wifi
 * @param ssid nombre de la red
 * @param pwd contraseña de la red
 * @param mode nos indicara el modo, default WIFI_STA
 * Los modos pueden ser :
 *  - WIFI_STA
 *  - WIFI_AP
 *  - WIFI_AP_STA
 */
void WifiConnector::connect(const char* ssid, const char* pwd, WiFiMode_t mode) {
    WiFi.mode(mode);
    WiFi.begin(ssid, pwd);

    Serial.print("Conectando a WiFi: ");
    while (WiFi.status() != WL_CONNECTED) {
        delay(300);
        Serial.print(".");
    }
    Serial.println("\nWiFi conectada");
}
