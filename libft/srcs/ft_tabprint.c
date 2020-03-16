// 42 HEADER

#include "libft.h"

/*
**	[NAME] :
**	ft_tabprint
**
**	[DESCRIPTION] :
**  print the given two-dimensional array (must be null-terminated)
**  require a printing function to be passed as a parameter
**	if 'tab' is null, "ft_tabprint: NULL" is printed
**	(testing purpose only bc not optimized)
**
**	[RETURN VALUE] :
**	none
*/

void	ft_tabprint(const void *tab[], void (*print)(const void *))
{
	int i;

	if (tab == NULL)
	{
		ft_putstr("ft_tabprint: NULL\n");
		return ;
	}
	i = -1;
	while (tab[++i])
	{
		print(tab[i]);
		ft_putstr("\n");
	}
}
