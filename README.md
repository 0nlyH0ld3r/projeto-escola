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
    menu -> ┌──────────────────────┐
     │      │  Utilidades:         │  
     │      │                      │
     │      │ v VLD. DATA          │       
     │      │ x VLD. CPF           │       
     │      │ x VLD. NOME          │       
     │      │ v GERA MATRICULA     │
     │      │ v PROCURA VAGA       │
     │      │                      │
     │      │ x PROCURA ARQ. SALVO │
     │      │ x SALVA ARQ(JSON).   │
     │      │                      │       
     │      └──────────────────────┘
     │
     ├──────────────► escola -> utilidades            ┌──────────────────────┐
     │                 │                              │ v ALTERA INDV.       │
     │                 │                              │ v ADC INDV.          │
     │                 │                              │ v DEL INDV.          │
     │                 │                              │ v ATZ INDV.          │
     │                 │                              │                      │
     │                 │                              │ v ALTERA DISC.       │
     │                 │                              │ v ADC DISC.          │
     │                 │                              │ v DEL DISC.          │
     │                 │                              │ v ATZ DISC.          │
     │                 │                              │ * INSCRV. ALUNO      │
     │                 │                              └──────────────────────┘
     │                 ├── Cadastro Indv.(Matric;Nome;Sexo;Data;CPF;Cargo)
     │                 ├── Cadastro Disc. (Nome;Cod.;Semestre;Prof.)       
     │                 │   ├── Cadastrar alunos na Disc.
     │                 │
     │◄────────────────┘ retorna ao menu 
     │
     ├──────────────► relatorios -> utilidades        ┌──────────────────────┐
     │                 │                              │ v LS INDV.           │
     │                 │                              │ v LS ALUN.           │
     │                 │                              │ v LS PROF.           │
     │                 │                              └──────────────────────┘
     │                 ├── v Lista Indv.(Aln ou Prof.)
     │                 ├── * Lista Indv. por sexo(Aln ou Prof.)
     │                 ├── v* Lista Indv. por nome(Aln ou Prof.)
     │                 ├── v Lista Indv. por data(Aln ou Prof.)
     │                 ├── v* Lista Indv. por string
     │                 ├── v Lista Indv. ALUNOS matriculados em menos de 3 disciplinas
     │                 ├── v Lista Indv. Aniversariantes do mês
     │                 ├── v Lista Disciplinas.
     │                 ├── * Lista Disciplinas - Dados de uma disciplina específica.
     │                 ├── * Lista Disciplinas (com nome do professor) que extrapolam 40 vagas.
     │                 │
     │◄────────────────┘ retorna ao menu 
     │
     ▼
     └──────────────► sair
                       │
                       *
                      main
                       │
                       ▼
                      fim
    
## Alunos
 - Bruno Vinicius
 - Igor Lisboa Ramos
