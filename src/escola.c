#include "../headers/constants.h"
#include "../headers/escola.h"
#include "../headers/relatorio.h"
#include "../headers/utilidades.h"

void cadastro_individuo(individuo* lista, size_t tam) {
	size_t index = 0;
	procura_vaga(lista, tam, index);
	input_individuo(&lista[index], GERAL);
}

void cadastro_disciplina(disciplina* lista, individuo* lista_prof, size_t tam) {
	size_t index = 0;

	procura_vaga(lista, tam, index);
	input_disciplina(&lista[index], lista_prof, GERAL);
}

void remover_individuo(individuo* pessoa) {
	if (pessoa == NULL) {
		puts("\n\tPessoa não encontrada!\n");
		return;
	}

	pessoa->estado = NAO_ATIVO;
}

void remover_disciplina(disciplina* pessoa) {
	if (pessoa == NULL) {
		puts("\n\tDisciplina não encontrada!\n");
		return;
	}

	pessoa->estado = NAO_ATIVO;
}

void atualizar_individuo(individuo* pessoa, int opcao) {
	if (pessoa == NULL) {
		puts("\n\tPessoa não encontrada!\n");
		return; 
	}

	input_individuo(pessoa, opcao);
}

void atualizar_disciplina(disciplina* disciplina, int opcao) {
	if (disciplina == NULL) {
		puts("\n\tDisciplina não encontrada!\n");
		return; 
	}

	input_disciplina(disciplina, NULL, opcao);
}

void input_individuo(individuo* pessoa, int opcao) {
	if (pessoa == NULL) {
		puts("\n\tPessoa não encontrada!\n");
		return;
	}

	static int primeiros_digitos = 0;

	switch (opcao){
	case GERAL:
	case NOME:
		puts("Digite seu nome: ");
		input_string(pessoa->nome, 40);

		if (opcao != GERAL) return;

	case CPF:
		puts("\n\nDigite seu CPF (111.111.111-11): ");
		input_string(pessoa->cpf, MAX_CHAR_CPF);

		if (opcao != GERAL) return;

	case CARGO:
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

		if (opcao != GERAL) return;

	case GENERO:
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

		if (opcao != GERAL) return;

	case DATA:
		puts("\nDigite sua data de data (DDMMAAAA): ");
		int data;
		scanf_limpo("%d", &data);

		pessoa->data.ano	= data % 10000;
		pessoa->data.mes	= (data % 1000000) / 10000;
		pessoa->data.dia	= data / 1000000;

		if (opcao != GERAL) return;

	}

	if (pessoa->estado == NAO_ATIVO){
		pessoa->n_disciplinas	= 0;
		pessoa->matricula = (2026 * 10000) + primeiros_digitos;
		printf("\nSua matrícila é: %u\n", pessoa->matricula);
		++primeiros_digitos;
	}

	pessoa->estado = ATIVO;


}

void input_disciplina(disciplina* disciplina, individuo* lista_prof, int opcao) {
	if (disciplina == NULL) {
		puts("\n\tDisciplina não encontrada!\n");
		return;
	}

	switch (opcao) {
	case GERAL:
	case NOME:
		puts("Digite o nome da disciplina: ");
		input_string(disciplina->nome, MAX_CHAR_NOME);
		if (opcao != GERAL) break;

	case CODIGO:
		puts("\nDigite o código da disciplina (ex: INF029): ");
		input_string(disciplina->codigo, MAX_CHAR_COD_DISCIPLINA);
		if (opcao != GERAL) break;

	case PROFESSOR:
		puts("\nAperte qualquer tecla para entrar no menu de seleção do professor responsável: ");
		input_char_non_canon();

		disciplina->estado			= ATIVO;
		unsigned int matricula;

		listar_individuos(lista_prof, MAX_PESSOAS_ESCOLA, NULL, DOSCENTE);

		do { 
			puts("\nSelecione o professor pela matrícula: ");
			scanf_limpo("%u", &matricula);

			disciplina->professor = busca_matricula(lista_prof, MAX_PESSOAS_ESCOLA, matricula);

			if (disciplina->professor != NULL) break;

			puts("\nDigite a matrícula válida de um professor!");

		} while(1);

		listar_disciplinas(disciplina, 1, NULL);
		puts("\n");
		break;
	}
}


