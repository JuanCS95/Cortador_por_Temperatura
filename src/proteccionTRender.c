#include "proteccionTRender.h"
#include <sapi.h>

void proteccionTRender_init(proteccionTRender* proteccionRender,
		proteccionTermica * proteccion, gpioMap_t ledOk,
		gpioMap_t ledFine,gpioMap_t ledWarning,
		gpioMap_t ledDanger, gpioMap_t salida) {

	proteccionRender->proteccion = proteccion;

	proteccionRender->ledOk = ledOk;
	proteccionRender->ledFine = ledFine;
	proteccionRender->ledwarning = ledWarning;
	proteccionRender->ledDanger = ledDanger;
	proteccionRender->salida = salida;
}

void proteccionTRender_Update(proteccionTRender * proteccionR,
		proteccionTermica * proteccion) {
	switch (proteccionR->estadoRender) {
	case Bien: {
		gpioWrite(proteccionR->ledOk, 1);
		gpioWrite(proteccionR->ledFine, 0);
		gpioWrite(proteccionR->ledwarning, 0);
		gpioWrite(proteccionR->ledDanger, 0);
		gpioWrite(proteccionR->salida,getEstado(proteccion));
		if (proteccion->temperatura > 28) {
			proteccionR->estadoRender = Aceptable;
		}
	}
		break;
	case Aceptable: {
		gpioWrite(proteccionR->ledOk, 0);
		gpioWrite(proteccionR->ledFine, 1);
		gpioWrite(proteccionR->ledwarning, 0);
		gpioWrite(proteccionR->ledDanger, 0);
		gpioWrite(proteccionR->salida,getEstado(proteccion));
		if (proteccion->temperatura > 30) {
			proteccionR->estadoRender = Alerta;
		}
		if (proteccion->temperatura < 28) {
			proteccionR->estadoRender = Bien;
		}
	}
		break;
	case Alerta: {
		gpioWrite(proteccionR->ledOk, 0);
		gpioWrite(proteccionR->ledFine, 0);
		gpioWrite(proteccionR->ledwarning, 1);
		gpioWrite(proteccionR->ledDanger, 0);
		gpioWrite(proteccionR->salida,getEstado(proteccion));
		if (proteccion->temperatura > proteccion->temperaturaDeCorte) {
			proteccionR->estadoRender = Peligro;
		}
		if (proteccion->temperatura < 30) {
			proteccionR->estadoRender = Aceptable;
		}
		break;
		case Peligro:
		{
			gpioWrite(proteccionR->ledOk, 0);
			gpioWrite(proteccionR->ledFine, 0);
			gpioWrite(proteccionR->ledwarning, 0);
			gpioWrite(proteccionR->ledDanger, 1);
			gpioWrite(proteccionR->salida,getEstado(proteccion));
			if (proteccion->temperatura < proteccion->temperaturaDeCorte) {
				proteccionR->estadoRender = Alerta;
			}
			break;
		}
	}
	}
}
