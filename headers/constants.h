#ifndef _CONSTANTS
#define _CONSTANTS

#include <unistd.h>
#include <stdint.h>

	// Definindo macros para true e false caso não estejam definidas
	// usando #ifndef (if not defined).

	#ifndef _bool 
	#define _bool
		#define true	1 
		#define false	0
	#endif

	enum Status {
		LISTA_CHEIA	= -1,
		TIPO_INVALIDO	= -2,
		NAO_ATIVO	=  0,
		ATIVO		=  1,
	};

	enum Cargo {
		DISCENTE	= 0,
		DOSCENTE	= 1,
		AMBOS		= 2,
	};

	enum Tipo {
		INDIVIDUO	= 1,
		DISCIPLINA	= 2,
	};

	///MAXIMOS VALORES PARA TAMANHO DOS VETORES
	enum valores_maximos {

		MAX_ALUNOS_ESCOLA		= 5,
		MAX_DISCIPLINAS_ESCOLA		= 2,
		MAX_PROFESSORES_ESCOLA		= 2,

		MAX_CHAR_NOME			= 40,
		MAX_CHAR_COD_DISCIPLINA		= 6,
		MAX_CHAR_CPF			= 14,

		MAX_NUMERO_ALUNOS_DISCIPLINA	= 3,
		MAX_DISCIPLINAS_INDIVIDUO	= 2,

	};

	enum Ano {
		ANO_ATUAL = 20260000,
	};

	/**
	*	nome
	*	disciplinas
	*	n_disciplinas;	
	*	matricula;	
	*	data;	
	*	cpf;		
	*	genero;		
	*	eh_doscente;	
	*	estado;		
	*/
	typedef struct Individuo individuo;

	/**
	*	nome
	*	codigo
	*	professor
	*	lista_alunos
	*	estado
	*/
	typedef struct Disciplina disciplina;

	/**
	 *	disciplinas
	 *	professores
	 *	alunos
	 */
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
		char		nome[MAX_CHAR_NOME];			// Nota: Não tentem escrever nada por cima disso.
		disciplina*	disciplinas[MAX_DISCIPLINAS_INDIVIDUO];	// Lista de disciplinas do individuo.
		unsigned int	n_disciplinas;				// Número de disciplinas do individuo.
		unsigned int	matricula;				// Matrícula. Também usa pro professor.
		data		data;				// Data de data no padrão DDMMYY.
		char		cpf[14];				// CPF do indivíduo.
		char		genero;					// F | M  -> Feminino | Masculino.
		unsigned int	eh_doscente;				// true -> Professor | false -> Aluno.
		unsigned int	estado;					// NAO_ATIVO <- Vaga livre pra uso
		
	};


	struct Disciplina {
		char		nome[MAX_CHAR_NOME];			// Nome da disciplina.
		char		codigo[MAX_CHAR_COD_DISCIPLINA];	// Código da disciplina. Ex: INF029
		individuo*	professor;				// Ponteiro para Professor responsável
		individuo*	alunos[MAX_NUMERO_ALUNOS_DISCIPLINA];	// Lista de alunos matriculados
		char		estado;					// NAO_ATIVO <- Vaga livre pra uso
	};
	

#endif
