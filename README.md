# 📋 Documentación de DOJO Nº1 SPD Div. 1º G. UTN FRA Grupo Nº 5.  

Prototipo de semáforo con indicación sonora para personas no videntes realizado en Arduino. Trabajo practico nº 1 de materia SPD, Tecnicatura en Programación UTN FRA.

![Imagen no encontrada](./img/ArduinoTinkercad.jpg "banner Intercad")

### Autores ✒️
***
* **Franco Mendieta** 
* **Fernando Malinowski** 
* **Facundo Leonelli** 
* **Carlos Marquez** 
* **Tadeo Iuliani**  

⌨️ con ❤️ por grupo nº5 SPD, DIV G.
## Proyecto: Semáforo Adaptado para personas no videntes.
***
![Imagen no encontrada](./img/Dojo%201%20-%20Sem%C3%A1foro%20adaptado%20V1.png "DOJO Nº1 SPD Div. 1º G. UTN FRA Grupo Nº 5.")

## Comenzando 🚀
***
Estas instrucciones te permitirán comprender el funcionamiento del proyecto. Además, se incluye el enlace hacia TinkerCad para poder ver el proyecto armado con sus distintos componentes y poner el código en ejecución. 

Ve a la sección de **link al proyecto** para ver el código del proyecto.

## Consigna 🔩

1- El semáforo tiene que tener 2 leds de cada color como minimo, en caso de que uno se
rompa, lo ideal serian 3.

2- Tiene que implementar los tiempos correctos como se detallan a continuación.

3- El verde dura 45 segundos.

4- El amarillo dura 5 segundos.

5- Rojo dura 30 segundos.

6- Tiene que tener señalización para personas no videntes como se detalla a
continuación.

7- Durante el verde: No sonar

8- Durante el amarillo: Tiene que sonar 1 vez cada 2 segundos en un tono suave.

9- Durante el rojo: Tiene que sonar 1 vez por segundo en un tono fuerte.

## Función principal 🔩

* * *

 ~~~ C (Lenguaje del código)
void changeStatusDelay(int nombreLed1,
                       int nombreLed2,
                       int piezoStatus,
                      int timer)
{
  int prendido_alto = 400;
  int apagado_alto = 600;
  int prendido_bajo = 1000;
  int apagado_bajo = 1000;
  unsigned long tiempo1 = 0;
  unsigned long tiempo2 = 0;
  long lapseTime = 0;
  
  digitalWrite(nombreLed1, 1);
  digitalWrite(nombreLed2, 1);
  lapseTime = 0;
  tiempo1 = millis();
  
  if (piezoStatus == 2)
 {
     while ( lapseTime < timer )
    {
      digitalWrite(ALTO, 1);
      delay(prendido_alto);
      digitalWrite(ALTO, 0);
      delay(apagado_alto);
      tiempo2 = millis();
      lapseTime = (tiempo2 - tiempo1);
      
    }
 }
  else
 {
    if (piezoStatus == 1)
    {
       while ( lapseTime < timer )
      {
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
        tiempo2 = millis();
        lapseTime = (tiempo2 - tiempo1);
        
      }
    }
     else
     {
       if (piezoStatus == 0)
       {
         tiempo1 = millis();
         delay(timer);
         tiempo2 = millis();
         lapseTime = (tiempo2 - tiempo1);
       }
     }
   }
    digitalWrite(ALTO, 0);
    digitalWrite(BAJO, 0);
    digitalWrite(nombreLed1, 0);
    digitalWrite(nombreLed2, 0);
  }
 ~~~

## Explicación Función principal.
* * * 
## Parámetros de la función:
 ~~~ C
 void changeStatusDelay(int nombreLed1,
                       int nombreLed2,
                       int piezoStatus,
                      int timer)
 ~~~
- nombreLed1, nombreLed2:  
pares de leds a encender / apagar 
- piezoStatus:  
2 = sonido alto cada 1 seg  
1 = sonido bajo cada 2 seg  
0 = sin sonido
- timer:  
tiempo dado en milisegundos en el que los leds permanecen encendidos

## Hardcodeo interno de la función:
 ~~~ C
  int prendido_alto = 400;
  int apagado_alto = 600;
  int prendido_bajo = 1000;
  int apagado_bajo = 1000;
  unsigned long tiempo1 = 0;
  unsigned long tiempo2 = 0;
  long lapseTime = 0;
 ~~~

Estas variables marcan los tiempos (en milisegundos) de permanencia cada estado (prendidos y apagado) de 
los sonidos altos y bajos:

- int prendido_alto = 400  
milisegundos en el que el sonido alto esta encendido
- int apagado_alto = 600  
milisegundos en el que el sonido alto esta apagado
- int prendido_bajo = 1000  
milisegundos en el que el sonido bajo esta encendido
- int apagado_bajo = 1000  
milisegundos en el que el sonido bajo esta apagado  
##### Obs: Si se quieren modificar estos tiempos, se debe modificar la función (para este pequeño proyecto no es necesario parametrizarlos).  


### Cuerpo de la función:
~~~ C
  digitalWrite(nombreLed1, 1);
  digitalWrite(nombreLed2, 1);
  lapseTime = 0;
  tiempo1 = millis();
~~~
##### Obs: digitalWrite(nombreled1, 1) es una función de de la librería de Arduino. El primer parámero esta asociado a un pin de la placa de arduino, el segundo, energiza (1 o HIGH) o apaga el mismo (0 o LOW).
- Por lo tanto en nuestra función los dos digitalWrite energizan los leds conectados a los puertos asociados a nombreLed1 y nombreLed2.
- A continuación setea el lapseTime en cero.
- Luego la función millis() guarda el tiempo de desde que se inició el programa en la variable tiempo1.

#### Dependiendo del valor de piezoStatus se abre un `if` que dependiendo del valor de `piezoStatus` se ejecutan 3 ciclos `while`:

### Si `piezoStatus == 2 `:
~~~ C
if (piezoStatus == 2)
 {
     while (lapseTime < timer )
    {
      digitalWrite(ALTO, 1);
      delay(prendido_alto);
      digitalWrite(ALTO, 0);
      delay(apagado_alto);
      tiempo2 = millis();
      lapseTime = (tiempo2 - tiempo1);
      
    }
 }
~~~
- Comienza ciclo while para el ***sonido alto***:   
    - Prende y apaga el sonido alto una vez por ciclo, con los tiempos configurados al principio de la función.
    - Luego, en la variable tiempo2 se guarda el tiempo actual de ejecucion del programa.  
    - Se calcula la diferencia de tiempo entre tiempo2 y tiempo1 y se guarda en la variable lapseTime.  
     -Si ese lapso de tiempo es inferior al timer establecido como argumento `lapseTime < timer` se vuelve a inicar el ciclo hasta dejar de cumplir la condición del while.

### Si `piezoStatus = 1`:
~~~ C
 else
 {
    if (piezoStatus == 1)
    {
       while ( lapseTime < timer )
      {
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
        tiempo2 = millis();
        lapseTime = (tiempo2 - tiempo1);
        
      }
    }
~~~
- Comienza otro ciclo while para el ***sonido bajo***:   
    - Es similar al ciclo anterior,  pero prende y apaga el sonido bajo 3 veces por ciclo.
    - Luego el control de tioempo es igual que en caso anterior.

### Si `piezoStatus = 0`:
~~~ C
else
     {
       if (piezoStatus == 0)
       {
         delay(timer);
       }
     }
   }
~~~
- Caso ***sin sonido***:   
    -  Simplemente ejecuta el timer u cierra la llave del primer if.

### Pie de la función:
~~~ C
    digitalWrite(ALTO, 0);
    digitalWrite(BAJO, 0);
    digitalWrite(nombreLed1, 0);
    digitalWrite(nombreLed2, 0);
  }
~~~
- Sin importar el valor del parametro `piezoStatus`
    siempre se ejecuta el siguiente algoritmo al final de la función (estan fuera del primer `if`):
    - Apaga el sonido y apaga y el apr de leds.
    - La ultima llave indica el cierre de la función.



## 🤖 Link al proyecto 
---

 Proyecto [Semáforo Adaptado ](https://www.tinkercad.com/things/8oHwzMKlTXf-dojo-1-semaforo-adaptado-v1/editel?sharecode=JPbVYoZY0ViAlwjupwjPqmmHtwbsWOnT7YtB-P6JKZs "Enlace del proyecto en Tinkercad") TinkerCad.
 - - - 

##  📘 Fuentes
---
- [Tecnicatura Universitaria en Programación - UTN](http://www.sistemas-utnfra.com.ar/#/pages/carrera/tecnico-programacion/resumen)
- [Consejos para documentar](https://www.sohamkamani.com/how-to-write-good-documentation/#architecture-documentation).

- [Lenguaje Markdown](https://markdown.es/sintaxis-markdown/#linkauto).

- [Markdown Cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet).

- [Emojis](https://gist.github.com/rxaviers/7360908).  
