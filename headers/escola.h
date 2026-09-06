#include "constants.h"
#include <stdint.h>


#ifndef _ESCOLA
#define _ESCOLA

	void cadastrar(void* lista, int index, uint8_t tipo);
	void inicializar_lista(void* lista, size_t tam, uint8_t tipo);
	void input_individuo(individuo* lista, int index);

#endif
