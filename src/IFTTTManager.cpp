#include "IFTTTManager.hpp"
#include "WifiConnector.hpp"

WiFiClient IFTTTManager::_client;
const char* IFTTTManager::_apiKey = nullptr;
const char* IFTTTManager::_server = nullptr;

/**
 * Reallizamos la inicicializacion y conexion con el servidor
 * @param ssid nombre de la red
 * @param pwd contraseña de la red
 * @param apiKey clave publica para conectarse con el servidor
 * @param server nombre del servidor
 */
void IFTTTManager::begin(const char* ssid, const char* pwd, const char* apiKey, const char* server)
{
    _apiKey = apiKey;
    _server = server;
    WifiConnector::connect(ssid, pwd);
}

/**
 * Metodo para el envio de los datos al servidor
 * @param request datos del request
 */
void IFTTTManager::sendReading(String request)
{
    if (_client.connect(_server, 80)) {
        _client.print(request);
    }

    _client.flush();
    _client.stop();
}

/**
 * Funcion para el envio de la informacion, comun para todos los servidores de IFTTT
 * @param valores es un array de string con los valores que se quieren mandar
 * @param nvalores nos indica el numero de valores que estamos mandando
 * @param evento evento que estamos mandando
 */
String IFTTTManager::getRequestIFTTT(String valores[], int nValores, String evento)
{
    String req = "GET /trigger/";
    req += evento;
    req += "/with/key/";
    req += _apiKey;

    // añadimos los valores
    for (int i = 0; i < nValores; i++) {
        req += (i == 0 ? "?" : "&");
        req += "value" + String(i + 1) + "=" + valores[i];
    }

    req += " HTTP/1.1\r\nHost: ";
    req += _server;
    req += "\r\nConnection: close\r\n\r\n";

    Serial.print("Request: ");
    Serial.println(req);

    return req;
}
