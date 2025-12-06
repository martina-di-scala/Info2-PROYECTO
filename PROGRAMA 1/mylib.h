#ifndef MY_LIB
#define MY_LIB
#include"avr_api.h"
#include "conf.h"


typedef enum {
    INICIO= 0,
    ESPERA = 1,
    LECTURA =2,
    CL_ROJO=3,
    CL_VERDE=4,
    CL_AZUL=5,
    PARADA=6
}estados_t;

// Limites de voltaje para referencia VCC (5V)
// Rango total: 0 a 5000 mV 
#define LIMITE_NADA 200
#define LIMITE_ROJO 1800
#define LIMITE_VERDE 3000
#define LIMITE_AZUL 4200
// Mayor a 4200mV se considera PARADA

estados_t iniciar_cinta(void);
estados_t f_espera(void);
estados_t f_lectura(void);
estados_t f_cl_rojo(void);
estados_t f_cl_verde(void);
estados_t f_cl_azul(void);
estados_t f_parada(void);

#endif
