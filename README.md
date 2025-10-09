# Info2-PROYECTO
Proyecto - Informática II - 2025
## Memoria descriptiva

El sistema consiste en una __clasificadora automática de envases basada en el color de su etiqueta__. Los productos se desplazan sobre una cinta transportadora, donde cada envase es identificado según el color de su etiqueta (rojo, azul o verde) mediante un sensor de color. Una vez detectado el color, el sistema acciona actuadores eléctricos para desviar el envase hacia la salida correspondiente. 

En caso de no reconocer el color, se detecta una falla y se detiene el sistema. 

 ## Máquina de estado 
![alt text](https://github.com/martina-di-scala/Info2-PROYECTO/blob/main/Recursos/MAQUINA%20DE%20ESTADO%202.png)


- __S<sub>C</sub>__: Sensor COLOR
 - __S<sub>P0</sub>__: Sensor DETECTOR DE RECIPIENTE 
 - __S<sub>Projo</sub>__: Sensor DETECTOR DE RECIPIENTE (Posición salida correspondiente)
 - __S<sub>Pazul</sub>__: Sensor DETECTOR DE RECIPIENTE (Posición salida correspondiente)
 - __S<sub>Pverde</sub>__: Sensor DETECTOR DE RECIPIENTE (Posición salida correspondiente)
