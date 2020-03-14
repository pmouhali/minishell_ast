#include <stdlib.h>
#include <stdio.h>
#include "libft.h" 

int		main(void)
{
	char *s;
	int *t;
	int i = 0;
	
	s = calloc(0, sizeof(char));
	printf("o %lu\n", sizeof(s));
	printf("o %i\n", *s);
	free(s);
	s = ft_calloc(0, sizeof(char));
	printf("f %lu\n", sizeof(s));
	printf("f %i\n", *s);
	free(s);

	s = calloc(10, 0);
	printf("o %lu\n", sizeof(s));
	printf("o %i\n", *s);
	free(s);
	s = ft_calloc(10, 0);
	printf("f %lu\n", sizeof(s));
	printf("f %i\n", *s);
	free(s);

	s = calloc(10, sizeof(char));
	while (i < 11)
	{
		printf("%c | ", s[i] + 48);
		i++;
	}
	printf("\n");
	free(s);

	i = 0;
	s = ft_calloc(10, sizeof(char));
	while (i < 11)
	{
		printf("%c | ", s[i] + 48);
		i++;
	}
	printf("\n");
	free(s);
	
	i = 0;
	t = calloc(10, sizeof(int));
	while (i < 11)
	{
		printf("%i | ", t[i]);
		i++;
	}
	printf("\n");
	free(t);

	i = 0;
	t = ft_calloc(10, sizeof(int));
	while (i < 11)
	{
		printf("%i | ", t[i]);
		i++;
	}
	printf("\n");
	free(t);
}
