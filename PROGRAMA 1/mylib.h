#ifndef MY_LIB
#define MY_LIB
#include <stdio.h>

typedef enum {
    espera = 0,
    lectura =1,
    clasificacion=2,
    parada=3
}estados_t;

typedef struct {
  char s_color;
  char sp_inicio;
  char sp_rojo;
  char sp_verde;
  char sp_azul;
  char ac_clasifica;  
  char c_nodetecta; 
}entradas_t;

estados_t f_espera(entradas_t);
estados_t f_lectura(entradas_t);
estados_t f_clasificacion(entradas_t);
estados_t f_parada(entradas_t);

#endif