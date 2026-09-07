#include <stdio.h>
#include "../headers/constants.h"
#include "../headers/escola.h"
#include "../headers/utilidades.h"

void cadastrar(void* lista, int index, uint8_t tipo) {
	if (index / ANO_ATUAL) {
		index %= ANO_ATUAL;
	}
	switch (tipo) {
	case INDIVIDUO:
		input_individuo((individuo*)lista, index);
		break;
	case DISCIPLINA:
		//input_disciplina((disciplina*)lista, index);
		break;

	}

}

void input_individuo(individuo* lista, int index) {
	puts("Digite seu nome: ");
	input_string(lista[index].nome, 40);

	puts("\n\nDigite seu CPF (111.111.111-11): ");
	input_string(lista[index].cpf, MAX_CHAR_CPF);

	puts("\nÉ doscente? (S - Sim | N - Sim): ");
	switch (input_char_non_canon()) {
	case 'S':
	case 's':
		lista[index].eh_doscente = true;
		break;

	case 'N':
	case 'n':
		lista[index].eh_doscente = false;
		break;
	}

	puts("\nDigite seu gênero (M - masculino | F - feminino) ");
	lista[index].genero = input_char_non_canon();

	puts("\nDigite sua data de nascimento (DDMMAAAA): ");
	int data;
	scanf_limpo_simples("%d", &data);
	puts("\n");

	lista[index].estado	= ATIVO;
	lista[index].matricula	= (2026 * 10000) + index;

	lista[index].nascimento.ano = data % 10000;
	lista[index].nascimento.mes = data % 1000000 / 10000;
	lista[index].nascimento.dia = data / 1000000;

	lista[index].n_disciplinas = 0;
}

void inicializar_lista(void* lista, size_t tam, uint8_t tipo) {
	if (tipo == INDIVIDUO) {
		individuo* ptr_lista = (individuo*)lista;

		for (int i = 0; i < tam; ++i)
			ptr_lista[i].estado = NAO_ATIVO;

		return;
	}

	else if (tipo == DISCIPLINA) {

		disciplina* ptr_lista = (disciplina*)lista;

		for (int i = 0; i < tam; ++i)
			ptr_lista[i].estado = NAO_ATIVO;

		return;
	}
}

