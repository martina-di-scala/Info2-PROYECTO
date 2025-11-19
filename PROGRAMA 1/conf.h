#ifndef CONF_H
#define CONF_H 1
#include "mylib.h"

//Función de inicializacion y configuacion del micro
void init_mcu(void);

//lee tension sensor color (pote)
int leer_color(void);

//funciones para los estados de los actuadores (Salida)
void activar_ac_rojo(void);
void desactivar_ac_rojo(void);

void activar_ac_verde(void);
void desactivar_ac_verde(void);

void activar_ac_azul(void);
void desactivar_ac_azul(void);


//Definiciones de puertos para los sensores
#define SENSORES_PORT avr_GPIO_D
#define SP_INICIO avr_GPIOD_IN_0
#define SP_INICIO_PIN avr_GPIO_PIN_0
#define SP_ROJO avr_GPIOD_IN_2
#define SP_ROJO_PIN avr_GPIO_PIN_2
#define SP_VERDE avr_GPIOD_IN_4
#define SP_VERDE_PIN avr_GPIO_PIN_4
#define SP_AZUL avr_GPIOD_IN_6
#define SP_AZUL_PIN avr_GPIO_PIN_6

//Definiciones de puertos para los actuadores
#define ACTUADORES_PORT avr_GPIO_A
#define AC_ROJO avr_GPIOA_OUT_0
#define AC_ROJO_PIN avr_GPIO_PIN_0
#define AC_VERDE avr_GPIOA_OUT_2
#define AC_VERDE_PIN avr_GPIO_PIN_2
#define AC_AZUL avr_GPIOA_OUT_4
#define AC_AZUL_PIN avr_GPIO_PIN_4

//Canal de conersión para el sensor color (pote)
#define ADC_PORT avr_ADC_canal0

#endif
