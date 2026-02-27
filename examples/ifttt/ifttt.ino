#include <RaulDisp.h>
#include "wifiConf.h"

const int PIN_DHT22 = D4;

// Sensor
SensorDHT22 sensorDHT22;

// Datos para el iftt
IFTTTManager clienteLot;

//const char* server = "maker.ifttt.com"; 
const char* server = "api.thingspeak.com";

// Espera dormido
//const int SLEEP_TIME = 60e6; // 1 minuto
const int SLEEP_TIME = 600e6; // 10 minutos
// const uint64_t SLEEP_TIME = 3600e6; // 1 hora

void setup()
{
  Serial.begin(115200);
  delay(200);

  // Inicializamos el sensor SensorDHT22
  sensorDHT22.init(PIN_DHT22);

  // Leer sensor
  TempAndHumidity data = sensorDHT22.leer();
  sensorDHT22.toConsole(data);

  // Enviamos la informacion
  clienteLot.begin(SSID, PWD, apiKey, server);
  clienteLot.sendReading(getRequestThingSpeak(data));

  // Dormimos
  ESP.deepSleep(SLEEP_TIME);
}

void loop() {}

// Generamos el mensaje get para enviar
String getRequestThingSpeak(TempAndHumidity data)
{
    String req = "GET /update?api_key=";
    req += apiKey;
    req += "&field1=" + String(data.temperature, 1);
    req += "&field2=" + String(data.humidity, 1);
    req += " HTTP/1.1\r\nHost: ";
    req += server;
    req += "\r\nConnection: close\r\n\r\n";

    Serial.print("Request: ");
    Serial.println(req);

    return req;
}
