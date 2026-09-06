# Projeto escola

## Estrutura atual da codebase
    .
    ├── explicando_funcoes.md
    ├── headers
    │   ├── constants.h
    │   ├── escola.h
    │   ├── menu.h
    │   ├── relatorio.h
    │   └── utilidades.h
    ├── Makefile
    ├── README.md
    └── src
        ├── escola.c
        ├── main.c
        ├── menu.c
        ├── relatorio.c
        └── utilidades.c

    3 directories, 13 files
    
## Arquitetura Proposta
### Estrutura proposta
    projetoEscola/
    │
    ├── Makefile
    │
    ├── src/
    │   ├──  main.c             -> importa constants.h inicia o programa; cria o objeto escola;chama o menu;termina;
    │   ├──  menu.c             -> seleciona a operação e termina;
    │   ├──  escola.c           -> implementa as operações solicitadas pelo menu
    │   ├──  relatorios.c       -> cria relatórios com os dados armazenados na escola
    │   └──  utilidades.c       -> funções pequenas e úteis como limpar buffer do scanf ou remover caractere do fgets
    ├── headers/
    │   ├──  constants.h        -> todas as structs, constantes e modelos ficam aqui; 
    │   ├──  menu.h
    │   ├──  escola.h
    │   ├──  relatorios.h
    │   └──  utilitarios.h
    └── build/
        └──  app
### Lógica Proposta   

    main
     │
     ▼
    menu -> utilidades
     │
     ├──────────────► escola -> utilidades
     │                    │
     │                    └──► retorna ao menu
     │
     ├──────────────► relatorios -> utilidades
     │                    │
     │                    └──► retorna ao menu
     │
     └──────────────► sair
                          │
                          ▼
                         main
                          │
                          ▼
                         fim
    
## Alunos
 - Bruno Vinicius
 - Igor Lisboa Ramos
 - João Abreu
 - Vitor Chagas
