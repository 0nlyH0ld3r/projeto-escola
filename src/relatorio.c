#include <stdio.h>
#include <string.h>
#include "../headers/escola.h"
#include "../headers/relatorio.h"

void listar_individuos(individuo* lista, size_t tam, ordenar ordenacao) {
	individuo buff_lista[tam]; // Buffer para o sort da função ordenacao

	memcpy(buff_lista, lista, sizeof(individuo) * tam);	// Copia os dados de lista em buff_lista

	if (ordenacao != NULL) ordenacao(buff_lista, tam);	// Passar NULL caso não deseje ordenar

	for (int i = 0; i < tam; ++i) {
		if (buff_lista[i].estado == NAO_ATIVO) continue;

		if (buff_lista[i].eh_doscente == true)	printf("Professor: %s\n", buff_lista[i].nome);
		else					printf("Aluno: %s\n", buff_lista[i].nome);

		printf("CPF: %d\n", buff_lista[i].cpf);
		printf("Data de Nascimento: %d %d %d\n", 
				buff_lista[i].nascimento.dia,
				buff_lista[i].nascimento.mes,
				buff_lista[i].nascimento.ano);

		printf("Gênero: %s\n", buff_lista[i].genero == 'M' ? "Masculino" : "Feminino");

		printf("Matricula: %d\n", buff_lista[i].matricula);

		printf("Número de disciplinas: %d\n", buff_lista[i].n_disciplinas);

		puts("\n\n");
	}
}

void listar_disciplinas(disciplina* lista, size_t tam, ordenar ordenacao) {
	individuo buff_lista[tam];	// Buffer para o sort da função ordenacao
	memcpy(buff_lista, lista, tam); // Copia os dados de lista em buff_lista

	if (ordenacao != NULL) ordenacao(buff_lista, tam); // Passar NULL caso não deseje ordenar

	for (int i = 0; i < tam; ++i) {
		if (lista[i].estado == NAO_ATIVO) continue;

		printf("Nome da disciplina: %s\n", lista[i].nome);
		printf("Professor: %s",	lista[i].professor->nome);
		printf("Gênero: %s\n", lista[i].codigo);
		puts("\n\n");
	}
}

static int compara_datas(data data1, data data2) {
	if (data1.ano < data2.ano) {
		return true;
	}

	if (data1.mes < data2.mes) {
		return true;
	}

	if (data1.dia < data2.dia) {
		return true;
	}

	return false;
}

void ordenar_nascimento(individuo* buff_lista, size_t tam) {
	for (int i = 1; i < tam; ++i) {
		individuo tmp = buff_lista[i];
		int j = i;

		while (compara_datas(tmp.nascimento, buff_lista[j - 1].nascimento) == true) {
			tmp = buff_lista[i];
			buff_lista[j - 1] = buff_lista[j];

			--j;

			continue;
		}

		buff_lista[j] = tmp;

	}
}

