#include "constants.h"

#ifndef _ESCOLA
#define _ESCOLA

	/* Cadastra individuos. Só recebe uma lista de individuos
	* e cadastrar o novo indivíduo lá.
	*/
	void cadastro_individuo(individuo* lista);

	/* Remover individuos. Só recebe uma lista de individuos, printa
	* uma lista de escolha e remove o individuo pelo código digitado.
	*/
	void remover_individuo(individuo* pessoa);

	/* Atualizar individuos. Só recebe uma lista de individuos
	* e atualiza individuo lá. Tem o parâmetro opcao que é uma enumm
	* dentro de constants.h pra saber o que quer atualizar.
	*/
	void atualizar_individuo(individuo* pessoa, int opcao);

	/* Função de utilidade pra cadastrar e atualizar individuos
	*/
	void input_individuo(individuo* lista, int opcao);

	/* Cadastrar disciplinas. Só recebe uma lista de discplinas
	* e cadastra a nova disciplina lá.
	*/
	void cadastro_disciplina(disciplina* lista, individuo* lista_prof);

	/* Remover disciplinas. Só recebe uma lista de discplinas, printa
	* uma lista de escolha e remove a disciplina pelo código digitado1.
	*/
	void remover_disciplina(disciplina* pessoa);

	/* Atualizar disciplinas. Só recebe uma lista de discplinas
	* e atualiza disciplina lá. Tem o parâmetro opcao que é uma enumm
	* dentro de constants.h pra saber o que quer atualizar.
	*/
	void atualizar_disciplina(disciplina* disciplina, int opcao);

/* Função de utilidade pra cadastrar e atualizar individuos.
* Depois checar que eu talvez remova essa, a contraparte de invidiuos dela 
* não tá aqui então acho que removi a contraparte pq não tava sendo necessária 
* em outro canto, mas esqueci dela. Primeiro preciso verificar.
*/
void input_disciplina(disciplina* lista, individuo* lista_prof, int opcao);
		/* Função de util
	#define inicializar_lista(lista, tam)		\
		for (size_t i = 0; i < tam; ++i){	\
			lista[i].estado = NAO_ATIVO; \
		}

#endif
