/*
  SensorDistancia.h - Librer�a para el sensor que mide distancias.
  
  Created  2013 Aug 29
  Version 1.0
 */

// Incluye el archivo de descripci�n.
#include "SensorDistancia.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vac�o. Usar s�lo en la declaraci�n.
 */
SensorDistancia::SensorDistancia()
{
}

/**
 * Constructor principal que inicializa los par�metros.
 * @param pin: pin donde est� ubicado el sensor.
 */
SensorDistancia::SensorDistancia(int pin){
	pinDistancia = pin;
}

/** M�TODOS P�BLICOS **/

/**
 * Mide la distancia al pr�ximo obst�culo.
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