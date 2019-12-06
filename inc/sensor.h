/*
 * sensor.h
 *
 *  Created on: Oct 4, 2019
 *      Author: user
 */

#ifndef PROGRAMS_CORTADOR_POR_TEMPERATURA_INC_SENSOR_H_
#define PROGRAMS_CORTADOR_POR_TEMPERATURA_INC_SENSOR_H_

#include <sapi.h>


	typedef void (* sensorHandler)(float temp, void * model);
	typedef struct sensorTemperatura {
		sensorHandler funcionTemperatura;
		void * model;
		MPU9250_address_t direccion;

	}sensorTemperatura;

	void sensorTemperatura_init(sensorTemperatura* sensor, void * model, sensorHandler funcion);
	void sensor_update(sensorTemperatura* sensor);



#endif /* PROGRAMS_CORTADOR_POR_TEMPERATURA_INC_SENSOR_H_ */
