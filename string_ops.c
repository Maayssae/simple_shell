#include "shell.h"

/**
* **strtow - splits a string into words. Repeat delimiters are ignored
* @str: the input string to be split
* @d: the delimeter string. If NULL it defaults to a space character
* Return: pointer to an array of strings from input string, or NULL on failure
*/

char **strtow(char *str, char *d)
{
int i, j, k, m, numwords = 0;
char **string;

if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (i = 0; str[i] != '\0'; i++)
if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
numwords++;

if (numwords == 0)
return (NULL);
string = malloc((1 + numwords) *sizeof(char *));
if (!string)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (is_delim(str[i], d))
i++;
k = 0;
while (!is_delim(str[i + k], d) && str[i + k])
k++;
string[j] = malloc((k + 1) * sizeof(char));
if (!string[j])
{
for (k = 0; k < j; k++)
free(string[k]);
free(string);
return (NULL);
}
for (m = 0; m < k; m++)
sting[j][m] = str[i++];
string[j][m] = 0;
}
string[j] = NULL;
return (string);
}

/**
* **strtow2 - splits string into words
* @str: the input string
* @d: the delimeter
* Return: a pointer to an array of strings, or NULL on failure
*/
char **strtow2(char *str, char d)
{
int i, j, k, m, numwords = 0;
char **string;

if (str == NULL || str[0] == 0)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
if ((str[i] != d && str[i + 1] == d) ||
    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
numwords++;
if (numwords == 0)
return (NULL);
string = malloc((1 + numwords) *sizeof(char *));
if (!string)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (str[i] == d && str[i] != d)
i++;
k = 0;
while (str[i + k] != d && str[i + k] && str[i + k] != d)
k++;
string[j] = malloc((k + 1) * sizeof(char));
if (!string[j])
{
for (k = 0; k < j; k++)
free(string[k]);
free(string);
return (NULL);
}
for (m = 0; m < k; m++)
string[j][m] = str[i++];
string[j][m] = 0;
}
string[j] = NULL;
return (string);
}