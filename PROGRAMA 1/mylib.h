#ifndef MY_LIB
#define MY_LIB
#include"avr_api.h"



typedef enum {
    INICIO= 0,
    ESPERA = 1,
    LECTURA =2,
    CL_ROJO=3,
    CL_VERDE=4,
    CL_AZUL=5,
    PARADA=6
}estados_t;

//limites de voltaje por color 
#define LIMITE_ROJO 1800
#define LIMITE_VERDE 3000
#define LIMITE_AZUL 4200
/*
typedef struct {
  char s_color;
  char sp_inicio;
  char sp_rojo;
  char sp_verde;
  char sp_azul;
}entradas_t;

typedef struct{
  char ac_rojo;
  char ac_verde;
  char ac_azul;
}salidas_t;

typedef enum {
    rojo = 0,
    verde = 1,
    azul= 2
}color_t;
 */
estados_t iniciar_cinta(void);
estados_t f_espera(void);
estados_t f_lectura(void);
estados_t f_cl_rojo(void);
estados_t f_cl_verde(void);
estados_t f_cl_azul(void);
estados_t f_parada(void);

#endif
