/*
  ActuadorRueda.h - Librer�a para el manejo de una rueda del robot.
  
  Created  2013 Sep 1
  Version 1.0
*/

// ensure this library description is only included once
#ifndef ActuadorRueda_h
#define ActuadorRueda_h
#define LIBRARY_VERSION	 1.0

// include core Wiring API and now Arduino
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <Servo.h>

// Clase ActuadorRueda
class ActuadorRueda {
 
	/** Elementos p�blicos de la interfaz. **/
	public:
	
		/** CONSTRUCTORES **/

		/**
		 * Constructor vac�o. Usar s�lo en la declaraci�n.
		 */
		ActuadorRueda();

		/**
		 * Constructor principal que inicializa los par�metros.
		 * @param pin: pin donde est� ubicado el servo.
		 */
		ActuadorRueda(int pin);
	
		/** M�TODOS **/

		/**
		 * Comienza a andar.
		 */
		void avanzar(int velocidad = 40);

		/**
		 * Comienza a andar hacia atr�s.
		 */
		void retroceder(int velocidad = 40);

		/**
		 * Detiene la marcha.
		 */
		void parar();

	private:

		/** ATRIBUTOS **/

		//Servo que mueve la pierna
		Servo servo;

};

#endif
