/*
  SensorDistancia.h - Librer�a para el sensor que mide distancias.
  
  Created  2013 Apr 20
  Version 1.0
*/

// ensure this library description is only included once
#ifndef SensorDistancia_h
#define SensorDistancia_h
#define LIBRARY_VERSION	 0.1

// include core Wiring API and now Arduino
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

// Clase SensorDistancia
class SensorDistancia {
 
	/** Elementos p�blicos de la interfaz. **/
	public:
	
		/** CONSTRUCTORES **/

		/**
		 * Constructor vac�o. Usar s�lo en la declaraci�n.
		 */
		SensorDistancia();

		/**
		 * Constructor principal que inicializa los par�metros.
		 * @param pin: pin donde est� ubicado el sensor.
		 */
		SensorDistancia(int pin);
	
		/** M�TODOS **/

		/**
		 * Mide la distancia al pr�ximo obst�culo.
		 */
		float medir();

	private:

		/** Variable que mide el pulso **/
		unsigned long pulso;

		/** Variable para el c�lculo de distancia **/
		float distancia;

		/** Pin al que est� conectado el sensor */
		float pinDistancia;

};

#endif
