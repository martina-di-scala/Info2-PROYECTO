#include "mylib.h"

void init_mcu(void){
    GpioInitStructure_AVR sensores, actuadores;
    AdcInitStructure_AVR s_color;

    sensores.modo = avr_GPIO_mode_Input;
    sensores.port = SENSORES_PORT;
    sensores.pines = sp_inicio_PIN | sp_rojo_PIN | sp_verde_PIN | sp_azul_PIN;
    init_gpio(sensores);

    leds.modo = avr_GPIO_mode_Output;
    leds.port = ACTUADORES_PORT;
    leds.pines = ac_rojo_PIN | ac_verde_PIN | ac_azul_PIN;
    init_gpio(actuadores);

    s_color.mode = avr_ADC_MODE_Single_Conversion;
    s_color.reference = avr_ADC_REF_Internal;
    s_color.resolution = avr_ADC_RES_10Bit;
    s_color.channel = ADC_PORT;
    s_color.prescaler = avr_ADC_Prescaler_64;
    init_adc(s_color);

    // lectura del adc 0 - 1023 => (2560/1024) = 2.5 cuentas por milivolt |  2.5 * cuentas = milivolts leidos 
    int leer_color(void){
        return (((float)leer_ADC(ADC_PORT) * (2560.0/1024.0)));
    }

    void activar_ac_rojo(void);{

    }
    void desactivar_ac_rojo(void);{

    }

    void activar_ac_verde(void);{

    }
    void desactivar_ac_verde(void);{

    }

    void activar_ac_azul(void);{

    }
    void desactivar_ac_azul(void);{
        
    }
}


