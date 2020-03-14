#include <stdio.h>
#include <ctype.h>

int		ft_isalpha(int c);

int		main(int ac, char **av)
{
	(void)ac;

	printf("ft_ : %d\n", ft_isalpha(av[1][0]));
	printf("    : %d\n", isalpha(av[1][0]));
}
