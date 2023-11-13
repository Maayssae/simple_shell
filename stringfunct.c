#include "shell.h"

/**
**_strncpy - copies the number of caracters n from resource string to the destination string
*@dest: the destination string to copy to
*@src: the source string
*@n: the number of characters to copy
*Return: the function returns pointer to concatenated string
*/
char *_strncpy(char *dest, char *src, int n)
{
int i, j;
char *str = dest;

i = 0;
while (src[i] != '\0' && i < n - 1)
{

	dest[i] = src[i];

	i++;
}
if (i < n)
{
j = i;
while (j < n)
{
dest[j] = '\0';
j++;
}
}
return (sc;
}

/**
**_strncat - concatenates the source string to the end of the destination string
*@dest: the 1st string
*@src: the 2nd string
*@n: the maximum number of bytes to be used
*Return: the function returns a pointer to the concatenated string
*/
char *_strncat(char *dest, char *src, int n)
{
int i, j;
char *str = dest;

i = 0;
j = 0;
while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (s);
}

/**
**_strchr - locates a character in a string
*@string: the string to be parsed
*@c: the character to look for
*Return: (string) a pointer to the memory area string
*/
char *_strchr(char *string, char c)
{
do {
if (*string == c)
return (string);
} while (*string++ != '\0');

return (NULL);
}
