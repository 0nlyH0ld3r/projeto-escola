#include "constants.h"
#include "escola.h"

#ifndef _RELATORIO
	#define _RELATORIO
	/* Abstração para chamar chamar funções de ordenação como parâmetros de outras 
	 * funções (no caso as de ordenação). 
	 * @par
	 * Cria um typedef que é um size_t* ptr  com parâmetros (individuo*, size_t),
	 * tal qual as funções de ordenação que serão criadas agora.
	 * @par note
	 * void (*nome_ponteiro)(tipo_parâmetros_recebidos);
	 * @par @warning
	 * Em funções que recebam parâmetros do tipo ordenar (que seria uma função de 
	 * ordenação), é possível passar NULL caso não deseje ordenar nada.
	 */
	typedef size_t (*ordenar_i)(individuo*, size_t);
	typedef size_t (*ordenar_d)(disciplina*, size_t);

	/* Recebe uma lista de individuos (um buffer) e uma string nome, então retorna o número
	* de pessoas com esse nome. A ideia é ter uma função de busca que vai poder ser passada
	* pra função listar_invidiuos() como uma função de ordenação pra buscar o nome. Ela vai
	* ler um nome, passar o buffer criado dentro da função de lista pra procura_nome() e
	* então listar as pessoas.
	*/
	size_t procura_nome(individuo* buff_a, size_t tam, char* nome);

	/* Uma função normal de listar individuos. Recebe uma lista de individuos,
	* uma função de ordenação (Ou NULL se não usar) e um cargo (DOSCENTE, DISCENTE ou AMBOS)
	*/
	void listar_individuos(individuo* lista, ordenar_i ordenacao, cargo cargo);

	/* A mesma coisa que a função de listar individuos, mas pra disciplinas. Não recebe
	* nada como cargo ou essas coisas e só recebe funções de ordenação específicas.
	* Não deve ter nenhuma ou quase nenhuma pq a única que teria aparentemente seria
	* a função de listar disciplinas com 40 alunos, mas a nossa arquitetura não permite.
	*/
	void listar_disciplinas(disciplina* lista, ordenar_d ord);

	/* Função de utilidade pra listaegm, não tenta usar
	*/
	void output_individuo(individuo pessoa, int opcao);

	/* Função de utilidade pra listaegm, não tenta usar
	*/
	void output_disciplina(disciplina disciplina, int opcao);

	/* Ordenação por data pros indivídios
	*/
	size_t ord_data(individuo* buff_l, size_t tam);

	/* Ordenação por nome pros indivídios
	*/
	size_t ord_nome(individuo* buff_l, size_t tam);

	/* Ordenação para alunos com menos de três disciplinas pros indivídios
	*/
	size_t ord_tres_disciplinas(individuo* buff_, size_t taml);

	/* Ordenação para aniversariantes do mês pros indivídios
	*/
	size_t aniversariantes(individuo* buff_l, size_t tam);
#endif
