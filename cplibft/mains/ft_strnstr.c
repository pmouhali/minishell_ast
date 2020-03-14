#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);

int		main(int ac, char **av)
{
	(void)ac;

	printf("ft_ : %s\n", ft_strnstr(av[1], av[2], atoi(av[3])));
//	printf("    : %s\n", strnstr(av[1], av[2], atoi(av[3])));
}
