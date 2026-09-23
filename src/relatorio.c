#include "../headers/relatorio.h"
#include "../headers/escola.h"
#include "../headers/utilidades.h"
#include "constants.h"

//
// Funções de listagem
//

static void print_header_individuo(cargo cargo);
static size_t procura_nome(individuo *buff, size_t tam, char *nome);

ordenar_i ordenar_pessoas[] = {NULL,
			       ord_data,
			       ord_nome,
			       ord_genero,
			       filtro_3_disciplinas,
			       filtro_aniversariante,
			       pesquisa_pessoa};

void listar_individuos(individuo *lista, ordenar_i ord, cargo cargo)
{
	size_t tam = MAX_PESSOAS_ESCOLA;
	individuo buff_lista[tam];
	memcpy(buff_lista, lista, sizeof(individuo) * tam);

	if (ord != NULL)
		tam = ord(buff_lista, tam);

	print_header_individuo(cargo);

	for (size_t i = 0; i < tam; ++i) {
		if (cargo == AMBOS) {
			output_individuo(buff_lista[i], true);
		}

		else if (cargo == DOSCENTE) {
			if (buff_lista[i].cargo == DOSCENTE) {
				output_individuo(buff_lista[i], true);
			}
		}

		else if (cargo == DISCENTE) {
			if (buff_lista[i].cargo == DISCENTE) {
				output_individuo(buff_lista[i], true);
			}
		}
	}
}

void listar_disciplinas(disciplina *lista, ordenar_d ord)
{
	size_t tam = MAX_DISCIPLINAS_ESCOLA;
	disciplina buff_l[tam];

	memcpy(buff_l, lista, sizeof(disciplina) * tam);

	if (ord != NULL)
		tam = ord(buff_l, tam);

	puts("************************\n");
	puts("**LISTA DE DISCIPLINAS**\n");
	puts("************************\n\n");

	for (size_t i = 0; i < tam; ++i) {
		if (buff_l[i].estado == NAO_ATIVO) {
			continue;
		}

		output_disciplina(buff_l[i], false);
	}
}

//
// Funções de ordenação
//

size_t ord_data(individuo *buff_l, size_t tam)
{
	for (size_t i = 1; i < tam; ++i) {
		individuo tmp = buff_l[i];
		size_t j = i;

		while (unir_data(tmp.data) < unir_data(buff_l[j - 1].data)) {
			buff_l[j] = buff_l[j - 1];
			--j;

			continue;
		}

		buff_l[j] = tmp;
	}

	return tam;
}

size_t pesquisa_pessoa(individuo *buff_l, size_t tam)
{
	char nome[MAX_CHAR_NOME] = {0};

	puts("\nDigite um nome para ser pesquisado na lista de alunos\n"
	     "O nome deve possuir pelo menos 3 letras.\n\nNOME: ");

	size_t len;
	do {
		fgets(nome, tam, stdin);
		len = strlen(nome);
	} while (len <= 4);

	return procura_nome(buff_l, tam, nome);
}

size_t pesquisa_disciplina(disciplina *buff_l, size_t tam);

size_t filtro_3_disciplinas(individuo *buff, size_t tam)
{
	size_t count = 0;
	for (size_t i = 1; i < tam; ++i) {
		individuo t = buff[i];
		size_t j = i;

		if (t.n_disciplinas < 3 && t.cargo == DISCENTE) {
			while (t.n_disciplinas < buff[j - 1].n_disciplinas &&
			       j > 0) {
				buff[j] = buff[j - 1];
				--j;

				continue;
			}

			++count;
		}

		buff[j] = t;
	}

	return count;
}

size_t ord_nome(individuo *buff_l, size_t tam)
{
	for (size_t i = 1; i < tam; ++i) {
		individuo tmp = buff_l[i];
		size_t j = i;

		while (ordem_alfabetica(tmp.nome, buff_l[j - 1].nome) == true &&
		       j > 0) {
			buff_l[j] = buff_l[j - 1];
			--j;

			continue;
		}

		buff_l[j] = tmp;
	}

	return tam;
}

size_t filtro_aniversariante(individuo *buff, size_t tam)
{
	size_t count = 0;
	time_t mytime = time(NULL);
	struct tm tm = *localtime(&mytime);
	unsigned long mes_atual = (unsigned long)tm.tm_mon;

	for (size_t i = 0; i < tam; ++i) {
		individuo t = buff[i];
		size_t j = i;

		if (t.data.mes == mes_atual) {
			while (t.data.mes != buff[j - 1].data.mes && j > 0) {
				buff[j] = buff[j - 1];
				--j;

				continue;
			}

			++count;
		}

		buff[j] = t;
	}

	return count;
}

size_t ord_genero(individuo *buff, size_t tam)
{
	for (size_t i = 0; i < tam; ++i) {
		individuo t = buff[i];
		size_t j = i;

		while (t.genero == FEM && buff[j - 1].genero == MASC && j > 0) {
			buff[j] = buff[j - 1];
			--j;

			continue;
		}

		buff[j] = t;
	}

	return tam;
}

//
// Funções de output
//

void output_individuo(individuo pessoa, int geral)
{
	if (pessoa.estado == NAO_ATIVO)
		return;

	if (pessoa.cargo == DOSCENTE)
		printf("Professor: %s\n", pessoa.nome);
	else
		printf("Aluno: %s\n", pessoa.nome);

	if (geral == true) {
		printf("CPF: %s\n", pessoa.cpf);
		printf("Data de Nascimento: %2d/%2d/%4d\n", pessoa.data.dia,
		       pessoa.data.mes, pessoa.data.ano);
		printf("Gênero: %s\n",
		       pessoa.genero == MASC ? "Masculino" : "Feminino");
		printf("Número de disciplinas: %d\n\n\n", pessoa.n_disciplinas);
	}

	printf("Matricula: %d\n\n", pessoa.matricula);
}

void output_disciplina(disciplina disciplina, int alunos)
{
	if (disciplina.estado == NAO_ATIVO)
		return;

	printf("Disciplina: %s\n", disciplina.nome);
	printf("Código: %s\n", disciplina.codigo);
	printf("Semestre: %u\n", disciplina.semestre);

	printf("Doscente responsável: %s\n\n\n", disciplina.professor->nome);

	if (alunos == true) {
		for (size_t i = 0; i < MAX_NUMERO_ALUNOS_DISCIPLINA; ++i)
			output_individuo(*disciplina.alunos[i], false);
	} else {
		puts("\n\n");
	}
}

//
// FUNÇÕES LOCAIS
//

static size_t procura_nome(individuo *buff, size_t tam, char *nome)
{
	size_t count = 0;
	for (size_t i = 1; i < tam; ++i) {
		individuo t = buff[i];
		size_t j = i;

		if (compara_strings(nome, t.nome)) {
			while (!(compara_strings(nome, buff[j - 1].nome))) {
				buff[j] = buff[j - 1];
				--j;

				continue;
			}

			++count;
		}

		buff[j] = t;
	}

	return count;
}

static void print_header_individuo(cargo cargo)
{

	switch (cargo) {
	case DOSCENTE:
		puts("************************\n");
		puts("**LISTA DE PROFESSORES**\n");
		puts("************************\n\n");
		break;

	case DISCENTE:
		puts("***********************\n");
		puts("****LISTA DE ALUNOS****\n");
		puts("***********************\n\n");
		break;

	case AMBOS:
		puts("**********************\n");
		puts("***LISTA DE PESSOAS***\n");
		puts("**********************\n\n");
		break;
	default:
		break;
	}
}
