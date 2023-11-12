#include "shell.h"
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

/**
 * displayPrompt - displaysPrompt for user entry
 * @void: no parameter
 */

void displayPrompt(void)
{
	/* Display prompt */
	printf("simple_shell$ ");
}

/**
 * readUserInput - reads user input
 * @input: input from user
 */

void readUserInput(char *input)
{
	/* Read user input */
	if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
		/* Exit the program on end of file (Ctrl+D) */
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	/* Remove newline character */
	input[strcspn(input, "\n")] = '\0';
}

/**
 * parseInput - executes command from user
 * @command: command to be executed
 * @input: string input
 * @arguments: arguments passed
 */

void parseInput(char *input, char *command, char *arguments[])
{
	/* Parse input into command and arguments */
	char *token = strtok(input, " ");
	int argIndex;

	if (token != NULL)
	{
		strcpy(command, token);
		argIndex = 0;

		while ((token = strtok(NULL, " ")) != NULL && argIndex < MAX_ARGUMENTS - 1)
		{
			arguments[argIndex++] = token;
		}

		arguments[argIndex] = NULL; /*Set the last argument to NULL for execv*/
	}
	else
	{
		/* No command provided */
		command[0] = '\0';
		arguments[0] = NULL;
	}
}

/**
 * executeCommand - executes command from user
 * @command: command passed
 * @arguments: arguments passed
 */

void executeCommand(char *command, char *arguments[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		/* Child process */
		execv(command, arguments);
		/* If execv fails */
		perror("execv");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		int status;

		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			/* Print exit status */
			printf("Exit status: %d\n", WEXITSTATUS(status));
		}
		else
		{			/* Print if the child process did not terminate normally */
			printf("Child process did not terminate normally\n");
		}
	}
}

/**
 * main - main function
 * Return: EXIT_SUCCESS
 */

int main(void)
{
	char input[MAX_COMMAND_LENGTH];
	char command[MAX_COMMAND_LENGTH];
	char *arguments[MAX_ARGUMENTS];

	while (1)
	{
		displayPrompt();
		readUserInput(input);

		/* Parse input into command and arguments */
		parseInput(input, command, arguments);
		/* Execute the command with arguments */
		executeCommand(command, arguments);
	}
	return (EXIT_SUCCESS);
}
