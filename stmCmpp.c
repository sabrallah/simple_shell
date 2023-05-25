#include <stddef.h>
deepping
/**
 * my_cmp_str - bytes tht benn given by string.
 * @sttOne: character array stt.
 * @sttTwo: chracter string number two.
 * @nbr: max of bytes test.
 *
 * Return: conditionaly sttOne or stttwo.
 */
int my_cmp_str(const char *sttOne, const char *sttTwo, size_t nbr)
{
	size_t idding = 0;

	while (idding < nbr)
	{
		if (sttOne[idding] != sttTwo[idding])
			return ((sttOne[idding] < sttTwo[idding]) ? -1 : 1);
		else if (sttOne[idding] == '\0')
			return (0);
		idding++;
	}
	return (0);
}

