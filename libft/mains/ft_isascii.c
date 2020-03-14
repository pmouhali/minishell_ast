#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int		main(int ac, char **av)
{
	(void)ac;

	printf("%d\n", isascii(atoi(av[1])));
	printf("%d\n", atoi(av[1]));
}
