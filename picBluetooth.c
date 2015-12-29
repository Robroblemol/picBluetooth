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
       if(kbhit()){
          cad = getc();
          delay_ms(50);
          putc(cad);
       }
       if(cad == 'a'){
       output_high(led);
      }
       if(cad == 'b'){
         output_low(led);
       }
       if (cad == 'c') {
         output_toggle(led);
         cad = 's';
       }
       if(input(boton)==0){
         delay_ms(500);
          printf("Probando envio de datos\r\n");
       }
       if(cad == ' '){
         output_toggle (led);
         delay_ms(1000);
       }
   }

}
