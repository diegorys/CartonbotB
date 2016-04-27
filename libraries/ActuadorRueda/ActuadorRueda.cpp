/*
  ActuadorRueda.h - Librer�a para el manejo de una rueda del robot.
  
  Created  2013 Sep 1
  Version 1.0
 */

// Incluye el archivo de descripci�n.
#include "ActuadorRueda.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vac�o. Usar s�lo en la declaraci�n.
 */
ActuadorRueda::ActuadorRueda()
{
}

/**
 * Constructor principal que inicializa los par�metros.
 * @param pin: pin donde est� ubicado el servo.
 */
ActuadorRueda::ActuadorRueda(int pin){
	servo.attach(pin);
}

/** M�TODOS P�BLICOS **/

/**
 * Comienza a andar.
 */
void ActuadorRueda::avanzar(int velocidad /*= 40*/){
	servo.write(95+velocidad);
}

/**
 * Comienza a andar hacia atr�s.
 */
void ActuadorRueda::retroceder(int velocidad /*= 40*/){
	servo.write(95-velocidad);
}

/**
 * Detiene la marcha.
 */
void ActuadorRueda::parar(){
	servo.write(95);
}