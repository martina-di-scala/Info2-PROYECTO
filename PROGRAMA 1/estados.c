#include "mylib.h"
#include "conf.h"


estados_t f_espera(entradas_t){

}

estados_t f_lectura(void){
    int color;
    color=leer_color();
    if ( color < LIMITE_ROJO) {
        return cl_rojo;
    } 
    else if ( color < LIMITE_VERDE) {
        return cl_verde;
    } 
    else if (color < LIMITE_VERDE)
    {
        return cl_azul;
    }else
    {
        return parada;
    }
}
estados_t cl_rojo(void){
    
    
}
estados_t cl_verde(void){
    
}
estados_t cl_azul(void){
    
}
estados_t f_parada(entradas_t){

}
