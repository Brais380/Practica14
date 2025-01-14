/*
Esta practica consistia en aprobechar un circuto ya hecho 
anteriormente y condicionar la secuencia de encendido de sus 
pilotos en este caso mediante un pulsador cuando dicho pulsador 
este desactivado el sistema funcionara con normalidade haciendo 
la secuencia programada, en caso de que este pulsado este 
presionado bloqueara el sistema y apagara los pilotos.

Autor: Brais Rey Mirón
Fecha: 13 / Enero / 2025
*/

#define LED_A 13
#define LED_V 12
#define RELE  11
#define PULS  10
 
bool pulsador = 0;
int tiempo = 4000;
   
void setup() {
 pinMode(LED_A, OUTPUT);
 pinMode(LED_V, OUTPUT);
 pinMode(RELE, OUTPUT);
 pinMode(PULS, INPUT);
}

void loop() {
 pulsador = digitalRead(PULS);
 if (pulsador != 1) {// Condicion (SI) para activar
  leds_on();
 } 
 else {// Condicion (SI NO) para desactivar
  leds_off(); 
 }
}

void leds_on() {
 digitalWrite(LED_A, HIGH);// Activación led amarillo// Activación led amarillo
 delay(tiempo); // Espera por 4000 milisegundo(s)
 digitalWrite(LED_A, LOW);// Desactivación led amarillo
 delay(tiempo/2); // Espera por 2000 milisegundo(s)
 digitalWrite(RELE, HIGH);// Activación rele
 digitalWrite(LED_V, HIGH);// Activación led verde
 delay(tiempo); // Espera por // Activación rele4000 milisegundo(s)
 digitalWrite(RELE, LOW);// Desactivación rele
 digitalWrite(LED_V, LOW);// Desactivación led verde
 delay(tiempo/2); // Espera por 2000 milisegundo(s)
}

void leds_off() {
 digitalWrite(LED_A, LOW);// Desactivación led amarillo
 digitalWrite(LED_V, LOW);// Desactivación led verde
 digitalWrite(RELE, LOW);// Desactivación rele
}
