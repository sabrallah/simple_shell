#include "shell.h"

/**
 * my_read_input  - rea inp
 * @reading: to cha
 * Return: 1 if rea else 0
*/

int my_read_input(char *reading)
{
	ssize_t strr = read(STDIN_FILENO, reading, 1);

	if (strr == -1)
		return (0);
	if (strr == 0)
	{
		if (reading != NULL)
			reading[0] = '\0';
		return (0);
	}
	return (1);
}

/**
 * my_re_allocation  - sam as C realoc
 * @VoidPointer: to olds ones
 * @szz: cuse sizin
 * Return: void
*/

void *my_re_allocation(void *VoidPointer, size_t szz)
{
	void *pointer;

	if (szz == 0)
	{
		free(VoidPointer);
		return (NULL);
	}

	pointer = malloc(szz);
	if (pointer == NULL)
	return (NULL);

	if (VoidPointer != NULL)
	{
		my_memry_copy(pointer, VoidPointer, szz);
		free(VoidPointer);
	}

	return (pointer);
}

/**
 * my_buf_upto  - up the stor bff
 * @buffing: point
 * @sezing: the si of buf
 * @bff: stor
 * @unicId: cur posi of bf
 * Return: void
*/
void my_buf_upto(char **buffing, size_t *sezing, char *bff, size_t unicId)
{
	if (*buffing == NULL || *sezing < unicId)
	{
		*sezing = (unicId > STORAGE_SIZE) ? unicId : STORAGE_SIZE;
		*buffing = bff;
	}
	else
	{
		my_copy_str(*buffing, bff);
		free(bff);
	}
}

