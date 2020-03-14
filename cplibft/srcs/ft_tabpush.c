// 42 HEADER

#include "libft.h"

/*
**	[NAME] :
**	ft_tabpush
**	[DESCRIPTION] :
**	creates a copy of the given two-dimensional array with the element to push
**	added at the specified position.
**	duplications are made using the provided duplication function, this function
**	needs to return an allocated pointer.
**	if the specified position is a negative int or is out of range, the given
**	element will be pushed in last position.
**	this function frees the given two-dimensional array, so it needs to be
**	previously allocated.
**	[RETURN VALUE] :
**	returns the new two-dimensional array, or, NULL if one parameter is null or
**	if allocation fail.
*/

void	**ft_tabpush(void *tab[], const void *elem, int index, void *(*dup)(const void *))
{
	void **copy;
	int len;
	int tab_i;
	int copy_i;

	if (!tab || !elem || !dup)
		return (tab);
	len = ft_tablen((const void **)tab) + 1;
	if (!(copy = (void**)malloc(sizeof(*tab) * (len + 1))))
		return (NULL);
	index = index < 0 || index > len - 1 ? len - 1 : index;
	copy[index] = dup(elem); 
	tab_i = -1;
	copy_i = -1;
	while (++copy_i < len)
		if (copy_i != index)
			copy[copy_i] = dup(tab[++tab_i]);
	copy[copy_i] = NULL;
	ft_tabfree(tab);
	return (copy);
}
