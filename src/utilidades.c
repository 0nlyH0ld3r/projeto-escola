#include "../headers/utilidades.h"
#include "../headers/constants.h"
#include "../headers/escola.h"
#include <stdio.h>
#include <string.h>
#include <termios.h>


void scanf_limpo(const char* format, void* variavel) {
	if (compara_strings(format, "%d")) {
		scanf("%d", (int*)variavel );
	}

	else if (compara_strings(format, "%f")) {
		scanf("%f", (float*)variavel );
	}

	int c;
	do { c = getchar(); } while (  c!= '\n' && c != EOF );
}

void input_string(char* string, size_t tam) {
	fgets(string, tam, stdin);
	string[strcspn(string, "\n")] = '\0';
}

int compara_strings(const char* string1, const char* string2) {
	return !strcmp(string1, string2);
}

int input_char_non_canon(void) {
	struct termios old_t;
	tcgetattr(STDIN_FILENO, &old_t);
	struct termios new_t = old_t;
	new_t.c_lflag &= ~(ICANON);

	tcsetattr(STDIN_FILENO, TCSANOW, &new_t );

	int ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &old_t );

	return ch;
}


