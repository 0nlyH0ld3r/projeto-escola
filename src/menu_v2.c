#include "../headers/menu_v2.h"

#include <termios.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define TAM_LISTA_ALUNOS 		5
#define TAM_LISTA_DISCIPLINAS 	3

#define ESCAPE_INVERSE     	"\033[7m"
#define RETURN_INVERSE     	"\033[0m"

#define ESCAPE_ARROW_UP    	'\33[A'
#define ESCAPE_ARROW_DOWN  	'\33[B'

#define ESCAPE_ITALICO		"\033[3m"
#define RETURN_ITALICO 		"\033[0m"

#define KEY_UP    1001
#define KEY_DOWN  1002
#define KEY_RIGHT 1003
#define KEY_LEFT  1004
#define KEY_ENTER 1005

static int contaLinhasTotal = 1;

const char *opcoes_relatorio[] = {
    "\t - Listar Alunos - \n",
    "\t - Listar Professores - \n",
    "\t - Listar Disciplinas - \n",
    "\t - Voltar - \n",
};

const char *opcoes_atualizar[] = {
    "\t - Atualizar Disciplina - \n",
    "\t - Atualizar Indivíduo - \n",
    "\t - Voltar - \n",
};

const char *opcoes_cadastro[] = {
    "\t - Cadastrar Disciplina - \n",
    "\t - Cadastrar Indivíduo - \n",
    "\t - Atualizar Cadastro - \n",
    "\t - Voltar - \n",
};

const char *opcoes_principal[] = {
    "\t - Sair - \n",
    "\t - Cadastro - \n",
    "\t - Relatórios - \n",
};
void printaAviso(){
	printContabilizado(ESCAPE_ITALICO);
	printContabilizado("Para controlar o menu utilize as setas do teclado ↑ ↓ e confirme com ENTER!\n");
	printContabilizado(RETURN_ITALICO);
}
void printLimitesMenu(int secao, int totalColunas, int posMenu)
{
    if (secao == INICIO) {
        for (int i = 0; i < totalColunas; i++)
            printContabilizado("*");

        printContabilizado("\n");

        for (int i = 0; i < posMenu; i++)
            printContabilizado(" ");

        printContabilizado("Digite a opção:\n");
    }

    if (secao == FINAL) {
        for (int i = 0; i < totalColunas; i++)
            printContabilizado("*");

        printContabilizado("\n");
    }
}

void printaMenu(
    struct winsize *w,
    int linhaSelecionada,
    MENUS menuAtivo
)
{
    MENUS menubase = {
        .opcoes = menuAtivo.opcoes,
        .tamanho = menuAtivo.tamanho,
        .pai = menuAtivo.pai
    };

    int totalColunas = w->ws_col;
    int posMenu = (totalColunas / 2) - 15;

    apagaLinhaMenu(contaLinhasTotal);

    printLimitesMenu(INICIO, totalColunas, posMenu);
	if(menubase.pai == -1){
		printaAviso();
	}
    for (int i = 0; i < (int)menubase.tamanho; i++) {
        if (i == linhaSelecionada)
            printSelecionado(menubase.opcoes[i]);
        else
            printContabilizado(menubase.opcoes[i]);
    }

    printLimitesMenu(FINAL, totalColunas, posMenu);
}

void apagaLinhaMenu(int linhasParaApagar)
{
    for (int i = 0; i < linhasParaApagar; i++)
        printf("\033[A\33[2K");

    fflush(stdout);

    contaLinhasTotal -= linhasParaApagar;
}

void printContabilizado(const char *str, ...)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            contaLinhasTotal++;
    }

    va_list args;

    va_start(args, str);
    vprintf(str, args);
    va_end(args);

    fflush(stdout);
}

void printSelecionado(const char *str, ...)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            contaLinhasTotal++;
    }

    va_list args;

    va_start(args, str);

    printf(ESCAPE_INVERSE);
    vprintf(str, args);
    printf(RETURN_INVERSE);

    va_end(args);

    fflush(stdout);
}

int pegaTeclaComando(void)
{
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    if (ch == '\n' || ch == '\r' || ch == 10) {
        ch = KEY_ENTER;
    }
    else if (ch == 27) {
        int next1 = getchar();
        int next2 = getchar();

        if (next1 == '[') {
            switch (next2) {
                case 'A':
                    ch = KEY_UP;
                    break;

                case 'B':
                    ch = KEY_DOWN;
                    break;

                case 'C':
                    ch = KEY_RIGHT;
                    break;

                case 'D':
                    ch = KEY_LEFT;
                    break;
            }
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

void menuv2(escola *escola, int debug)
{
    MENUS menuPrincipal = {
        .opcoes = opcoes_principal,
        .tamanho = sizeof(opcoes_principal) / sizeof(opcoes_principal[0]),
        .pai = -1
    };

    MENUS menuCadastro = {
        .opcoes = opcoes_cadastro,
        .tamanho = sizeof(opcoes_cadastro) / sizeof(opcoes_cadastro[0]),
        .pai = 0
    };

    MENUS menuAtualizar = {
        .opcoes = opcoes_atualizar,
        .tamanho = sizeof(opcoes_atualizar) / sizeof(opcoes_atualizar[0]),
        .pai = 1
    };

    MENUS menuRelatorio = {
        .opcoes = opcoes_relatorio,
        .tamanho = sizeof(opcoes_relatorio) / sizeof(opcoes_relatorio[0]),
        .pai = 0
    };

    MENUS listaMenus[] = {
        menuPrincipal,
        menuCadastro,
        menuAtualizar,
        menuRelatorio
    };

    int menuAtual = 0;
    int opcaoAtiva = 0;
    int tecla = 0;
    bool sair = false;

    MENUS menuAtivo = listaMenus[menuAtual];

    if (debug)
        printf("ENTROU MENU.\n\n");
    else
        system("clear");

    struct winsize janela;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &janela);

    while (!sair) {

        printaMenu(&janela, opcaoAtiva, menuAtivo);

        tecla = pegaTeclaComando();

        switch (tecla) {
        case KEY_UP:
            if (opcaoAtiva == 0)
                opcaoAtiva = (int)menuAtivo.tamanho - 1;
            else
                opcaoAtiva--;
            break;

        case KEY_DOWN:
            if (opcaoAtiva == (int)menuAtivo.tamanho - 1)
                opcaoAtiva = 0;
            else
                opcaoAtiva++;
            break;

        case KEY_ENTER:

            /*
             * MENU PRINCIPAL
             */
            if (menuAtual == 0) {

                if (opcaoAtiva == 0) {
                    // Sair
                    sair = true;
                }

                else if (opcaoAtiva == 1) {
                    // Principal -> Cadastro
                    menuAtual = 1;

                    menuAtivo = listaMenus[menuAtual];
                    opcaoAtiva = 0;
                }

                else if (opcaoAtiva == 2) {
                    // Principal -> Relatórios
                    menuAtual = 3;

                    menuAtivo = listaMenus[menuAtual];
                    opcaoAtiva = 0;
                }
            }

            /*
             * MENU CADASTRO
             */
            else if (menuAtual == 1) {

                if (opcaoAtiva == 0) {
                    /* cadastraDisciplina(escola); */
                }

                else if (opcaoAtiva == 1) {
                    /* cadastraIndividuo(escola); */
                }

                else if (opcaoAtiva == 2) {
                    // Cadastro -> Atualizar
                    menuAtual = 2;

                    menuAtivo = listaMenus[menuAtual];
                    opcaoAtiva = 0;
                }

                else if (opcaoAtiva == 3) {
                    // Cadastro -> Pai (Principal)
                    menuAtual = menuAtivo.pai;

                    menuAtivo = listaMenus[menuAtual];
                    opcaoAtiva = 0;
                }
            }

            /*
             * MENU ATUALIZAR
             */
            else if (menuAtual == 2) {

                if (opcaoAtiva == 0) {
                    /* atualizarDisciplina(escola); */
                }

                else if (opcaoAtiva == 1) {
                    /* atualizarIndividuo(escola); */
                }

                else if (opcaoAtiva == 2) {
                    // Atualizar -> Pai (Cadastro)
                    menuAtual = menuAtivo.pai;

                    menuAtivo = listaMenus[menuAtual];
                    opcaoAtiva = 0;
                }
            }

            /*
             * MENU RELATÓRIOS
             */
            else if (menuAtual == 3) {

                if (opcaoAtiva == 0) {
                    /* listarAlunos(escola); */
                }

                else if (opcaoAtiva == 1) {
                    /* listarProfessores(escola); */
                }

                else if (opcaoAtiva == 2) {
                    /* listarDisciplinas(escola); */
                }

                else if (opcaoAtiva == 3) {
                    // Relatórios -> Pai (Principal)
                    menuAtual = menuAtivo.pai;

                    menuAtivo = listaMenus[menuAtual];
                    opcaoAtiva = 0;
                }
            }

            break;

        default:
            break;
        }
    }

    system("clear");
}