#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	ft_bzero(void *s, size_t n);

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

	bzero(new, 9);
	new[9] = 0;
	printf("new : %s\n", new);
	bzero(new, 2);
	new[9] = 0;
	printf("new : %s\n", new);

	bzero(tab, 10*sizeof(int));
	print_itab(tab, 10);
	bzero(tab, 37);
	print_itab(tab, 10);
	
	ft_bzero(new2, 9);
	new2[9] = 0;
	printf("new2: %s\n", new2);
	ft_bzero(new2, 2);
	new2[9] = 0;
	printf("new2: %s\n", new2);

	ft_bzero(tab2, 10*sizeof(int));
	print_itab(tab2, 10);
	ft_bzero(tab2, 37);
	print_itab(tab2, 10);
}
