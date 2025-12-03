#include "mylib.h"

int main()

{
    //entradas_t entradas = {0};
    estados_t estado = INICIO; // primer estado
    estados_t (*fsm[])(void) = {iniciar_cinta, f_espera, f_lectura, f_cl_rojo,f_cl_verde, f_cl_azul, f_parada};
    init_mcu();
    while(1) estado = (*fsm[estado])();

  return 0;
}
