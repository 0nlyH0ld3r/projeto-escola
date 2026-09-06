#include <stdio.h>
#include "../headers/constants.h"
#include "../headers/escola.h"
#include "../headers/utilidades.h"

void cadastrar(void* lista, int index, uint8_t tipo) {
	if (index / 10000000) {
		index %= 1000;
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
	lista[index].estado	= ATIVO;

	lista[index].matricula	= (2026 * 10000) + index;

	puts("É doscente? (S - Sim | N - Sim)\n");

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

	puts("Digite seu nome: ");
	input_string(lista[index].nome, 40);
	puts("\n\n");

	puts("Digite seu CPF: ");
	scanf_limpo_simples("%d", &lista[index].cpf);
	puts("\n");

	puts("Digite seu gênero (M - masculino | F - feminino) ");
	lista[index].genero = input_char_non_canon();

	puts("Digite sua data de nascimento (DDMMAAAA): ");
	int data;
	scanf_limpo_simples("%d", &data);
	lista[index].nascimento.ano = data % 10000;
	lista[index].nascimento.mes = data % 1000000 / 10000;
	lista[index].nascimento.dia = data / 1000000;
	puts("\n");

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

