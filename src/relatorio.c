#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../headers/escola.h"
#include "../headers/relatorio.h"

static void output_individuo(individuo buff_i);
static void output_disciplina(disciplina buff_d);

// 
// Funções de listagem
//

void listar_individuos(individuo* lista, size_t tam, ordenar_i ord, cargo cargo) {
	individuo buff_lista[tam]; // Buffer para o sort da função ordenacao

	memcpy(buff_lista, lista, sizeof(individuo) * tam);	// Copia os dados de lista em buff_lista

	if (ord != NULL) tam = ord(buff_lista, tam);	// Passar NULL caso não deseje ordenar

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
	}

	for (size_t i = 0; i < tam; ++i) {
		if (cargo == AMBOS){ 
			output_individuo(buff_lista[i]); 
		}

		else if (cargo == DOSCENTE) {
			if (buff_lista[i].cargo == DOSCENTE) { output_individuo(buff_lista[i]); }
		}

		else if (cargo == DISCENTE) {  
			if (buff_lista[i].cargo == DISCENTE) { output_individuo(buff_lista[i]); }
		}
	}
}

void listar_disciplinas(disciplina* lista, size_t tam, ordenar_d ord) {

	disciplina buff_l[tam];

	memcpy(buff_l, lista, sizeof(disciplina) * tam);

	if (ord != NULL) tam = ord(buff_l, tam);

	puts("************************\n");
	puts("**LISTA DE DISCIPLINAS**\n");
	puts("************************\n\n");
	for (size_t i = 0; i < tam; ++i) {
		if (buff_l[i].estado == NAO_ATIVO) continue;

		output_disciplina(buff_l[i]);
	}
}

//
// Funções utilidades
//



int inverter_data (data tmp) {
	int data = 0;

	data += tmp.dia * 1;
	data += tmp.mes * 10000;
	data += tmp.ano * 1000000;

	return data;
}

//
// Funções de ordenação
//

size_t ord_data(individuo* buff_l, size_t tam) {
	for (size_t i = 1; i < tam; ++i) {
		individuo tmp = buff_l[i];
		size_t j = i;

		while (inverter_data(tmp.data) < inverter_data(buff_l[j-1].data)) {
			buff_l[j] = buff_l[j - 1];
			--j;

			continue;
		}

		buff_l[j] = tmp;
	}

	return tam;
}

size_t ord_tres_disciplinas(individuo* buff_a, size_t tam) { // Ordenação exclusiva de alunos
	size_t count = 0;
	for (size_t i = 1; i < tam; ++i) {
		individuo tmp = buff_a[i];
		size_t j = i;

		if (tmp.n_disciplinas < 3 && tmp.cargo == DISCENTE) {
			while (tmp.n_disciplinas < buff_a[j-1].n_disciplinas && j > 0) {
				buff_a[j] = buff_a[j - 1];
				--j;

				continue;
			}

			++count;
		}

		buff_a[j] = tmp;
	}

	return count;
}

size_t aniversariantes(individuo* buff_l, size_t tam) {
	size_t count = 0;
	time_t mytime = time(NULL);
	struct tm tm = *localtime(&mytime);

	for (size_t i = 0; i < tam; ++i) {
		individuo tmp = buff_l[i];
		size_t j = i;
		if (tmp.data.mes == (unsigned long)tm.tm_mon) {
			while (tmp.data.mes != buff_l[j-1].data.mes && j > 0) {
				buff_l[j] = buff_l[j - 1];
				--j;

				continue;
			}

			++count;
		}

		buff_l[j] = tmp;
	}

	return count;
}

//
// Funções de output
//

static void output_individuo(individuo pessoa) {
	if (pessoa.estado == NAO_ATIVO) return;

	if (pessoa.cargo == DOSCENTE)	printf("Professor: %s\n", pessoa.nome);
	else				printf("Aluno: %s\n", pessoa.nome);

	printf("CPF: %s\n", pessoa.cpf);
	printf("Data de Nascimento: %2d/%2d/%4d\n", pessoa.data.dia,
			   	   pessoa.data.mes, pessoa.data.ano);

	printf("Gênero: %s\n", pessoa.genero == 'M' ? "Masculino" : "Feminino");
	printf("Matricula: %d\n", pessoa.matricula);
	printf("Número de disciplinas: %d\n\n\n", pessoa.n_disciplinas);

}

static void output_disciplina(disciplina disciplina) {
	if (disciplina.estado == NAO_ATIVO) return;

	printf("Disciplina: %s\n", disciplina.nome);
	printf("Código: %s\n", disciplina.codigo);
	printf("Doscente responsável: %s\n\n\n", disciplina.professor->nome);
}
