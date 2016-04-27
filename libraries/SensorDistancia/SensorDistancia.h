/*
  SensorDistancia.h - Librería para el sensor que mide distancias.
  
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
 
	/** Elementos públicos de la interfaz. **/
	public:
	
		/** CONSTRUCTORES **/

		/**
		 * Constructor vacío. Usar sólo en la declaración.
		 */
		SensorDistancia();

		/**
		 * Constructor principal que inicializa los parámetros.
		 * @param pin: pin donde está ubicado el sensor.
		 */
		SensorDistancia(int pin);
	
		/** MÉTODOS **/

		/**
		 * Mide la distancia al próximo obstáculo.
		 */
		float medir();

	private:

		/** Variable que mide el pulso **/
		unsigned long pulso;

		/** Variable para el cálculo de distancia **/
		float distancia;

		/** Pin al que está conectado el sensor */
		float pinDistancia;

};

#endif
