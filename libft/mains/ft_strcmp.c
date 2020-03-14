#include <string.h>
#include <stdio.h>

int		ft_strcmp(const char *s1, const char *s2);

int		main(void)
{
	printf("ft_ : %d\n", ft_strcmp("test\200", "test\0"));
	printf("    : %d\n", strcmp("test\200", "test\0"));
}
