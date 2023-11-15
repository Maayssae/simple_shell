#include "shell.h"

/**
 * _memset - fills memory *n with a constant byte *b
 * @m: a pointer to the memory area
 * @b: a byte to fill *m with
 * @n: the amount of bytes to be filled
 * Return: (m) a pointer to the memory area m
 */
char *_memset(char *m, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		m[i] = b;
	return (m);
}

/**
 * ffree - frees an array of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - memory block reallocation
 * @ptr: pointer to previous malloc block
 * @old_size: byte size for an old block
 * @new_size: byte size for a new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
