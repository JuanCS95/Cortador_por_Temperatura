#include "sensor.h"
#include "proteccionTermica.h"
#include "proteccionTRender.h"
#include <sapi.h>
#include "Button.h"



void sensorUpdate(float temp, void * model){
	temperatura_update((proteccionTermica *)model, temp);
}

void buttonResetPressed(void * model){
	proteccionTermica * p = (proteccionTermica *) model;
	if(p->temperatura < p->temperaturaDeCorte){
		p->estado = Encendido;
	}
}

int main(void){
	boardConfig();
	gpioInit(GPIO0,GPIO_OUTPUT);


	proteccionTermica proteccionT;
	proteccionTermica_init(&proteccionT,Encendido, 33);
	sensorTemperatura sensor;
	proteccionTRender proteccionRender;


	sensorTemperatura_init(&sensor, &proteccionT, sensorUpdate);

	proteccionTRender_init(&proteccionRender,&proteccionT,LED3, LED1, LED2,LEDB,GPIO0);

	Button buttonReset;

	button_init(&buttonReset,TEC4, &proteccionT);
	button_onPress(&buttonReset, buttonResetPressed);

	while(1){

		button_update(&buttonReset);
		sensor_update(&sensor);
		proteccionTermica_update(&proteccionT);
		printf( "Temperatura:    %f   [C]\r\n\r\n", mpu9250GetTemperature_C());

		proteccionTRender_Update(&proteccionRender, &proteccionT);

		delay(100);
	}
}
