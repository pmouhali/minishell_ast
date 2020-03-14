// 42 HEADER

/*
**	[NAME] :
**	ft_index
**	[DESCRIPTION] :
**	try to find character 'c' in string 's'.
**	[RETURN VALUE] :
**	returns the index where the first occurrence of c was foud or -1.
*/

#include "libft.h"

int		ft_index(const char *s, int c)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (i);
}
