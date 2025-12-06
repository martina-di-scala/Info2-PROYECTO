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
    desactivar_ac_verde();
    desactivar_ac_azul();

    if (SP_ROJO)     
        activar_ac_rojo();
    if (SP_INICIO) {
        desactivar_ac_rojo();
        return ESPERA;
    }
    return CL_ROJO;
}

estados_t f_cl_verde(void){
    desactivar_ac_rojo();
    desactivar_ac_azul();

    if (SP_VERDE)     
        activar_ac_verde();
    if (SP_INICIO) {
        desactivar_ac_verde();
        return ESPERA;
    }
    return CL_VERDE;
}
estados_t f_cl_azul(void){
    desactivar_ac_rojo();
    desactivar_ac_verde();

     if (SP_ROJO)     
        activar_ac_rojo();
    if (SP_INICIO) {
        desactivar_ac_rojo();
        return ESPERA;
    }
    return CL_AZUL;
}
estados_t f_parada(void){
    desactivar_cinta();
    desactivar_ac_rojo();
    desactivar_ac_verde();
    desactivar_ac_azul();

    /*if (!SP_INICIO && !SP_ROJO && !SP_VERDE && !SP_AZUL)
    {
        activar_cinta();
        return ESPERA;
    }
    else
        return PARADA;*/

}
