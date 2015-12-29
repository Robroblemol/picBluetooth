#include "picBluetooth.h"
char cad = ' ';

void main()
{

   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   setup_oscillator(False);

   delay_ms(500);

   while (true) {
       if(kbhit()){// si recivimos datos
          cad = getc();// se guardan en cad
          delay_ms(50);//espremos 50ms
          putc(cad);//devolvemos lo recivido
       }
       if(cad == 'a'|| cad == 'A'){// si cad igual 'a'
       output_high(led);// led encendido
      }
       if(cad == 'b'|| cad == 'B'){//si cad igual 'b'
         output_low(led);//led apagado
       }
       if (cad == 'c'|| cad == 'C') {//si cad igual 'c'
         output_toggle(led);//led toggle
         cad = 's';
       }
       if(input(boton)==0){// si boton presionado (activo bajo)
         delay_ms(500);// evitamos el rebote
          printf("Probando envio de datos\r\n");//envio mensaje
       }
       if(cad == ' '){//si cad en estado inicial
         output_toggle (led);//cada segundo enciendo y apago el led
         delay_ms(1000);
       }
   }

}
