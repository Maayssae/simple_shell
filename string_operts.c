#include "shell.h"

/**
* _strlen - returns the length of a string
* @string: the string whose length to check
*
* Return: integer length of string
*/
int _strlen(char *string)
{
int i = 0;

if (!string)
return (0);

while (*string++)
i++;
return (i);
}

/**
* _strcmp - performs lexicogarphic comparison of two strangs.
* @str1: the first strang
* @str2: the second strang
*
* Return: negative if str1<str2, positive if str1>str2, zero if str ==str2
*/
int _strcmp(char *str1, char *str2)
{
while (*str1 && *str2)
{
if (*str1 != *str2)
return (*str1 - *str2);
str1++;
str2++;
}
if (*str1 == *str2)
return (0);
else
return (*str1 < *str2 ? -1 : 1);
}

/**
* starts_with - checks if needle starts with haystack
* @haystack: string to search
* @needle: the sub string to find
*
* Return: address of next char of haystack or NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
* _strcat - concatenates two strings
* @dest: the destination buffer
* @src: the source buffer
*
* Return: pointer to destination buffer
*/
char *_strcat(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
