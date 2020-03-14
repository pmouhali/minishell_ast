// 42 HEADER

/*
**	[NAME] :
**	ft_tabindex
**  [DESCRIPTION] :
**	use the provided comparison function to find an element inside the given
**	two-dimensional array.
**	the comparison function must return zero if the comparison is successful.
**	[RETURN VALUE] :
**	returns the index where object 'e' was found or -1.
**
**	see 'mains/ft_tabpush.c' for usage examples
*/

#include "libft.h"

int		ft_tabindex(const void *tab[], const void *e, int (*cmp)(const void *, const void *))
{
	int i;

	i = -1;
	while (tab[++i])
		if (cmp(tab[i], e) == 0)
			return (i);
	return (-1);
}
