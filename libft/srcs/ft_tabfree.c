// 42 HEADER

#include "libft.h"

/*
**	[NAME] :
**	ft_tabfree
**
**	[DESCRIPTION] :
** 	frees a previously allocated and null-terminated two-dimensional array
**
**	[RETURN VALUE] :
**	none
*/

void	ft_tabfree(void **tab)
{
	int i;

	i = -1;
	while (tab && tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
}
