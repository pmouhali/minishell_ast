#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c);

int		main(int ac, char **av)
{
	(void)ac;

	printf("ft_ : %s\n", ft_strchr(av[1], '\0'));
	printf("    : %s\n", strchr(av[1], '\0'));

	printf("ft_ : %s\n", ft_strchr(av[1], av[2][0]));
	printf("    : %s\n", strchr(av[1], av[2][0]));
}
