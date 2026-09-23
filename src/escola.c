#include "../headers/escola.h"
#include "../headers/constants.h"
#include "../headers/relatorio.h"
#include "../headers/utilidades.h"

void cadastro_individuo(individuo *pessoas)
{
	size_t tam = MAX_PESSOAS_ESCOLA;
	size_t index = 0;
	procura_vaga(pessoas, tam, index);
	input_individuo(&pessoas[index], NULL, GERAL);
}

void cadastro_disciplina(disciplina *lista, individuo *lista_prof)
{
	size_t tam = MAX_DISCIPLINAS_ESCOLA;
	size_t index = 0;

	procura_vaga(lista, tam, index);
	input_disciplina(&lista[index], lista_prof, GERAL);
}

void remover_individuo(individuo *lista)
{
	for (size_t i = 0; i < MAX_PESSOAS_ESCOLA; ++i)
		output_individuo(lista[i], false);

	printf("\nDigite a matrícula da pessoa a ser deletada: ");
	unsigned int matricula;
	scanf_limpo("%d", &matricula);
	individuo *pessoa =
		busca_matricula(lista, MAX_PESSOAS_ESCOLA, matricula);

	if (pessoa == NULL) {
		puts("\n\tPessoa não encontrada!\n");
		return;
	}

	pessoa->estado = NAO_ATIVO;
}

void remover_disciplina(disciplina *lista)
{
	for (size_t i = 0; i < MAX_DISCIPLINAS_ESCOLA; ++i) {
		output_disciplina(lista[i], false);
	}
	printf("\nDigite a matrícula da pessoa a ser deletada: ");
	char codigo[MAX_CHAR_COD_DISCIPLINA];
	fgets(codigo, MAX_CHAR_COD_DISCIPLINA, stdin);
	disciplina *disciplina =
		busca_codigo(lista, MAX_DISCIPLINAS_ESCOLA, codigo);

	if (disciplina == NULL) {
		puts("\n\tDisciplina não encontrada!\n");
		return;
	}

	disciplina->estado = NAO_ATIVO;
}

void atualizar_individuo(individuo *pessoa, disciplina *disciplinas, int opcao)
{
	if (pessoa == NULL) {
		puts("\n\tPessoa não encontrada!\n");
		return;
	}

	input_individuo(pessoa, disciplinas, opcao);
}

void atualizar_disciplina(disciplina *disciplina, int opcao)
{
	if (disciplina == NULL) {
		puts("\n\tDisciplina não encontrada!\n");
		return;
	}

	input_disciplina(disciplina, NULL, opcao);
}

void input_individuo(individuo *pessoa, disciplina *disciplinas, int opcao)
{
	if (pessoa == NULL) {
		puts("\n\tPessoa não encontrada!\n");
		return;
	}

	static int primeiros_digitos = 0;

	switch (opcao) {
	case GERAL:
	case NOME:
		puts("Digite seu nome: ");
		input_string(pessoa->nome, 40);

		if (opcao != GERAL)
			return;

	case CPF:
		puts("\n\nDigite seu CPF (111.111.111-11): ");
		input_string(pessoa->cpf, MAX_CHAR_CPF);

		if (opcao != GERAL)
			return;

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

		if (opcao != GERAL)
			return;

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

		if (opcao != GERAL)
			return;

	case DATA:
		puts("\nDigite sua data de data (DDMMAAAA): ");
		do {
			int data;
			scanf_limpo("%d", &data);

			pessoa->data.ano = data % 10000;
			pessoa->data.mes = (data % 1000000) / 10000;
			pessoa->data.dia = data / 1000000;

		} while (data_eh_valida(pessoa->data) == false);
		break;

	case DISCIPLINA:
		if (pessoa->n_disciplinas == MAX_DISCIPLINAS_INDIVIDUO) return;

		for (size_t i = 0; i < MAX_DISCIPLINAS_ESCOLA; ++i)
			output_disciplina(disciplinas[i], false);

		puts("\nDigite o código da disciplina em que deseja se "
		     "matricular: ");
		char codigo[10];
		fgets(codigo, 10, stdin);
		size_t index = pessoa->n_disciplinas;

		disciplina *disciplina = busca_codigo(
			disciplinas, MAX_DISCIPLINAS_ESCOLA, codigo);
		++pessoa->n_disciplinas;

		pessoa->disciplinas[index] = disciplina;
		procura_vaga(*disciplina->alunos, MAX_NUMERO_ALUNOS_DISCIPLINA, index);

		disciplina->alunos[index] = pessoa;
		break;
	}
	if (opcao != GERAL)
		return;

	if (pessoa->estado == NAO_ATIVO) {
		pessoa->n_disciplinas = 0;
		pessoa->matricula = (2026 * 10000) + primeiros_digitos;

		printf("\nSua matrícila é: %u\n", pessoa->matricula);

		++primeiros_digitos;
	}

	pessoa->estado = ATIVO;
}

void input_disciplina(disciplina *disciplina, individuo *lista_prof, int opcao)
{
	if (disciplina == NULL) {
		puts("\n\tDisciplina não encontrada!\n");
		return;
	}

	switch (opcao) {
	case GERAL:
	case NOME:
		puts("Digite o nome da disciplina: ");
		input_string(disciplina->nome, MAX_CHAR_NOME);
		if (opcao != GERAL)
			break;

	case CODIGO:
		puts("\nDigite o código da disciplina (ex: INF029): ");
		input_string(disciplina->codigo, MAX_CHAR_COD_DISCIPLINA);
		if (opcao != GERAL)
			break;

	case SEMESTRE:
		puts("\nDigite em qual semestre essa disciplina é "
		     "obrigatória: ");
		scanf_limpo("%u", &disciplina->semestre);

	case PROFESSOR:
		puts("\nAperte qualquer tecla para entrar no menu de seleção "
		     "do professor responsável: ");
		input_char_non_canon();

		disciplina->estado = ATIVO;
		unsigned int matricula;

		for (size_t i = 0; i < MAX_PESSOAS_ESCOLA; ++i)
			if (lista_prof[i].cargo == DOSCENTE)
				output_individuo(lista_prof[i], false);

		puts("\nSelecione o professor pela matrícula: ");
		do {
			scanf_limpo("%u", &matricula);

			disciplina->professor = busca_matricula(
				lista_prof, MAX_PESSOAS_ESCOLA, matricula);

			if (disciplina->professor != NULL &&
			    disciplina->professor->cargo == DOSCENTE)
				break;

			puts("\nDigite a matrícula válida de um professor!\n:");

		} while (1);

		output_disciplina(*disciplina, false);
		puts("\n");
		break;
	}
}
