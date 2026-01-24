# Conexiones web
## Crear un punto acceso SoftAP (Wifi)
Crearemos un punto Wifi donde nos conectaremos, para poder conectarnos a ella y controlar remotamente los sensores. Dentro de la tarjeta vamos a “embeber” un servidor web, que no es otra cosa más que responder con HTML a las peticiones.
Necesitaremos la librería wifi compatible con la placa NodeMCU.

Los comandos para realizar la creación serán:
1. Indicamos el **modo:WiFi.mode(WIFI_AP)**.<br>
Los diferentes valores son:       
    - WIFI_STA: Estacion
    - WIFI_AP: Punto de acceso
    - WIFI_AP_STA: las dos
2. Instanciamos la **clase: WiFi.softAP(ssid, passphrase = NULL, channel = 1, ssid_hidden = 0, max_connection = 4)**.<br> 
La descripción de los campos es:
   - ssid, nombre de la red WiFi que vamos a generar (entre 32 char)
   - password, opcional, contraseña de la WiFi (mín 8 y máx 63 char)
   - channel, opcional, el canal de WiFi a emplear (del 1 al 13)
   - hidden, opcional, si es true no se mostrará el SSID
   - max_connection, opcional, número máximo de conexiones (máx 8)
3. Esta parte es opcional, podemos configurar los valores de la red creada: WiFi.config(ip, gateway, subnet);

### Ejemplos
Se puede ver un ejemplo en la carpeta ''examples/wifi_STA''
