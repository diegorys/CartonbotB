/*
  ActuadorRueda.h - Librería para el manejo de una rueda del robot.
  
  Created  2013 Sep 1
  Version 1.0
 */

// Incluye el archivo de descripción.
#include "ActuadorRueda.h"

   
/** CONSTRUCTORES **/

/**
 * Constructor vacío. Usar sólo en la declaración.
 */
ActuadorRueda::ActuadorRueda()
{
}

/**
 * Constructor principal que inicializa los parámetros.
 * @param pin: pin donde está ubicado el servo.
 */
ActuadorRueda::ActuadorRueda(int pin){
	servo.attach(pin);
}

/** MÉTODOS PÚBLICOS **/

/**
 * Comienza a andar.
 */
void ActuadorRueda::avanzar(int velocidad /*= 40*/){
	servo.write(95+velocidad);
}

/**
 * Comienza a andar hacia atrás.
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