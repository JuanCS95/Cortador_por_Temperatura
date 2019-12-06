#include "proteccionTermica.h"

void proteccionTermica_init(proteccionTermica * proteccionT,unsigned char estado, float tempCorte) {
	proteccionT->estado = estado;
	proteccionT->temperaturaDeCorte = tempCorte;
}

void proteccionTermica_update(proteccionTermica * proteccionT) {
	switch (proteccionT->estado) {
	case Encendido: {
		if (proteccionT->temperatura > proteccionT->temperaturaDeCorte) {
			proteccionT->estado = Apagado;
		}
		break;
	}
	}
}
unsigned char getEstado(proteccionTermica* model){
	return model->estado;
}

void apagarProteccion(proteccionTermica* proteccionT){
	proteccionT->estado = Apagado;
}

void temperatura_update(proteccionTermica* proteccionT, float temp){
	proteccionT->temperatura = temp;
}
