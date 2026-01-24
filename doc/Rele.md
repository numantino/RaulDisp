# Rele
Con el rele lo que hacemos es controlar el apagado y encendido de un dispositivo. Este dispositivo puede tener solo un controlador o varios, la configuracion seria la misma.<br> 
**Metodos** <br>
```CPP
  // Inicializacion del componente 
    void init(uint8_t id);
    void init(uint8_t id, String n, int t = T_DEFAULT);

    // Podemos modificar el tiempo de riego
    void setTiempo(int t);
    int getTiempo();
    // Metodo para poder modificar el nombre del dispositvo
    void setNombre(String n);
    String getNombre();

    // Metodos del rele
    void releON();
    void releOFF();

    // Metodo para iniciar el riego
    // T_DEFAULT = 7000 (20 segundos)
    void riegoAutomatico();

```

## El rele
Este dispositivo necesita una fuente de alimentacion extra.
<span style="color: red;">10v + 1out</span>
<div style="display: flex; align-items: center; margin-bottom: 20px;">
  <img src="./img/imgRele.png" style="max-width: 200px; margin-right: 20px;">
  <p>Las entradas son:<br/>
  **NO** = Entrada positiva<br/>
  **COM** = Entrada negativa<br/>
  **NC** = No lo usaremos
  </p>
</div>

## Bomba de agua
Para controlar la bomba de agua, se tendria que conectar al rele
<div style="display: flex; align-items: center; margin-bottom: 20px;">
  <img src="./img/imgBomba.png" style="max-width: 200px; margin-right: 20px;">
</div>

## Ejemplos
Se puede ver un ejemplo en la carpeta ''examples/rele''
