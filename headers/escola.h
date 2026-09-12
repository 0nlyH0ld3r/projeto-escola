#include "constants.h"
#include <stdint.h>


#ifndef _ESCOLA
#define _ESCOLA

	void cadastrar(void* lista, int index, uint8_t tipo);
	void cadastro_individuo(individuo* lista, size_t tam);
	void cadastro_disciplina(disciplina* lista, individuo* lista_prof, size_t tam);
	void input_individuo(individuo* lista);
	void input_disciplina(disciplina* lista, individuo* lista_prof);
		
	#define inicializar_lista(lista, tam)		\
		for (size_t i = 0; i < tam; ++i){	\
			lista[i].estado = NAO_ATIVO; \
		}

#endif
