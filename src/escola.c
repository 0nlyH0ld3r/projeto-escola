#include <stdio.h>
#include "../headers/constants.h"
#include "../headers/escola.h"
#include "../headers/relatorio.h"
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


void cadastro_individuo(individuo* lista, size_t tam) {
	size_t index = 0;
	procura_vaga(lista, tam, index);
	input_individuo(&lista[index]);
}
void cadastro_disciplina(disciplina* lista, individuo* lista_prof, size_t tam) {
	size_t index = 0;

	procura_vaga(lista, tam, index);
	input_disciplina(&lista[index], lista_prof);

}


void input_individuo(individuo* pessoa) {
	static int primeiros_digitos = 0;
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
	scanf_limpo("%d", &data);
	puts("\n");

	pessoa->estado			= ATIVO;
	pessoa->matricula		= (2026 * 10000) + primeiros_digitos;

	pessoa->data.ano		= data % 10000;
	pessoa->data.mes		= (data % 1000000) / 10000;
	pessoa->data.dia		= data / 1000000;

	pessoa->n_disciplinas	= 0;
	++primeiros_digitos;
}

void input_disciplina(disciplina* disciplina, individuo* lista_prof) {
	puts("Digite o nome da disciplina: ");
	input_string(disciplina->nome, MAX_CHAR_NOME);
	// pessoa->professor;
	puts("\nDigite o código da disciplina (ex: INF029): ");
	input_string(disciplina->codigo, MAX_CHAR_COD_DISCIPLINA);

	puts("\nAperte qualquer tecla para entrar no menu de seleção do professor: ");
	input_char_non_canon();

	disciplina->estado			= ATIVO;
	unsigned int matricula;

	listar_individuos(lista_prof, MAX_ALUNOS_ESCOLA, NULL, DOSCENTE);



	do { 
		puts("\nSelecione o professor pela matrícula: ");
		scanf_limpo("%u", &matricula);

		disciplina->professor = busca_matricula(lista_prof, 3, matricula);

		if (disciplina->professor != NULL) break;

		puts("\nDigite a matrícula válida de um professor!");

	} while(1);

	listar_disciplinas(disciplina, 1, NULL);
	puts("\n");
}


