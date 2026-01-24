# Sensor DHT22
Es un sensor con el que se puede recuperar la humedad del suelo.<br> 

Metodos: <br>
```CPP
  // Inicializacion del componente 
  void init(uint8_t id);
  void init(uint8_t id, String n, int h);

  // Metodo para poder modificar el humbral
  void setHumbral(int h);
  // Metodo para poder modificar el nombre del dispositvo
  void setNombre(String n);

  // Funcion que nos devuelve los datos de la humedad
  float getHumedad();
  // Funcion que nos indica si es suelo esta seco dependiendo del humbral indicado
  // DEFAULT_HUMBRAL = 800 
  bool isSeco();

  // Mustra la informacion en la consola
  void toConsole(float humedad);
  // Genera un fichero html para mostrar la informacion
  String toHtmlContent(float humedad);

```

## El sensor
Consiste en dos picas que se encuentran enterradas en tierra de manera que controlando la resistencia de la tierra se puede conocer la humedad.
Con el potenciómetro del dispositivo intermedio, se puede calibrar (no en todos los dispositivos).<br>
No necesita una fuente de alimentacion externa.<br>
<span style="background-color: grey;">**!Importante:** En este caso la conexion es a un pin analógico</span><br>
<div style="display: flex; align-items: center; margin-bottom: 20px;">
  <img src="./img/sensorYL69.png" style="max-width: 200px; margin-right: 20px;">
  <p>Las entradas son:<br/>
  **A0** = Salida de datos del control, este se tiene que conctar al pin A0 (al pin analogico) esto es importante<br/>
  *D0** = sin nada<br/>
  **VCC** = Se conecta al pin de 3v o 5v<br/>
  **GND** = Se conecta al pin de tierra
  </p>
</div>

## Ejemplos
Se puede ver un ejemplo en la carpeta ''examples/sensores''