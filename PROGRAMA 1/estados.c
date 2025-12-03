#include "mylib.h"
#include "conf.h"

estados_t iniciar_cinta(void){
     activar_cinta();     
    return ESPERA;   
}


estados_t f_espera(void){
    desactivar_ac_rojo();
    desactivar_ac_verde();
    desactivar_ac_azul();

    if (!SP_INICIO)//No hay ningun objeto en el sensor inicial      
        return ESPERA;
    else
        return LECTURA;
}

estados_t f_lectura(void){
    int color;
    color=leer_color();
    if ( color < LIMITE_ROJO) {
        return CL_ROJO;
    } 
    else if ( color < LIMITE_VERDE) {
        return CL_VERDE;
    } 
    else if (color < LIMITE_AZUL)
    {
        return CL_AZUL;
    }else
    {
        return PARADA;
    }
}
estados_t f_cl_rojo(void){
    activar_ac_rojo();
    desactivar_ac_verde();
    desactivar_ac_azul();

    if (SP_ROJO)     
        return CL_ROJO;
    else
        return ESPERA;
}
estados_t f_cl_verde(void){
    activar_ac_verde();
    desactivar_ac_rojo();
    desactivar_ac_azul();

    if (SP_VERDE)     
        return CL_VERDE;
    else
        return ESPERA;
}
estados_t f_cl_azul(void){
     activar_ac_azul();
    desactivar_ac_rojo();
    desactivar_ac_verde();

    if (SP_AZUL)     
        return CL_AZUL;
    else
        return ESPERA;   
}
estados_t f_parada(void){
     desactivar_cinta();

    if (!SP_INICIO && !SP_ROJO && !SP_VERDE && !SP_AZUL)
    {
        iniciar_cinta();
        return ESPERA;
    }
    else
        return PARADA;

}
