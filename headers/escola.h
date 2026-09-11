#include "constants.h"
#include <stdint.h>


#ifndef _ESCOLA
#define _ESCOLA

	void cadastrar(void* lista, int index, uint8_t tipo);
	void input_individuo(individuo* lista, int index);
		
	#define inicializar_lista(lista, tam)		\
		for (size_t i = 0; i < tam; ++i){	\
			ptr_lista[i].estado = NAO_ATIVO \
		}

#endif
