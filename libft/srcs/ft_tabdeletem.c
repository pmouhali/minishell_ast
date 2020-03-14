// 42 HEADER

/*
**	[NAME] :
**	ft_tabdeletem - m stands for memmmove
**	[DESCRIPTION] :
**	frees the element 'e' in the given two-dimensional array and move back
**	all the following pointers so the data remains valid.
**	no reallocation is performed so the previously taken memory remains unused.
**	if 'e' is not found in 'tab', nothing is done.
**	[RETURN VALUE] :
**	constanlty returns the given two-dimensional array.
*/

#include "libft.h"

void	**ft_tabdeletem(void *tab[], const void *e, int (*cmp)(const void *, const void*))
{
	int i;

	i = 0;
	while (tab[i] && cmp(tab[i], e))
		i++;
	if (tab[i] == NULL)
		return (tab);
	free(tab[i]);
	while (tab[i + 1])
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
