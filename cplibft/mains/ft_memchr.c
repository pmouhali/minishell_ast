#include <stdio.h>
#include <string.h>

void    *ft_memchr(const void *s, int c, size_t n);

void	printab(int *tab, int n)
{
	int i = 0;
	while (i < n)
	{
		printf("%d | ", tab[i]);
		i++;
	}
	printf("\n");
}

int		main(void)
{
	char s1[] = "string";
	char s2[] = "jambon";

	printf("o %s\n", (char*)memchr(s2, '*', 7));
	printf("f %s\n", (char*)ft_memchr(s2, '*', 7));

	printf("o %s\n", (char*)memchr(s1, 'r', 7));
	printf("f %s\n", (char*)ft_memchr(s1, 'r', 7));
	
	printf("o %s\n", (char*)memchr(s1, 'h', 7));
	printf("f %s\n", (char*)ft_memchr(s1, 'h', 7));
	
	printf("o %s\n", (char*)memchr(s1, 'h', 600));
	printf("f %s\n", (char*)ft_memchr(s1, 'h', 600));

	printf("o %s\n", (char*)memchr(s1, 'h', -1));
	printf("f %s\n", (char*)ft_memchr(s1, 'h', -1));

	printf("o %s\n", (char*)memchr(s1, 0, 6));
	printf("f %s\n", (char*)ft_memchr(s1, 0, 6));
	
	printf("o %s\n", (char*)memchr(s1, 0, 7));
	printf("f %s\n", (char*)ft_memchr(s1, 0, 7));
	
	printf("o %s\n", (char*)memchr(s1, 0, 8));
	printf("f %s\n", (char*)ft_memchr(s1, 0, 8));
}
