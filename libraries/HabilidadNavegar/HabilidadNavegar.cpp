/*
  HabilidadNavegar.h - Librería que representa la habilidad de navegación.
  
  Created  2013 Aug 30
  Version 0.1
*/

// Incluye el archivo de descripción.
#include "HabilidadNavegar.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vacío.
 */
HabilidadNavegar::HabilidadNavegar()
{
	pinMode(11, OUTPUT);
}

/** MÉTODOS PÚBLICOS **/

/**
 * Asigna las piezas a la habilidad.
 * @param sDistancia: sensor de distancia.
 * @param rDerecha:	  rueda derecha.
 * @param rIzquierda: rueda izquierda.
 */
void HabilidadNavegar::asignarPiezas(SensorDistancia sDistancia, ActuadorRueda rDerecha, ActuadorRueda rIzquierda){
	//Piezas
	sensorDistancia = sDistancia;
	ruedaDerecha    = rDerecha;
	ruedaIzquierda  = rIzquierda;
}

/**
 * Ejecuta un ciclo de la habilidad.
 * @return: true si no ha acabado la ejecución. False en caso contrario.
 */
bool HabilidadNavegar::ejecutar(){
	distancia = sensorDistancia.medir();
	Serial.println(distancia);

	//TODO: Algoritmo muy simple.
	if(distancia < 5){
		digitalWrite(11, HIGH);
		retroceder();
	}else if(distancia < 8){
		digitalWrite(11, HIGH);
		retroceder();
		delay(800);
		rotarDerecha();
		delay(950);
	}else{
		int vel = distancia;
		if(vel > 80){
			vel = 80;
		}
		digitalWrite(11, LOW);
		avanzar(vel);
	}

	delay(200);
}

/**
 * Hace avanzar al robot.
 */
void HabilidadNavegar::avanzar(int velocidad){
	ruedaDerecha.avanzar(velocidad);
	ruedaIzquierda.avanzar(velocidad);
}

/**
 * Hace retroceder al robot.
 */
void HabilidadNavegar::retroceder(){
	ruedaDerecha.retroceder(10);
	ruedaIzquierda.retroceder(10);
}

/**
 * Detiene al robot.
 */
void HabilidadNavegar::parar(){
	ruedaDerecha.parar();
	ruedaIzquierda.parar();
}

/**
 * Hace girar a la derecha al robot.
 */
void HabilidadNavegar::girarDerecha(){
	ruedaDerecha.parar();
	ruedaIzquierda.avanzar(20);
}

/**
 * Hace girar a la izquierda al robot.
 */
void HabilidadNavegar::girarIzquierda(){
	ruedaDerecha.avanzar(20);
	ruedaIzquierda.parar();
}

/**
 * Hace rotar a la derecha al robot.
 */
void HabilidadNavegar::rotarDerecha(){
	ruedaDerecha.retroceder(20);
	ruedaIzquierda.avanzar(20);
}

/**
 * Hace rotar a la izquierda al robot.
 */
void HabilidadNavegar::rotarIzquierda(){
	ruedaDerecha.avanzar(20);
	ruedaIzquierda.retroceder(20);
}