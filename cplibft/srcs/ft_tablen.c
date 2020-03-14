// 42 HEADER

#include "libft.h"

/*
**	return the lenght of the given two-dimensional array
**	do not count the null terminating pointer
**	segfaults if the given tab is null, maybe change that ?
*/

int		ft_tablen(const void **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
