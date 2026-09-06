#ifndef _CONSTANTS
#define _CONSTANTS

#include <unistd.h>
#include <stdint.h>

	// Definindo macros para true e false caso não estejam definidas
	// usando #ifndef (if not defined).

	#ifndef true 
	#define true		1 
	#endif

	#ifndef false
	#define false		0
	#endif

	enum Status {
		LISTA_CHEIA	=	-1,
		TIPO_INVALIDO	=	-2,
		NAO_ATIVO	=	 0,
		ATIVO		=	 1,
	};

	enum Tipo {
		INDIVIDUO	=	1,
		DISCIPLINA	=	2,
	};

	///MAXIMOS VALORES PARA TAMANHO DOS VETORES
	#define MAX_ALUNOS_ESCOLA		5
	#define MAX_DISCIPLINAS_ESCOLA		2
	#define MAX_PROFESSORES_ESCOLA		2
	#define MAX_NUMERO_ALUNOS_DISCIPLINA	3
	#define MAX_CARACTERE_NOME		40
	
	#define MAX_DISCIPLINAS_INDIVIDUO	2
	#define MAX_CHAR_COD_DISCIPLINA		6


	// Struct do invidivuo: pode ser tanto professor quanto aluno
	typedef struct Individuo individuo;

	// Struct das disciplinas
	typedef struct Disciplina disciplina;

	// Struct do objeto escola (Recebe possui lista de individuos e lista de disciplinas)
	typedef struct Escola escola;

	// Struct para data (Dia, mês, ano)
	typedef struct Data data;

	struct Data {
		unsigned int	dia;
		unsigned int	mes;
		unsigned int	ano;
	};

	struct Escola {
		disciplina*	disciplinas[MAX_DISCIPLINAS_ESCOLA];
		individuo*	professores[MAX_PROFESSORES_ESCOLA];
		individuo*	alunos[MAX_ALUNOS_ESCOLA];
	};

	struct Individuo {
		char		nome[MAX_CARACTERE_NOME];		// Nota: Não tentem escrever nada por cima disso.
		disciplina*	disciplinas[MAX_DISCIPLINAS_INDIVIDUO];	// Lista de disciplinas do individuo.
		unsigned int	n_disciplinas;				// Número de disciplinas do individuo.
		unsigned int	matricula;				// Matrícula. Também usa pro professor.
		data		nascimento;				// Data de nascimento no padrão DDMMYY.
		unsigned int	cpf;					// CPF do indivíduo.
		char		genero;					// F | M  -> Feminino | Masculino.
		char		eh_doscente;				// true -> Professor | false -> Aluno.
		char		estado;					// NAO_ATIVO <- Vaga livre pra uso
		
	};


	struct Disciplina {
		char		nome[MAX_CARACTERE_NOME];			// Nome da disciplina.
		char		codigo[MAX_CHAR_COD_DISCIPLINA];		// Código da disciplina. Ex: INF029
		individuo*	professor;					// Ponteiro para Professor responsável
		individuo*	lista_alunos[MAX_NUMERO_ALUNOS_DISCIPLINA];	// Lista de alunos matriculados
		char		estado;						// NAO_ATIVO <- Vaga livre pra uso
	};
	

#endif
