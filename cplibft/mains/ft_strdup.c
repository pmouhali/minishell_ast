#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strdup(const char *s);

int		main(int ac, char **av)
{
	(void)ac;
	char *n;

	n = ft_strdup(av[1]);
	printf("ft_ : %s\n", n);
	free(n);
	n = strdup(av[1]);
	printf("    : %s\n", n);
	free(n);
}
