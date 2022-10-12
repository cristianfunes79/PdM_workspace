# PdM_workspace
STM32CubeIDE workspace para Programación de microcontroladores - CESE - FIUBA

## Practica 1
### Ejercicio 1
Implementar un programa que genere una secuencia periódica con los leds de la placa NUCLEO-F429ZI.

La secuencia debe seguir el orden: LED1, LED2, LED3, LED1,... etc.
Cada led debe permanecer encendido 200 ms. y 200 ms apagado.  No debe encenderse más de un led simultáneamente.

### Ejercicio 2
Utilizar el pulsador azul (USER_BUTTON) para controlar cómo se recorre la secuencia de leds.  Cada vez que se presiona el pulsador se debe alternar el orden de la secuencia entre:
1. LED1, LED2, LED3, LED1,... etc.
2. LED1, LED3, LED2, LED1,... etc.


## Practica 2
### Ejercicio 1
Implementar las funciones auxiliares necesarias para usar retardos no bloqueantes en un archivo fuente main.c con su correspondiente archivo de cabecera main.h.
En main.h se deben ubicar los prototipos de las siguientes funciones y las declaraciones
```
typedef uint32_t tick_t; // Qué biblioteca se debe incluir para que esto compile?
typedef bool bool_t;	  // Qué biblioteca se debe incluir para que esto compile?
typedef struct{
   tick_t startTime;
   tick_t duration;
   bool_t running;
} delay_t;
void delayInit( delay_t * delay, tick_t duration );
bool_t delayRead( delay_t * delay );
void delayWrite( delay_t * delay, tick_t duration );
```
### Ejercicio 2
Implementar un programa que utilice retardos no bloqueantes y  haga titilar en forma periódica e independiente los tres leds de la placa NUCLEO-F429ZI de la siguiente manera:
- LED1: 100 ms. 
- LED2: 500 ms.
- LED3: 1000 ms.

## Practica 3
### Ejercicio 1
Crear un nuevo proyecto como copia del proyecto realizado en la practica 2. Crear una carpeta API, src, Inc y colocar alli las funciones de retardos no bloqueantes.

### Ejercicio 2
Implementar el ejercicio de la Practica 1 usando retardos no bloqueantes.

## Practica 4
### Ejercicio 1
Implementar una MEF anti-rebote que permita leer el estado del pulsador de la placa NUCLEO-F429ZI y generar acciones o eventos ante un flanco descendiente o ascendente, de acuerdo al diagrama.

### Ejercicio 2
Implementar el Ejercicio anterior pero creando la MEF en modulos distintos.

## Practica 5
### Ejercicio 1
Implementar un módulo de software en un archivos fuente API_uart.c con su correspondiente archivo de cabecera API_uart.h y ubicarlos en el proyecto dentro de  las carpetas /drivers/API/src y /drivers/API/inc, respectivamente.
En API_uart.h se deben ubicar los prototipos de las funciones públicas.
bool_t uartInit();
void uartSendString(uint8_t * pstring);
void uartSendStringSize(uint8_t * pstring, uint16_t size);
void uartReceiveStringSize(uint8_t * pstring, uint16_t size);

En API_uart.c se deben ubicar los prototipos de las funciones privadas y la implementación de todas las funciones de módulo, privadas y públicas.
Consideraciones para la implementación:
uartInit() debe realizar toda la inicialización de la UART.  Adicionalmente, debe imprimir por la terminal serie un mensaje con sus parámetros de configuración.

La función devuelve:
true: si la inicialización es exitosa.
false: si la inicialización no es exitosa.
uartSendString(uint8_t *pstring) recibe un puntero a un string que se desea enviar por la UART completo (hasta el caracter ‘\0’) y debe utilizar la función de la HAL HAL_UART_Transmit(...) para transmitir el sting.
uartSendStringSize(uint8_t * pstring, uint16_t size) recibe un puntero a un string que se desea enviar por la UART y un entero con la cantidad de caracteres que debe enviar. La función debe utilizar HAL_UART_Transmit(...) para transmitir el string.

### Ejercicio 2
Sobre el ejercicio de la práctica 4, implementar un programa que utilice el módulo de uart para informar al usuario cuando se producen los flancos ascendente y descendente.
