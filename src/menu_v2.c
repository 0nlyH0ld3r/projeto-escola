#include "../headers/menu_v2.h"

#define TAM_LISTA_ALUNOS 5
#define TAM_LISTA_DISCIPLINAS 3
#define QNT_LINHAS_MENU 10
#define ESCAPE_INVERSE     "\033[7m"
#define RETURN_INVERSE     "\033[0m"

static int contaLinhasTotal = 0;

// void selecionaTexto(const char *str){
// 	if(selecionado )
// }

void menuCadastro(void){
	printf("MENU CADASTRO");
}

void menuRelatorio(void){
	printf("MENU RELATÓRIO");
}

void printaMenu(struct winsize *w){
	const char *opcoes[] = {
		"\t - Sair - \n",
		"\t - Cadastro - \n",
		"\t - Relatṕrios - \n",
	};

	int linhaSelecionada = 0;
	int totalColunas = w->ws_col;
	int posMenu = (totalColunas/2) - 15;
	for(int i =0; i<totalColunas;i++) printContabilizado("*");
    printContabilizado("\n");
	for(int i =0; i<posMenu;i++) printContabilizado(" ");
	printContabilizado("Digite a opção:\n");

	for(int i = 0; i< 3; i++){
		if(i == linhaSelecionada) printSelecionado(opcoes[i]);
		else printContabilizado(opcoes[i]);
	}
    for(int i =0; i<totalColunas;i++) printContabilizado("*");
    printContabilizado("\n");

}

void apagaLinhaMenu(int linhasParaApagar){
	for(int i = 0; i< linhasParaApagar; i++)printf("\033[A\33[2K");
}
void printContabilizado(const char *str, ...){
	for(int i =0; str[i] != '\0'; i++){
			if(str[i] == '\n') contaLinhasTotal++;
		}
	
		va_list args;
	va_start(args, str);
	vprintf(str, args);
	va_end(args);

	fflush(stdout);
}
void printSelecionado(const char *str,...){
	for(int i =0; str[i] != '\0'; i++){
			if(str[i] == '\n') contaLinhasTotal++;
		}
	
	//PRINTA COM V_ARGS
	va_list args;
	va_start(args, str);
	printf(ESCAPE_INVERSE);
	vprintf(str, args);
	printf(RETURN_INVERSE);
	va_end(args);

	fflush(stdout);
}

void menuv2(escola* escola, int debug){
	if(debug) printf("ENTROU MENU.\n\n"); else system("clear");

	individuo lista_individuos[TAM_LISTA_ALUNOS]; //fazer isso uma propriedade de escola dps
	disciplina lista_disciplinas[TAM_LISTA_DISCIPLINAS];

	int opcaoMenu;
	

	//PEGA TAMANHO DO TERMINAL
	struct winsize janela;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &janela);
	printaMenu(&janela);
	printf(" %d ",contaLinhasTotal);

    scanf_limpo("%d", &opcaoMenu);

    /*
	while(SAIR){ //sair == 0
        if (linhasMenu >= janela.ws_row) {
        linhasMenu = 10;
		apagaLinhaMenu(1);
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
	*/
}
