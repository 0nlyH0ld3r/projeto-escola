#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "../headers/utilidades.h"
#include "../headers/relatorio.h"
#include "../headers/escola.h"
#include "../headers/constants.h"

#define TAM_LISTA_ALUNOS 5
#define TAM_LISTA_DISCIPLINAS 3

void menuCadastro(void){
	printf("MENU CADASTRO");
}

void menuRelatorio(){
	printf("MENU RELATÓRIO");
}

void menuv2(escola* escola, int debug){
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if(debug) printf("ENTROU MENU.\n\n");
	//system("clear");
	individuo lista_individuos[TAM_LISTA_ALUNOS];
	disciplina lista_disciplinas[TAM_LISTA_DISCIPLINAS];

	int sair = 0;
	int opcao;
    for(int i =0; i<60;i++) printf("*");
    printf("\n");
    printf("Digite a opção: \n\n");
    printf("\t0 - Sair \n");
    printf("\t1 - Inserir \n");
    printf("\t2 - Listar \n");
    printf("\t3 - Atualizar \n");
    printf("\t4 - Deletar \n\n");
    for(int i =0; i<60;i++) printf("*");
    printf("\n");

    scanf_limpo_simples("%d", &opcao);
    int total_lines_printed = 10;
	while(!sair){ //sair == 0
        if (total_lines_printed >= w.ws_row-1) {
        printf("\033[A\33[2K");
        printf("\033[A\33[2K");
        printf("\033[A\33[2K");
        
        total_lines_printed = 10;
        }
		switch (opcao){
		case SAIR:
			sair = 1;
			break;
		

		case CADASTRO: // Cadastrar
			menuCadastro();
            opcao = -1;
			break;

		case RELATORIO: // Listar
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
			menuRelatorio();
            opcao = -1;
			break;

        case -1:
            scanf_limpo_simples("%d", &opcao);
            break;

		default: 
            printf("\033[A\33[2K");
			puts("Opção Inválida");
            total_lines_printed++;
            opcao = -1;
		}
	}
}
