#ifndef _CONSTANTS
#define _CONSTANTS

#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>


	///MAXIMOS VALORES PARA TAMANHO DOS VETORES
	#define DIGITOS_CPF 					15
	#define MAX_ALUNOS_ESCOLA				5
	#define MAX_DISCIPLINAS_ESCOLA			2
	#define MAX_PROFESSORES_ESCOLA			2

	#define MAX_CHAR_NOME					40
	#define MAX_CHAR_COD_DISCIPLINA			6
	#define MAX_CHAR_CPF					14

	#define MAX_NUMERO_ALUNOS_DISCIPLINA	3
	#define MAX_DISCIPLINAS_INDIVIDUO		2

	// Definindo macros para true e false caso não estejam definidas
	// usando #ifndef (if not defined).
	enum MenuRelatorio{
		LISTA_ALUNO,
		LISTA_DISC,
		LISTA_PROF,
	};
	enum MenuAtualiza{
		ATUALIZA_INDV,
		ATUALIZA_DISC,
	};
	enum MenuCadastro{
		CADASTRO_INDV,
		CADASTRO_DISC,
		ATUALIZA,
	};
	enum MenuPrincipal{
		SAIR, 
		CADASTRO,
		RELATORIO,
	};
	typedef enum Status {
		TIPO_INVALIDO	= -2,
		LISTA_CHEIA	= -1,
		NAO_ATIVO	=  0,
		ATIVO		=  1,
	} status;

	typedef enum Cargo {
		DISCENTE	= 0,
		DOSCENTE	= 1,
		AMBOS		= 2,
	} cargo;

	typedef enum Genero{
		FEMININO = 0,
		MASCULINO = 1,
	} genero;



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
		char			nome[MAX_CHAR_NOME];			// Nota: Não tentem escrever nada por cima disso.
		disciplina*		disciplinas[MAX_DISCIPLINAS_INDIVIDUO];	// Lista de disciplinas do individuo.
		unsigned int	n_disciplinas;				// Número de disciplinas do individuo.
		unsigned int	matricula;				// Matrícula. Também usa pro professor.
		data			data;				// Data de data no padrão DDMMYY.
		char			cpf[DIGITOS_CPF];				// CPF do indivíduo.
		genero			genero;					// F | M  -> Feminino | Masculino.
		cargo			cargo;				// true -> Professor | false -> Aluno.
		unsigned int	estado;					// NAO_ATIVO <- Vaga livre pra uso
	};

	struct Disciplina {
		char		nome[MAX_CHAR_NOME];			// Nome da disciplina.
		char		codigo[MAX_CHAR_COD_DISCIPLINA];	// Código da disciplina. Ex: INF029
		individuo*	professor;				// Ponteiro para Professor responsável
		individuo*	alunos[MAX_NUMERO_ALUNOS_DISCIPLINA];	// Lista de alunos matriculados
		unsigned int	estado;					// NAO_ATIVO <- Vaga livre pra uso
	};
	

#endif
