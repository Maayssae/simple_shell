#include "shell.h"
#define MAX_COMMAND_LENGTH 100

/**
 * displayPrompt - displaysPrompt for user entry
 * @void: no parameter
 */

void displayPrompt(void)
{
	printf("simple_shell$ ");
}

/**
 * readUserInput - reads user input
 * @command: command read from user input
 */

void readUserInput(char *command)
{
	/* Read user input */
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
	{
		/* Exit the program on end of file (Ctrl+D) */
		printf("\n");
		exit(EXIT_SUCCESS);
	}
	/* Remove newline character */
	command[strcspn(command, "\n")] = '\0';
}

/**
 * executeCommand - executes command from user
 * @command: command to be executed
 */

void executeCommand(char *command)
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
		char *args[2];

		args[0] = command;
		args[1] = NULL;
		/* Execute the command in the child process */
		execv(command, args);
		/* If execv fails */
		perror("execv");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		int status;

		/* Wait for the child process to complete */
		waitpid(pid, &status, 0);

		/* Check if the child process terminated successfully */
		if (WIFEXITED(status))
		{
			/* Print exit status */
			printf("Exit status: %d\n", WEXITSTATUS(status));
		}
		else
		{
			/* Print if the child process did not terminate normally */
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
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		displayPrompt();
		readUserInput(command);
		executeCommand(command);
	}
	return (EXIT_SUCCESS);
}
