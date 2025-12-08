# Info2-PROYECTO
Proyecto - Informática II - 2025
## Memoria descriptiva

El sistema consiste en una __clasificadora automática de envases basada en el color de su etiqueta__. Los productos se desplazan sobre una cinta transportadora, donde cada envase es identificado según el color de su etiqueta (rojo, azul o verde) mediante un sensor de color. Una vez detectado el color, el sistema acciona actuadores eléctricos para desviar el envase hacia la salida correspondiente. 

En caso de no reconocer el color, se detecta una falla y se detiene el sistema. 

 ## Máquina de estado 

- __S<sub>C</sub>__: Sensor COLOR
 - __S<sub>P0</sub>__: Sensor DETECTOR DE RECIPIENTE 
 - __S<sub>Projo</sub>__: Sensor DETECTOR DE RECIPIENTE (Posición salida correspondiente)
 - __S<sub>Pazul</sub>__: Sensor DETECTOR DE RECIPIENTE (Posición salida correspondiente)
 - __S<sub>Pverde</sub>__: Sensor DETECTOR DE RECIPIENTE (Posición salida correspondiente)

![alt text](https://github.com/martina-di-scala/Info2-PROYECTO/blob/main/Recursos/Maquina%20de%20Estado.png)

### Explicación:
- __INICIO__: cinta transportadora activa;

- __ESPERA__: No se detectó nada en el sensor presencia inicio, por lo cual no hay objeto en la cinta;

- __LECTURA__: Esta activo el sensor presencia inicio y se determina por medio del sensor analógico si el objeto es ROJO , VERDE O AZUL;

- __ACTUADOR ROJO__: Deja de estar activo el sensor presencia inicio, el sensor analógico determino que se trataba de un objeto ROJO y esta activo el sensor posición actuador rojo, se activa el actuador rojo y se mantiene activo mientras no se active el sensor presencia inicio -> al desactivarse vuelve a espera;

- __ACTUADOR VERDE__: Deja de estar activo el sensor presencia inicio, el sensor analógico determino que se trataba de un objeto VERDE y esta activo el sensor posición actuador verde, se activa el actuador verde y se mantiene activo mientras no se active el sensor presencia inicio -> al desactivarse vuelve a espera;

- __ACTUADOR AZUL__: Deja de estar activo el sensor presencia inicio, el sensor analógico determino que se trataba de un objeto AZUL y esta activo el sensor posición actuador azul, se activa el actuador azul y se mantiene activo mientras no se active el sensor presencia inicio->al desactivarse vuelve a espera 

- __PARADA__: si estoy en LECTURA y leo un determinado rango de valores, se me desactivan todas las salidas (El motor cinta también) y espera a que el sensor haya dejado de detectar y se debe reiniciar el programa.

 ## SENSORES Y ACTUADORES

### ENTRADAS: 

- __Sensor analógico detector de color__: se simula a partir de un potenciómetro y según el rango en el que este detecta rojo, verde, azul, parada -> conectado al pin PF0/ADC0;

El sensor analógico correspondiente al sensor de color, se simula mediante la variación de un potenciometro, por lo cual su lectura se divide en:

1er rango -> OBJETO ROJO

2do rango -> OBJETO VERDE

3er rango -> OBJETO AZUL

4to rango -> PARADA

- __Sensor presencia inicio__: detecta cuando hay un objeto en la cinta -> conectado al pin PD0 del Atmega128;

- __Sensor digital posición actuador rojo__: detecta cuando el objeto esta pasando por el lugar donde se debe activar el actuador rojo, en caso de haberse detectado objeto rojo -> conectado al pin PD2

- __Sensor digital posición actuador verde__: detecta cuando el objeto esta pasando por el lugar donde se debe activar el actuador verde, en caso de haberse detectado objeto verde -> conectado al pin PD4;

- __Sensor digital posición actuador azul__: detecta cuando el objeto esta pasando por el lugar donde se debe activar el actuador azul, en caso de haberse detectado objeto azul -> conectado al pin PD6.

Los sensores digitales se simulan con switches.

### SALIDAS:

- __Motor cinta__: Esta activo mientras el sistema este en funcionamiento y no se haya entrado en la zona de PARADA -> conectado al pin PA6 del Atmega128;

- __Actuador ROJO__: Se activa cuando se ha detectado un objeto rojo, y el sensor posición actuador rojo esta activo, se desactiva cuando se vuelve a activar el sensor presencia inicio -> conectado al pin PA0;

- __Actuador VERDE__: Se activa cuando se ha detectado un objeto verde, y el sensor posición actuador verde esta activo, se desactiva cuando se vuelve a activar el sensor presencia inicio-> conectado al pin PA2;

- __Actuador AZUL__: Se activa cuando se ha detectado un objeto verde, y el sensor posición actuador verde esta activo, se desactiva cuando se vuelve a activar el sensor presencia inicio-> conectado al pin PA4;

Las salidas se simulan con diodos LED.

## PROGRAMACIÓN

La programación del sistema cuenta con 5 archivos, además de la API para el microcontrolador Atmega128 de ATMEL.

- __main.c__: contiene la estructura principal con el puntero a funciones, tal como estaba planteado originalmente en el trabajo práctico.

- __funciones.c__ : incluye la inicialización de la AVR y las funciones de activación y desactivación de los actuadores.

- __estados.c__: desarrollo los estados de la máquina. Tengo definidos los estados y la detección de color a partir del ADC(valores definidos para el potenciómetro); a partir de esto debería empezar a completar las acciones de cada estado, en función de los sensores y las funciones definidas en funciones.c.

- __mylib.h__: contiene las estructuras, los prototipos de las funciones de estado y los valores de detección para cada color.

- __conf.h__: agrupo todas las definiciones relacionadas a las entradas y salidas utilizando la AVR API.

## ESQUEMÁTICO
![alt text](https://github.com/martina-di-scala/Info2-PROYECTO/blob/main/Recursos/ESQUEMATICO.png)

## SIMULACIÓN

[SIMULACIÓN REALIZADA EN PROTEUS](https://drive.google.com/file/d/1XQ9YKma-T3nuwV--42is5m7R4R3CvGyy/view?usp=drive_link)
