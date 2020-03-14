#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n);

void	print_itab(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%d | ", tab[i]);
		i++;
	}
	printf("\n");
}

int		main(void)
{
	char new[10];
	int tab[10];

	char new2[10];
	int tab2[10];

	memset(new, 65, 9);
	new[9] = 0;
	printf("new : %s\n", new);
	memset(new, 66, 2);
	new[9] = 0;
	printf("new : %s\n", new);

	memset(tab, -1, 10*sizeof(int));
	print_itab(tab, 10);
	memset(tab, 0, 37);
	print_itab(tab, 10);
	
	ft_memset(new2, 65, 9);
	new2[9] = 0;
	printf("new2: %s\n", new2);
	ft_memset(new2, 66, 2);
	new2[9] = 0;
	printf("new2: %s\n", new2);

	ft_memset(tab2, -1, 10*sizeof(int));
	print_itab(tab2, 10);
	ft_memset(tab2, 0, 37);
	print_itab(tab2, 10);
}
