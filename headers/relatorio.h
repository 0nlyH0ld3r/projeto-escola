#include "constants.h"
#include "escola.h"

#ifndef _RELATORIO
	#define _RELATORIO
	/* Abstração para chamar chamar funções de ordenação como parâmetros de outras 
	 * funções (no caso as de ordenação). 
	 * @par
	 * Cria um typedef que é um void* ptr  com parâmetros (individuo*, size_t),
	 * tal qual as funções de ordenação que serão criadas agora.
	 * @par note
	 * void (*nome_ponteiro)(tipo_parâmetros_recebidos);
	 * @par @warning
	 * Em funções que recebam parâmetros do tipo ordenar (que seria uma função de 
	 * ordenação), é possível passar NULL caso não deseje ordenar nada.
	 */
	typedef void (*ordenar)(individuo*, size_t);

	void listar(void* lista, size_t tamanho,ordenar ordenacao,
		    uint8_t eh_doscente, uint8_t tipo);

	void listar_individuos(individuo* lista, size_t tamanho, ordenar ordenacao, uint8_t eh_doscente);

	void listar_disciplinas(disciplina* lista, size_t tamanho);

	void ord_data(individuo* buff_l, size_t tam);
#endif
