#include "main.h"

/*
 * Sam you can add a 
 * comment here
 * return 0 - success
 */
int main(void)
{
	char *full_command = NULL,
	     *copy_command = NULL;
	char **argv;
	size_t f = 0;
	/*number of char user types*/
	ssize_t fchars_read; 
	const char *delim = " \n";
	int num_tokens = 0;
	char *token;
	int j;

	/*strcpy(command_copy , full_command)*/
	/*print a prompt for the user to type something*/
	printf("$ ");

	/*get string typed in the &  pass it to full_command*/
	fchars_read = getline(&full_command, &f, stdin);

	/*allocating space to store he char read by getline*/
	copy_command= malloc(sizeof(char) * fchars_read);

	if (copy_command == NULL)
	{
		perror("tsh: memory allocation has some errors");

		return (-1);
	}

	/*make a copy of the typed  command*/
	strcpy(copy_command, full_command);

	/*checking the getline function - failed or reached EOF*/
	if (fchars_read == -1)
	{
		printf("Quitting shell, deuces ✌️...\n");
		return (-1);
	}
	else {
		/*splitting string (full_command) into an array of words*/
		token = strtok(full_command, delim);

		/*allocating space - stores variable arg before we determ the tokens*/
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		/*prinf(">>> %d \n", num_tokens);*/

		/*malloc - allocating enough space for the pointer */
		argv = malloc(sizeof(char *) * num_tokens);

		token = strtok(copy_command, delim);

		for (j = 0; token != NULL; j++)
		{
			argv[j] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[j], token);

			/*printf(">> %s \n", argv[j]);*/
			token = strtok(NULL, delim);
		}
		argv[j] = NULL;

		/*exec the commands with execv*/

		free(argv);
		free(full_command);
		free(copy_command);
	}

	return (0);
}


