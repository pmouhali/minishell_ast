// 42 HEADER

/*
**	[NAME]
**	ft_tabsort
**
**	[DESCRIPTION]
**	sort the given two-dimensional array using bubble-sort algorithm
**	the comparison is made with the given comparison function
**	the comparison function must take two pointer and return an int
**	about choosing the comparison function to give :
**	keep in mind that the sorting happens in ascending order
**	the function must return greater than zero for the swap to happens
**
**	[RETURN VALUE]
**	-1 if one of the arguments is null, or 0 if no issues found
*/

#include "libft.h"

int		ft_tabsort(void *tab[], int (*cmp)(const void *, const void *))
{
	int i;
	void *tmp;

	if (tab == NULL || cmp == NULL)
		return (-1);
	i = -1;
	while (tab[++i] && tab[i + 1])
	{
		if (cmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
	}
	return (0);
}
