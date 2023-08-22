#include "main.h"

/*
 * Sam you can add a 
 * comment here
 * return 0 - success
 */
int main(int ac, char **argv)
{
	char *prompt = "(SIMPLEShell) $ ";
	char *lineptr;
	size_t f = 0;

	/*
	 * declaring void variables to avoid flags 
	 * while compiling
	 */
	(void)ac; (void)argv;

	printf("%s", prompt);
	getline(&lineptr, &f, stdin);
	printf("%s\f", lineptr);

	free(lineptr);
	return (0);
}
