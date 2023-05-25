#include "shell.h"

/**
 * my_memry_copy - coping liking
 * @destX: destunation.
 * @resur: resursing
 * @bytNumber: numburing
 * Return: empty function
*/
void *my_memry_copy(void *destX, const void *resur,
size_t bytNumber)
{
	unsigned char *dss = destX;
	const unsigned char *crr = resur;
	size_t idd;

	while (idd < bytNumber)
	{
		dss[idd] = crr[idd];
		idd++;
	}
	return (destX);
}


