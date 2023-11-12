#include "shell.h"
#define MAX_INPUT_LENGTH 100
#define MAX_ARGUMENTS 10

void displayPrompt(void);
void readUserInput(char *input);
void parseInput(char *input, char *cmd, char *args[]);
void executeCommand(char *cmd, char *args[]);
int main(void);

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
	if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
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
 * @cmd: command to be executed
 * @input: string input
 * @args: arguments passed
 */

void parseInput(char *input, char *cmd, char *args[])
{
	/* Parse input into command and arguments */
	char *token = strtok(input, " ");
	int argIndex;

	if (token != NULL)
	{
		strcpy(cmd, token);
		argIndex = 0;
		while ((token = strtok(NULL, " ")) != NULL && argIndex < MAX_ARGUMENTS - 1)
		{
			args[argIndex++] = token;
		}
		args[argIndex] = NULL; /*Set the last argument to NULL for execv*/
	}
	else
	{
		/* No command provided */
		cmd[0] = '\0';
		args[0] = NULL;
	}
}

/**
 * executeCommand - executes command from user
 * @cmd: command passed
 * @args: arguments passed
 */

void executeCommand(char *cmd, char *args[])
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
		/*Construct the full path to the command using PATH*/
		char *path = getenv("PATH");
		char *dir = strtok(path, ":");

		while (dir != NULL)
		{
			char full_path[MAX_INPUT_LENGTH];

			snprintf(full_path, sizeof(full_path), "%s/%s", dir, cmd);
			/*Try to execute the command*/
			execv(full_path, args);
			/* Move to the next directory in PATH*/
			dir = strtok(NULL, ":");
		}
		/* If execv fails, print an error message*/
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
	char input[MAX_INPUT_LENGTH];
	char cmd[MAX_INPUT_LENGTH];
	char *args[MAX_ARGUMENTS];

	while (1)
	{
		displayPrompt();
		readUserInput(input);
		/* Parse input into command and arguments */
		parseInput(input, cmd, args);

		if (cmd[0] != '\0')
		{
			/* Execute the command with arguments if a command is provided */
			executeCommand(cmd, args);
		}
	}
	return (EXIT_SUCCESS);
}

