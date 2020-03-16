// 42 HEADER

#include "libft.h"

/*
**  [NAME] :
**	ft_tabdup
**
**	[DESCRIPTION] :
**	creates a copy of the given two-dimensional array 'tab'
**	for the duplication to work it needs to be given a duplication function
**
**	[RETURN VALUE] :
**	returns the allocated copy
*/

void	**ft_tabdup(const void *tab[], void *(*dup)(const void *))
{
	void **copy;
	int i;

	if (tab == NULL)
		return (NULL);
	if (!(copy = (void**)malloc(sizeof(*tab) * (ft_tablen(tab) + 1))))
		return (NULL);
	i = -1;
	while (tab[++i])
		copy[i] = dup(tab[i]);
	copy[i] = NULL;
	return (copy);
}
