// 42 HEADER

#include "libft.h"

/*
** frees a previously allocated and null-terminated two-dimensional array
*/

void	ft_tabfree(void **tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
}
