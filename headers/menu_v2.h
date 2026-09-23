#ifndef MENU
#define MENU

#include "../headers/constants.h"
#include "../headers/utilidades.h"
#include "../headers/relatorio.h"
#include "../headers/escola.h"

typedef struct {
    const char **opcoes;
    size_t tamanho;
    int pai;
} MENUS;


void menuCadastro(void);
void menuRelatorio(void);
void printaMenu(struct winsize *w, int linhaSelecionada, MENUS menuAtivo);
void printLimitesMenu(int secao, int totalColunas, int posMenu);
void apagaLinhaMenu(int linhasParaApagar);
void printSelecionado(const char *str,...);
void printContabilizado(const char *str,...);

/// @brief inicia o menu
/// @param escola o objeto escola
/// @param debug estado de depuração
/// @return void
void menuv2(escola* escola, int debug);

#endif