#include <HabilidadNavegar.h>
#include <ActuadorRueda.h>
#include <SensorDistancia.h>
#include <Servo.h>

/****************************************/
/***** EJEMPLO USO HABILIDAD NAVEGAR ****/
/****************************************/
/* Autor: Diego de los Reyes Rodríguez. */
/****************************************/

  /** VARIABLES **/

//Habilidad de navegación.
HabilidadNavegar navegacion;

//Sensor de distancia;
SensorDistancia sensorDistancia;

//Ruedas
ActuadorRueda ruedaDerecha;
ActuadorRueda ruedaIzquierda;

/** FUNCIONES ARDUINO **/

/**
 * Se ejecuta al arrancar el programa.
 */
void setup() {
  Serial.begin(9600);
  
  navegacion      = HabilidadNavegar();
  sensorDistancia = SensorDistancia(8);
  ruedaDerecha    = ActuadorRueda(6);
  ruedaIzquierda  = ActuadorRueda(9);
  
  navegacion.asignarPiezas(sensorDistancia, ruedaDerecha, ruedaIzquierda);
}

/**
 * Bucle infinito de ejecución.
 */
void loop() {
    navegacion.ejecutar();
}
