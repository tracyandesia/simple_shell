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
	ssize_t fchars_read;

	/*
	 * declaring void variables to avoid flags 
	 * while compiling
	 */
	(void)ac; (void)argv;

	/*
	 * now this part should 
	 * handle and infinite
	 * while loop
	 */
	while (1){
		printf("%s", prompt);
			fchars_read = getline(&lineptr, &f, stdin);
		/*check if the getline function breaks or has reached an End of Line (EOF) or if a user presses CTRL + D*/
		if (fchars_read == -1)
		{
			printf("Quiting shell...\n");
			return (-1);
		}

		printf("%s\f", lineptr);

		/*free up allocated memory*/
		free(lineptr);
	}

	return (0);
}
