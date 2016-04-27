/*
  HabilidadNavegar.h - Librer�a que representa la habilidad de navegaci�n.
  
  Created  2013 Aug 30
  Version 0.1
*/

// ensure this library description is only included once
#ifndef HabilidadNavegar_h
#define HabilidadNavegar_h
#define LIBRARY_VERSION	 0.1

// include core Wiring API and now Arduino
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "SensorDistancia.h"
#include "ActuadorRueda.h"

// Clase HabilidadNavegar
class HabilidadNavegar {
 
	/** Elementos p�blicos de la interfaz. **/
	public:
	
		/** CONSTRUCTORES **/

		/**
		 * Constructor vac�o.
		 */
		HabilidadNavegar();

		/** M�TODOS P�BLICOS **/
		
		/**
		 * Asigna las piezas a la habilidad.
		 * @param sDistancia: sensor de distancia.
		 * @param rDerecha:	  rueda derecha.
		 * @param rIzquierda: rueda izquierda.
		 */
		void asignarPiezas(SensorDistancia sDistancia, ActuadorRueda rDerecha, ActuadorRueda rIzquierda);

		/**
		 * Ejecuta un ciclo de la habilidad.
		 * @return: true si no ha acabado la ejecuci�n. False en caso contrario.
		 */
		bool ejecutar();

		/** M�TODOS DE NAVEGACI�N **/

		//TODO: Pasar a habilidades.

		/**
		 * Hace avanzar al robot.
		 */
		void avanzar(int velocidad);

		/**
		 * Hace retroceder al robot.
		 */
		void retroceder();

		/**
		 * Detiene al robot.
		 */
		void parar();

		/**
		 * Hace girar a la derecha al robot.
		 */
		void girarDerecha();

		/**
		 * Hace girar a la izquierda al robot.
		 */
		void girarIzquierda();

		/**
		 * Hace rotar a la derecha al robot.
		 */
		void rotarDerecha();

		/**
		 * Hace rotar a la izquierda al robot.
		 */
		void rotarIzquierda();

	private:

		/** ATRIBUTOS **/

		/* Par�metros */

		//Distancia al siguiente obst�culo.
		int distancia;

		//Estado del robot: 1 normal, 2 peligro, 3 chocado.
		int estado;

		/* Piezas */

		//Sensor que mide las distancias.
		SensorDistancia sensorDistancia;

		//Ruedas derecha e izquierda
		ActuadorRueda ruedaDerecha;
		ActuadorRueda ruedaIzquierda;

};

#endif
