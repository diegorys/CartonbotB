/*
  SensorDistancia.h - Librería para el sensor que mide distancias.
  
  Created  2013 Aug 29
  Version 1.0
 */

// Incluye el archivo de descripción.
#include "SensorDistancia.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vacío. Usar sólo en la declaración.
 */
SensorDistancia::SensorDistancia()
{
}

/**
 * Constructor principal que inicializa los parámetros.
 * @param pin: pin donde está ubicado el sensor.
 */
SensorDistancia::SensorDistancia(int pin){
	pinDistancia = pin;
}

/** MÉTODOS PÚBLICOS **/

/**
 * Mide la distancia al próximo obstáculo.
 */
float SensorDistancia::medir(){
	pinMode(pinDistancia, OUTPUT);				 // ponemos el pin como salida
	digitalWrite(pinDistancia, HIGH);			 // lo activamos
	delayMicroseconds(10);						 // esperamos 10 microsegundos
	digitalWrite(pinDistancia, LOW);			 // lo desactivamos
	pinMode(pinDistancia, INPUT);				 // cambiamos el pin como entrada
	pulso = pulseIn(pinDistancia, HIGH);		 // medimos el pulso de salida del sensor
	distancia = ((float(pulso/1000.0))*34.32)/2; // calculamos la distancia
	delay(100);
	return distancia;
}