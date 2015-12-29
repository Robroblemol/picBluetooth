# picBluetooth
Programa de prueba para el modulo Bluetooth HC-06 probado con Protocoder ejemplo Bluetooth
El progama enciende y a paga el led conectado en el pin_E0

si enviamos lso siguienetes datos:
a = encendemos led
b = apagamos led
c = toggle led

si en el presionamos el boton en el pin_C2 enviamos mensaje de confirmacion de envio de dato

# Configuracion Comandos AT
Para enviar los comndos AT resulta mas sencillo con la herramienta UART del
pickit 2 no sin antes deshabilitar el checkbox append CR+LF (x0D+x0A)
Ejemplo: AT+VERSION // para ver la version del modulo 

Datasheet Modulo HC-06 
https://www.olimex.com/Products/Components/RF/BLUETOOTH-SERIAL-HC-06/resources/hc06.pdf

# Consideraciones 
Para que la aplicacion de protocoder funcione de forma optima el telefono no debe estas conectado a ningun otro dispositivo.

La configuracion en el pic1f4550 como se utiliza el bootloader se debe configurar el #use delay(#use delay(clock=48000000)) a 48Mhz 
que es la velocidad a la que opera el bootloader (y no se puede modificar, por lo menos no se debe).

Para usar el compilador por consola con los Pic18f es necesario agregar el comando +fh.
ejemplo: ccsc +fh +df +pe picBluetooth.c
