#include "constants.h"
#include "escola.h"

#ifndef _RELATORIO
	#define _RELATORIO
	/* Abstração para chamar chamar funções de ordenação como parâmetros de outras 
	 * funções (no caso as de ordenação). Funções de filtragem também se encaixam.
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

	//
	// FUNÇÕES DE LISTAGEM
	//

	/* Uma função normal de listar individuos. Recebe uma lista de individuos,
	* uma função de ordenação (Ou NULL se não usar) e um cargo (DOSCENTE, DISCENTE ou AMBOS)
	*/
	void listar_individuos(individuo* lista, ordenar_i ordenacao, cargo cargo);

	/* A mesma coisa que a função de listar individuos, mas pra disciplinas. Não recebe
	* nada como cargo ou essas coisas e só recebe funções de ordenação específicas.
	* @par
	* A única função de ordenação pra disciplinas atualmente é a barra de pesquisa de
	* disciplina (pesquisa_disciplina)
	*/
	void listar_disciplinas(disciplina* lista, ordenar_d ord);

	//
	// FUNÇÕES DE ORDENAÇÃO
	//

	 /* A forma como ela funciona é recebendo uma lista de individuos,
	 * então ela pede input de uma string nome ao usuário e usa procura_nome() pra 
	 * isolar individuos cujo nome bate com a string e printar somente eles.
	 * @par
	 * Pra usar basta você colocar no parâmetro de listar_indidivuos() como a
	 * maioria das outras funções de ordenação.
	 */
	size_t pesquisa_pessoa(individuo *buff_l, size_t tam);

	/* Ordenação por data pros indivídios
	*/
	size_t ord_data(individuo* buff_l, size_t tam);

	/* Ordenação por nome pros indivídios
	*/
	size_t ord_nome(individuo* buff_l, size_t tam);

	/* Ordenação para alunos com menos de três disciplinas pros indivídios
	*/
	size_t filtro_3_disciplinas(individuo* buff_l, size_t taml);

	/* Ordenação para aniversariantes do mês pros indivídios
	*/
	size_t filtro_aniversariante(individuo* buff_l, size_t tam);

	/* A mesma coisa que a função barra_pesquisa_pessoas, mas pra disciplina. 
	void barra_pesquisa_disciplinas(disciplina *lista);
	*/
	size_t pesquisa_disciplina(disciplina *buff_l, size_t tam);

	/* Ordenação para gênero. Por enquanto (e talvez definitivamente), lista o gênero 
	 * feminino antes do masculino.
	 * Possível alteração para se tornar um filtro e não ordenação
	 */
	size_t ord_genero(individuo *buff, size_t tam);

	//
	// FUNÇÔES DE OUTPUT (Não precisa encostar nisso. Deixei no header pq outros 
	// arquivos usam. cogitando enviar eles para utilidades.h e .c, assim evito 
	// que outros arquivos importem relatorio.h somente por esses dois).
	//

	/* Função de utilidade pra listaegm, não tenta usar
	*/
	void output_individuo(individuo pessoa, int opcao);

	/* Função de utilidade pra listaegm, não tenta usar
	*/
	void output_disciplina(disciplina disciplina, int opcao);
#endif
