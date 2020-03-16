// 42 HEADER

#include "libft.h"

/*
**	[NAME] :
**	ft_tablen
**
**	[DESCRIPTION] :
**	get the lenght of the given two-dimensional array, not including the
**	null-terminating pointer
**
**	[RETURN VALUE] :
**	return the lenght of the array or -1 if the array is null
*/

int		ft_tablen(const void *tab[])
{
	int i;

	if (tab == NULL)
		return (-1);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}
