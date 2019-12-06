#include "sensor.h"
#include <sapi.h>

MPU9250_address_t addr = MPU9250_ADDRESS_0;

void sensorTemperatura_init(sensorTemperatura* sensor, void * model, sensorHandler funcion) {
	int8_t status;
	status = mpu9250Init( addr );

	bool_t mpuRead;
	mpuRead = mpu9250Read();


	sensor->model = model;
	sensor->funcionTemperatura = funcion;
}

void sensor_update(sensorTemperatura* sensor){
	mpu9250Read();
	sensor->funcionTemperatura(mpu9250GetTemperature_C(), sensor->model);
}
