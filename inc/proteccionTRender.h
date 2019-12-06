#include "proteccionTermica.h"
#include "sapi.h"
#ifndef PROGRAMS_CORTADOR_POR_TEMPERATURA_INC_PROTECCIONTRENDER_H_
#define PROGRAMS_CORTADOR_POR_TEMPERATURA_INC_PROTECCIONTRENDER_H_

enum estado {
	Bien, Aceptable, Alerta, Peligro
};

	typedef struct proteccionTRender {
		proteccionTermica* proteccion;
		int estadoRender;
		gpioMap_t ledOk;
		gpioMap_t ledFine;
		gpioMap_t ledwarning;
		gpioMap_t ledDanger;
		gpioMap_t salida;
	}proteccionTRender;

	void proteccionTRender_init(proteccionTRender* proteccionTR, proteccionTermica * proteccionT,gpioMap_t ledOk,gpioMap_t ledFine, gpioMap_t ledWarning, gpioMap_t ledDanger, gpioMap_t salida);
	void proteccionTRender_Update(proteccionTRender* proteccionR, proteccionTermica* proteccion);

#endif /* PROGRAMS_CORTADOR_POR_TEMPERATURA_INC_PROTECCIONTRENDER_H_ */
