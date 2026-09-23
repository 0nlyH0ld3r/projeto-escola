#include "../headers/menu_v2.h"
#include <termios.h>

#define TAM_LISTA_ALUNOS 5
#define TAM_LISTA_DISCIPLINAS 3
#define ESCAPE_INVERSE     "\033[7m"
#define RETURN_INVERSE     "\033[0m"
#define ESCAPE_ARROW_UP 	'\33[A'
#define ESCAPE_ARROW_DOWN 	'\33[B'

#define KEY_UP    1001
#define KEY_DOWN  1002
#define KEY_RIGHT 1003 //transformar em um enum dps
#define KEY_LEFT  1004
#define KEY_ENTER 1005

static int contaLinhasTotal = 1;


const char *opcoes_relatorio[] = {
		"\t - Listar Alunos - \n",
		"\t - Listar Professores - \n",
		"\t - Listar Disciplinas - \n",
};
const char *opcoes_atualizar[] = {
		"\t - Atualizar Disciplina - \n",
		"\t - Atualizar Indivíduo - \n",
};
const char *opcoes_cadastro[] = {
		"\t - Cadastrar Disciplina - \n",
		"\t - Cadastrar Indivíduo - \n",
		"\t - Atualizar Cadastro - \n",
};
const char *opcoes_principal[] = {
		"\t - Sair - \n",
		"\t - Cadastro - \n",
		"\t - Relatórios - \n",
};


void menuCadastro(void){
	printf("MENU CADASTRO");
}

void menuRelatorio(void){
	printf("MENU RELATÓRIO");
}

void printLimitesMenu(int secao, int totalColunas, int posMenu){
	if (secao == INICIO){
		for(int i =0; i<totalColunas;i++) printContabilizado("*");
    	printContabilizado("\n");
		for(int i =0; i<posMenu;i++) printContabilizado(" ");
		printContabilizado("Digite a opção:\n");
	}
	if (secao == FINAL){
		for(int i =0; i<totalColunas;i++) printContabilizado("*");
    	printContabilizado("\n");
	}
}

void printaMenu(struct winsize *w, int linhaSelecionada, MENUS menuAtivo){

	// const char *opcoes[] = {
	// 	"\t - Sair - \n",
	// 	"\t - Cadastro - \n",
	// 	"\t - Relatórios - \n",
	// };
	MENUS menubase = {
		.opcoes = menuAtivo.opcoes,
		.tamanho = menuAtivo.tamanho
	};
	int totalColunas = w->ws_col;
	int posMenu = (totalColunas/2) - 15;

	
	apagaLinhaMenu(contaLinhasTotal);
	printLimitesMenu(INICIO, totalColunas, posMenu);
	for(int i = 0; i< N_MENU_MAIN; i++){
		if(i == linhaSelecionada) printSelecionado(menubase.opcoes[i]);
		else printContabilizado(menubase.opcoes[i]);
	}
    
	printLimitesMenu(FINAL, totalColunas, posMenu);
}

void apagaLinhaMenu(int linhasParaApagar){
	for(int i = 0; i< linhasParaApagar; i++)printf("\033[A\33[2K");
	fflush(stdout);
	contaLinhasTotal -= linhasParaApagar;
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

int pegaTeclaComando(void){
    struct termios oldt, newt;
    int ch;

  
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();
	//ascii for esc is 27
	if (ch == '\n' || ch == '\r' || ch == 10){
		ch = KEY_ENTER;
		//printf("ENTER DETECTED");
	}
    else if (ch == 27) { 
        int next1 = getchar();
        int next2 = getchar();

        if (next1 == '[') {
            switch (next2) {
                case 'A': ch = KEY_UP; break;
                case 'B': ch = KEY_DOWN; break;
                case 'C': ch = KEY_RIGHT; break;
                case 'D': ch = KEY_LEFT; break;
            }
        }
    }

    // Restore original terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void menuv2(escola* escola, int debug){

	MENUS menuPrincipal = {
	.opcoes = opcoes_principal,
	.tamanho = sizeof(opcoes_principal)/sizeof(opcoes_principal[0]),
	};
	MENUS menuCadastro = {
		.opcoes = opcoes_cadastro,
		.tamanho = sizeof(opcoes_cadastro)/sizeof(opcoes_cadastro[0]),
	};
	MENUS menuAtualizar = {
		.opcoes = opcoes_atualizar,
		.tamanho = sizeof(opcoes_atualizar)/sizeof(opcoes_atualizar[0]),
	};
	MENUS menuRelatorio = {
		.opcoes = opcoes_relatorio,
		.tamanho = sizeof(opcoes_relatorio)/sizeof(opcoes_relatorio[0]),
	};


	MENUS listaMenus[] = {menuPrincipal,
						menuCadastro,
						menuAtualizar,
						menuRelatorio};
	
	bool sair = true;
	if(debug) printf("ENTROU MENU.\n\n"); else system("clear");

	//PEGA TAMANHO DO TERMINAL
	struct winsize janela;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &janela);

	int tecla				= 0,
		opcaoAtiva			= 0,
		i 					= 0;

		
	char opcaoEscape		= 0;
	MENUS menuAtivo = listaMenus[0];
	
	while(sair){
		printaMenu(&janela, opcaoAtiva, menuAtivo);
		tecla = pegaTeclaComando();
		switch (tecla)
		{
		case KEY_UP:
			if(opcaoAtiva == 0)opcaoAtiva = (int)menuAtivo.tamanho;
			opcaoAtiva--;
			break;
		
		case KEY_DOWN:
			if(opcaoAtiva == (int)menuAtivo.tamanho) opcaoAtiva = -1;
			opcaoAtiva++;
			break;
		case KEY_ENTER:
			i++;
			opcaoAtiva = 0;
		default:
			menuAtivo = listaMenus[i];
			
			break;
		}
	}

}
