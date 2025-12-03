#include "mylib.h"
#include "conf.h"

void init_mcu(void){
    GpioInitStructure_AVR sensores, actuadores;
    AdcInitStructure_AVR s_color;

    sensores.modo = avr_GPIO_mode_Input;
    sensores.port = SENSORES_PORT;
    sensores.pines = SP_INICIO_PIN | SP_ROJO_PIN | SP_VERDE_PIN | SP_AZUL_PIN;
    init_gpio(sensores);

    actuadores.modo = avr_GPIO_mode_Output;
    actuadores.port = ACTUADORES_PORT;
    actuadores.pines = AC_ROJO_PIN | AC_VERDE_PIN | AC_AZUL_PIN | MOTOR_CINTA_PIN;
    init_gpio(actuadores);

    s_color.mode = avr_ADC_MODE_Single_Conversion;
    s_color.reference = avr_ADC_REF_Internal;
    s_color.resolution = avr_ADC_RES_10Bit;
    s_color.channel = ADC_PORT;
    s_color.prescaler = avr_ADC_Prescaler_64;
    init_adc(s_color);

}

    void activar_cinta(void){
        motor_cinta=1;
    }
    void desactivar_cinta(void){
        motor_cinta=0;
    }

// lectura del adc 0 - 1023 => (2560/1024) = 2.5 cuentas por milivolt |  2.5 * cuentas = milivolts leidos 
    int leer_color(void){
        return (((float)leer_ADC(ADC_PORT) * (2560.0/1024.0)));
    }

    void activar_ac_rojo(void){
        AC_ROJO=1;
    }
    void desactivar_ac_rojo(void){
        AC_ROJO=0;
    }

    void activar_ac_verde(void){
        AC_VERDE=1;
    }
    void desactivar_ac_verde(void){
        AC_VERDE=0;
    }

    void activar_ac_azul(void){
        AC_AZUL=1;
    }
    void desactivar_ac_azul(void){
        AC_AZUL=0;
    }

