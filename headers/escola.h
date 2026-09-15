#include "constants.h"
#include <stdint.h>


#ifndef _ESCOLA
#define _ESCOLA

	void cadastro_individuo(individuo* lista, size_t tam);
	void remover_individuo(individuo* pessoa);
	void atualizar_individuo(individuo* pessoa, int opcao);
	void input_individuo(individuo* lista, int opcao);

	void cadastro_disciplina(disciplina* lista, individuo* lista_prof, size_t tam);
	void remover_disciplina(disciplina* pessoa);
	void atualizar_disciplina(disciplina* disciplina, int opcao);
	void input_disciplina(disciplina* lista, individuo* lista_prof, int opcao);
		
	#define inicializar_lista(lista, tam)		\
		for (size_t i = 0; i < tam; ++i){	\
			lista[i].estado = NAO_ATIVO; \
		}

#endif
