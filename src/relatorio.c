#include <stdio.h>
#include <string.h>
#include "../headers/escola.h"
#include "../headers/relatorio.h"

static int compara_datas(data data1, data data2);
static void output_individuo(individuo buff_i);

void listar(void* lista, size_t tamanho, ordenar ordenacao,
	    uint8_t eh_doscente, uint8_t tipo) {

	switch (tipo) {
	case INDIVIDUO:
		listar_individuos((individuo*)lista, tamanho, ordenacao, eh_doscente);
		break;
	case DISCIPLINA:
		listar_disciplinas((disciplina*)lista, tamanho);
		break;
	}
}

void listar_individuos(individuo* lista, size_t tam, ordenar ord, uint8_t eh_dos) {
	individuo buff_lista[tam]; // Buffer para o sort da função ordenacao

	memcpy(buff_lista, lista, sizeof(individuo) * tam);	// Copia os dados de lista em buff_lista

	if (ord != NULL) ord(buff_lista, tam);	// Passar NULL caso não deseje ordenar

	switch (eh_dos) {
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

	for (int i = 0; i < tam; ++i) {
		if (eh_dos == AMBOS){ 
			output_individuo(buff_lista[i]); 
		}

		else if (eh_dos == DOSCENTE) {
			if (buff_lista[i].eh_doscente == true) { output_individuo(buff_lista[i]); }
			printf("Eu estive aqui!\n");
		}

		else if (eh_dos == DISCENTE) {  
			if (buff_lista[i].eh_doscente == false) { output_individuo(buff_lista[i]); }
		}
	}
}


void listar_disciplinas(disciplina* lista, size_t tam) {
	puts("************************\n");
	puts("**LISTA DE DISCIPLINAS**\n");
	puts("************************\n\n");
	for (int i = 0; i < tam; ++i) {
		if (lista[i].estado == NAO_ATIVO) continue;

		printf("Disciplina: %s\n", lista[i].nome);
		printf("Código: %s\n", lista[i].codigo);
		printf("Doscente responsável: %s\n\n\n", lista[i].professor->nome);
	}
}


int rev_data (data tmp) {
	int data = 0;
	data += tmp.dia * 1;
	data += tmp.mes * 10000;
	data += tmp.ano * 1000000;

	return data;
}

void ord_data(individuo* buff_l, size_t tam) {
	for (int i = 1; i < tam; ++i) {
		individuo tmp = buff_l[i];
		int j = i;

		while (rev_data(tmp.data) < rev_data(buff_l[j-1].data)) {
			buff_l[j] = buff_l[j - 1];

			--j;

			continue;
		}

		buff_l[j] = tmp;

	}
}

static int compara_datas(data d1, data d2) {
	if (d1.dia < d2.dia) {
		return true;
	}

	if (d1.mes < d2.mes) {
		return true;
	}

	if (d1.ano < d2.ano) {
		return true;
	}

	return false;
}

void output_individuo(individuo buff_i) {
	if (buff_i.estado == NAO_ATIVO) return;
	if (buff_i.eh_doscente == true)	printf("Professor: %s\n", buff_i.nome);
	else				printf("Aluno: %s\n", buff_i.nome);

	printf("CPF: %s\n", buff_i.cpf);
	printf("Data de Nascimento: %2d/%2d/%4d\n", 
			buff_i.data.dia,
			buff_i.data.mes,
			buff_i.data.ano);

	printf("Gênero: %s\n", buff_i.genero == 'M' ? "Masculino" : "Feminino");

	printf("Matricula: %d\n", buff_i.matricula);

	printf("Número de disciplinas: %d\n\n\n", buff_i.n_disciplinas);

}

static void output_disciplina(disciplina buff_d) {
	printf("Disciplina: %s\n", buff_d.nome);

	printf("Código: %s\n", buff_d.codigo);
	printf("Doscente responsável: %s\n\n\n", buff_d.professor->nome);
}
