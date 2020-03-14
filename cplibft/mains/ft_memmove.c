#include <stdio.h>
#include <string.h>

void    *ft_memmove(void *dest, const void *src, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);

int		main(void)
{

	char dest[] = "ABCDEFGHIJ123";
	char dest1[] = "ABCDEFGHIJ123";
	
	printf("%s\n", memmove(dest + 3, dest, 10));

	printf("%s\n", ft_memmove(dest1 + 3, dest1, 10));

	printf("%s\n", memmove(dest, dest + 3, 10));

	printf("%s\n", ft_memmove(dest1, dest1 + 3, 10));
	
	printf("%s\n", memmove(NULL, NULL, 10));
	printf("%s\n", memmove(dest, NULL, 10));

	return (0);
}
