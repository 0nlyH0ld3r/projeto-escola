#include "../headers/utilidades.h"
#include "../headers/constants.h"
#include "../headers/escola.h"
#include <stdio.h>
#include <string.h>
#include <termios.h>

void scanf_limpo(const char *format, void *variavel)
{
	if (compara_strings(format, "%d")) {
		scanf("%d", (int *)variavel);
	}

	else if (compara_strings(format, "%f")) {
		scanf("%f", (float *)variavel);
	}

	else if (compara_strings(format, "%u")) {
		scanf("%d", (unsigned int *)variavel);
	}

	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}

int data_eh_valida(data data)
{
	if (data.dia > 31)
		return 0;
	if (data.mes > 12)
		return 0;
	if (data.ano > 2026)
		return 0;
	if (data.dia > 28 && data.mes == 2 && !ano_eh_bissexto(data.ano))
		return 0;
	if (data.dia > 29 && data.mes == 2)
		return 0;
	if (data.dia > 31 && !mes_31_dias(data.mes))
		return 0;

	return 1;
}

int mes_31_dias(unsigned int mes)
{
	if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
		return 0;

	return 1;
}

int ano_eh_bissexto(unsigned int ano)
{
	if ((!(ano % 4) && (ano % 100)) || !(ano % 400))
		return 1;

	return 1;
}
/*
individuo *busca_matricula(individuo *lista, size_t tam, unsigned int matricula)
{
	individuo *ptr = lista;

	for (register size_t i = 0; i < tam; ++i) {
		if (lista->matricula == matricula) {
			return ptr;
		}

		++ptr;
	}

	return NULL;
}
	*/
individuo *busca_matricula(
    individuo *lista[],
    size_t tam,
    unsigned int matricula
)
{
    for (size_t i = 0; i < tam; ++i) {

        if (lista[i] != NULL &&
            lista[i]->matricula == matricula) {

            return lista[i];
        }
    }

    return NULL;
}

disciplina *busca_codigo(disciplina *lista[], size_t tam, char *codigo)
{
	disciplina *ptr = *lista;

	for (register size_t i = 0; i < tam; ++i) {
		if (lista[i] != NULL && compara_strings(lista[i]->codigo, codigo)) {
			return ptr;
		}

		++ptr;
	}

	return NULL;
}

void input_string(char *string, size_t tam)
{
	fgets(string, tam, stdin);
	string[strcspn(string, "\n")] = '\0';
}

int compara_strings(const char *string1, const char *string2)
{
	size_t len1 = strlen(string1) - 1;
	size_t len2 = strlen(string2) - 1;
	size_t len = len1 > len2 ? len2 : len1;
	return !strncmp(string1, string2, len);
}

int input_char_non_canon(void)
{
	struct termios old_t;
	tcgetattr(STDIN_FILENO, &old_t);
	struct termios new_t = old_t;
	new_t.c_lflag &= ~(ICANON);

	tcsetattr(STDIN_FILENO, TCSANOW, &new_t);

	int ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &old_t);

	return ch;
}
int ordem_alfabetica(const char *s1, const char *s2)
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    for (size_t i = 0; i < len1 && i < len2; ++i) {
        if (s1[i] < s2[i])
            return 1;

        if (s1[i] > s2[i])
            return 0;
    }

    return len1 < len2;
}

int unir_data(data tmp)
{
	int data = 0;

	data += tmp.dia * 1;
	data += tmp.mes * 10000;
	data += tmp.ano * 1000000;

	return data;
}
