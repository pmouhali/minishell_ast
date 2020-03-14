// 42 HEADER

/*
**	[NAME] :
**	ft_tabdelete
**	[DESCRIPTION] :
**	creates a copy of the given two-dimensional array ignoring the element 'e'.
**	the provided comparison function is used to find 'e' in the array, it will
**	be passed as the argument to ft_tabindex.
**	only the first occurence of 'e' will be ignored.
**	[RETURN VALUE] :
**	returns the new two-dimensional array, or, 'tab' if 'e' is not found or if
**	allocation fails, or if one of the parameter is null.
*/

#include "libft.h"

#include <stdio.h>

void	**ft_tabdelete(void *tab[], const void *e, int (*cmp)(const void *, const void *), void *(*dup)(const void*))
{
	void **copy;
	int i;
	int j;
	int k;

	if (!tab || !e || !cmp || !dup || !(j = ft_tablen((const void **)tab))
		|| (i = ft_tabindex((const void **)tab, e, cmp)) == -1
			|| !(copy = (void**)malloc(sizeof(*tab) * j)))
		return (tab);
	copy[j - 1] = NULL;
	j = -1;
	k = -1;
	while (tab[++j])
		if (j != i)
			copy[++k] = dup(tab[j]); 
	ft_tabfree(tab);
	return (copy);
}
