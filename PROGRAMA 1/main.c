#include "mylib.h"

int main()

{
    entradas_t entradas = {0};
    estados_t estado = espera; // primer estado
    estados_t (*fsm[])(entradas_t) = {f_espera, f_lectura, f_clasificacion, f_parada};
    while(1) estado = (*fsm[estado])(entradas);

/*     while(1){
      switch (estado) {
        case espera: estado = f_espera(entradas);
        break;
        case lectura: estado = f_lectura(entradas);
        break;
        case clasificacion: estado = f_clasificacion(entradas);
        break;
        case parada: estado = f_parada(entradas);
        break;
      }
    } */
  return 0;
}