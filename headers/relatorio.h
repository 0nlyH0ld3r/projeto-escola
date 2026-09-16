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
	typedef size_t (*ordenar_i)(individuo*, size_t);
	typedef size_t (*ordenar_d)(disciplina*, size_t);

	# if ESTOU_COGITANDO_REMOVER_PARA_REDUZIR_A_COMPLEXIDADE
	void listar(void* lista, size_t tamanho,ordenar ordenacao,
		    uint8_t eh_doscente, uint8_t tipo);
	#endif

	void listar_individuos(individuo* lista, ordenar_i ordenacao, cargo cargo);

	void listar_disciplinas(disciplina* lista, ordenar_d ord);

	void output_individuo(individuo pessoa, int opcao);

	void output_disciplina(disciplina disciplina, int opcao);

	size_t ord_data(individuo* buff_l, size_t tam);

	size_t ord_nome(individuo* buff_l, size_t tam);

	size_t ord_tres_disciplinas(individuo* buff_, size_t taml);

	size_t aniversariantes(individuo* buff_l, size_t tam);
#endif
