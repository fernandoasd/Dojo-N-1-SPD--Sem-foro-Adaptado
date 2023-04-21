/*
Franco Mendieta
Fernando Malinowski
Facundo
Carlos M

DOJO Nº 1

1- El semáforo tiene que tener 2 leds de cada color como minimo, en caso de que uno se rompa, lo ideal serian 3.
2- Tiene que implementar los tiempos correctos como se detallan a continuación.
3- El verde dura 45 segundos.
4- El amarillo dura 5 segundos.
5- Rojo dura 30 segundos.
6- Tiene que tener señalización para personas no videntes como se detalla a continuación.
7- Durante el verde: No sonar
8- Durante el amarillo: Tiene que sonar 1 vez cada 2 segundos en un tono suave.
9- Durante el rojo: Tiene que sonar 1 vez por segundo en un tono fuerte.

*/

unsigned long tiempo1 = 0;
unsigned long tiempo2 = 0;
unsigned long lapseTime = 0;

int prendido_alto = 400; //milisegundos sonido alto encendido
int apagado_alto = 600;  //milisegundos sonido alto apagado
int prendido_bajo = 1000;//milisegundos sonido bajo encendido
int apagado_bajo = 1000; //milisegundos sonido bajo apagado

#define LED1 13
#define LED2 12
#define LED3 11
#define LED4 7
#define LED5 6
#define LED6 5
#define BAJO 3
#define ALTO 4


void setup()
{
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(BAJO, OUTPUT);
  pinMode(ALTO, OUTPUT);
  Serial.begin(9600);
}

/*
Declaración de función changeStatusDelay() :
 -nombreLed1,nombreLed2: puertos a manipular
 -piezoStatus: 
 	2 = sonido alto c/ 1 seg
    1 = sonido bajo c/ 2 seg
    0 = sin sonido

 -timer:
   tiempo dado en milisegundos en el que los leds permanecen encendidos

*/


void changeStatusDelay(int nombreLed1,
                       int nombreLed2,
                       int piezoStatus,
                      int timer)
{
  digitalWrite(nombreLed1, 1);
  digitalWrite(nombreLed2, 1);
  Serial.println("- LEDS ON -");
  lapseTime = 0;
  tiempo1 = millis();
  
  if (piezoStatus == 2)
 {
     while ( lapseTime < timer )
    {
      Serial.println("-------------------------- ROJO");
      digitalWrite(ALTO, 1);
      delay(prendido_alto);
      digitalWrite(ALTO, 0);
      delay(apagado_alto);
      tiempo2 = millis();
      Serial.print("TIME LAPSE: ");
      Serial.print(tiempo2 - tiempo1);
      lapseTime = (tiempo2 - tiempo1);
      
    }//end while
 } //end if
  else
 {
    if (piezoStatus == 1)
    {
       while ( lapseTime < timer )
      {
        Serial.println("-------------------------- AMARILLO");
        digitalWrite(BAJO, 1);
        delay(prendido_bajo);
        digitalWrite(BAJO, 0);
        delay(apagado_bajo);
        digitalWrite(BAJO, 1);
        delay(prendido_bajo);
        digitalWrite(BAJO, 0);
        delay(apagado_bajo);
        digitalWrite(BAJO, 1);
        delay(prendido_bajo);
        digitalWrite(BAJO, 0);
        Serial.print("TIME LAPSE: ");
        tiempo2 = millis();
        Serial.print(tiempo2 - tiempo1);
        lapseTime = (tiempo2 - tiempo1);
        
      } //end while
    } //end if
     else
     {
       if (piezoStatus == 0)
       {
         Serial.println("-------------------------- VERDE");
         tiempo1 = millis();
         delay(timer);
         tiempo2 = millis();
         Serial.print("TIME LAPSE: ");
         Serial.print(tiempo2 - tiempo1);
         lapseTime = (tiempo2 - tiempo1);
         
       }
     } //end else
   } //end else
    digitalWrite(ALTO, 0);
    digitalWrite(BAJO, 0);
    digitalWrite(nombreLed1, 0);
    digitalWrite(nombreLed2, 0);
    Serial.println("\n- LEDS OFF -\n");
  }

void loop()
{
  changeStatusDelay(LED1,LED2, 2, 30000); // LEDS ROJOS 30s
  changeStatusDelay(LED3,LED4, 1, 5000); // LEDS AMARILLOS 5s
  changeStatusDelay(LED5,LED6, 0, 45000); // LEDS VERDES 45s
}