#include <stdio.h>
#include "../headers/constants.h"
#include "../headers/escola.h"
#include "../headers/utilidades.h"

#if DIVIDIR_EM_DUAS_FUNÇÕES
void cadastrar(void* lista, int index, uint8_t tipo) {
	if (index / ANO_ATUAL) index %= ANO_ATUAL;

	if (index == LISTA_CHEIA) {
		printf("A lista está cheia!\n");
		return;
	};

	if (tipo == INDIVIDUO) {
		individuo* buff_l = (individuo*)lista;
		input_individuo(&buff_l[index], index);
	}
	if (tipo == DISCIPLINA) {
		// disciplina* buff_l = (disciplina*)lista;
		// input_disciplina((disciplina*)lista, index);
	}

}
#endif
void input_individuo(individuo* pessoa, int index) {
	puts("Digite seu nome: ");
	input_string(pessoa->nome, 40);

	puts("\n\nDigite seu CPF (111.111.111-11): ");
	input_string(pessoa->cpf, MAX_CHAR_CPF);

	puts("\nÉ doscente? (S - Sim | N - Sim): ");
	switch (input_char_non_canon()) {
	case 'S':
	case 's':
		pessoa->cargo = DOSCENTE;
		break;

	case 'N':
	case 'n':
		pessoa->cargo = DISCENTE;
		break;
	}

	puts("\nDigite seu gênero (M - masculino | F - feminino) ");
	switch (input_char_non_canon()) {
	case 'M':
	case 'm':
		pessoa->genero = 'M';
		break;

	case 'F':
	case 'f':
		pessoa->genero = 'F';
		break;
	}

	puts("\nDigite sua data de data (DDMMAAAA): ");
	int data;
	scanf_limpo_simples("%d", &data);
	puts("\n");

	pessoa->estado			= ATIVO;
	pessoa->matricula		= (2026 * 10000) + index;

	pessoa->data.ano		= data % 10000;
	pessoa->data.mes		= (data % 1000000) / 10000;
	pessoa->data.dia		= data / 1000000;

	pessoa->n_disciplinas	= 0;
}

void inicializar_lista(void* lista, size_t tam, uint8_t tipo) {
	if (tipo == INDIVIDUO) {
		individuo* ptr_lista = (individuo*)lista;

		for (size_t i = 0; i < tam;) {
			ptr_lista[i].estado = NAO_ATIVO;
			++i;
		}


		return;
	}

	else if (tipo == DISCIPLINA) {

		disciplina* ptr_lista = (disciplina*)lista;

		for (size_t i = 0; i < tam; ++i)
			ptr_lista[i].estado = NAO_ATIVO;

		return;
	}
}

