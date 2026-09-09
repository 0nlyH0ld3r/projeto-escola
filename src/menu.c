#include "../headers/constants.h"
#include "../headers/escola.h"
#include "../headers/relatorio.h"
#include "../headers/utilidades.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM_LISTA_ALUNOS 5
#define TAM_LISTA_DISCIPLINAS 3

void menu(escola *escola, int debug) {
	int sair = 0;
	int opcao;
	individuo lista_individuos[TAM_LISTA_ALUNOS];
	disciplina lista_disciplinas[TAM_LISTA_DISCIPLINAS];

	inicializar_lista(lista_individuos, TAM_LISTA_ALUNOS, INDIVIDUO);
	inicializar_lista(lista_disciplinas, TAM_LISTA_DISCIPLINAS, DISCIPLINA);
	system("clear");

	if (debug)
		printf("ENTROU MENU.\n\n");

	while (!sair) { // sair == 0
		for (int i = 0; i < 60; i++)
			printf("*");
		printf("\n");
		printf("Digite a opção: \n\n");
		printf("\t0 - Sair \n");
		printf("\t1 - Inserir \n");
		printf("\t2 - Listar \n");
		printf("\t3 - Atualizar \n");
		printf("\t4 - Deletar \n\n");
		for (int i = 0; i < 60; i++)
			printf("*");
		printf("\n");

		scanf_limpo_simples("%d", &opcao);

		switch (opcao) {
			case 0:
				sair = 1;
				break;

			case 1: // Cadastrar
				break;

			case 2: // Listar
				/*
				   switch (opcao) {
				   case 1:
				//listar_individuos(lista_individuos, TAM_LISTA_ALUNOS);
				break;
				case 2:
				//listar_disciplinas(lista_disciplinas, TAM_LISTA_DISCIPLINAS);
				break;
				}
				*/
				break;

			case 3: // Atualizar
				printf("Atualizar");
				break;

			case 4: // Deletar
				printf("Deletar");
				break;

			default:
				puts("Opção Inválida");
		}
	}
}
