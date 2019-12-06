/*
 * relay.h
 *
 *  Created on: Oct 4, 2019
 *      Author: user
 */

#ifndef PROGRAMS_CORTADOR_POR_TEMPERATURA_INC_PROTECCIONTERMICA_H_
#define PROGRAMS_CORTADOR_POR_TEMPERATURA_INC_PROTECCIONTERMICA_H_

enum estadodeRelayy{
	Encendido, Apagado
};

	typedef struct proteccionTermica {
		float temperatura;
		int estado;
		float temperaturaDeCorte;
	}proteccionTermica;

	void proteccionTermica_init(proteccionTermica * proteccionT,unsigned char estado, float TempCorte);
	void proteccionTermica_update(proteccionTermica * proteccionT);
	unsigned char getEstado(proteccionTermica* model);
	void apagarProteccion(proteccionTermica* proteccionT);
	void temperatura_update(proteccionTermica* proteccionT, float temp);


#endif /* PROGRAMS_CORTADOR_POR_TEMPERATURA_INC_PROTECCIONTERMICA_H_ */
