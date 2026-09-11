#include "../headers/menu_v2.h"
#include "../headers/constants.h"
#include <stdio.h>

#define DEBUG 1

/// @brief Cria o objeto escola e chama menu
/// @param teste = define se é DEBUG ou não 
void inicia_escola(int teste){
    if(teste)printf("MODO DE DEPURAÇÃO. \n");

    escola escolaAtual;

    menuv2(&escolaAtual, teste);

    return;
}

/// @brief main
/// @param  void
/// @return void
int main(int argc){
    if (argc > 1) {
    inicia_escola(DEBUG);
    return 0;        
    }
    inicia_escola(false);
    return 0;
}

