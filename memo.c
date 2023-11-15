#include "shell.h"

/**
 * bfree - utility function that frees a pointer and sets it to NULL
 * @ptr: a pointer to a pointer to free
 *
 * Return: 1 if the pointer is freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
