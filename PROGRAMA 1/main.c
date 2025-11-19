#include "mylib.h"

int main()

{
    entradas_t entradas = {0};
    estados_t estado = espera; // primer estado
    estados_t (*fsm[])(void) = {f_espera, f_lectura, cl_rojo,cl_verde, cl_azul, f_parada};
    init_mcu();
    while(1) estado = (*fsm[estado])();

  return 0;
}
