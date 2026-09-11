#include "../headers/menu_v2.h"
#include "../headers/constants.h"
#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define DEBUG 1
#define PRODUCTION 0

/// @brief Cria o objeto escola e chama menu
/// @param teste = define se é DEBUG ou não 
void inicia_escola(int teste){
    if(teste){
        printf("MODO DE DEPURAÇÃO. \n");
        printf("version: V2. \n");
    }

    escola escolaAtual;

    menuv2(&escolaAtual, teste);

    return;
}

/// @brief main
/// @param  void
/// @return void
int main(int argc, char** argv){
    if (argc < 2) {
        fprintf(stderr, ANSI_COLOR_RED "ERRO: SELECIONE DEBUG(-d) OU PRODUÇÃO(-p)." ANSI_COLOR_RED "\n"); 
        return 1;
    }

    if(argv[1][1] == 'd'){
        inicia_escola(DEBUG);
        return 0;
    }

    else if(argv[1][1] == 'p'){
        inicia_escola(PRODUCTION);
        return 0;
    }


}

