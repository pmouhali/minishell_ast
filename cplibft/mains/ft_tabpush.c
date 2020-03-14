#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char *tab[] = {"my cat", "is", "green, it's", "an", "alien", "cat", "!", 0};
	char **copy;

	copy = (char**)ft_tabdup((const void**)tab, (void*)(&strdup));
	if (copy == NULL)
		return (printf("tabdup : copy is null\n"));

	copy = (char**)ft_tabpush((void**)copy, "NOT", 2, (void*)(&strdup));
	copy = (char**)ft_tabpush((void**)copy, "NOT", 4, (void*)(&strdup));
	copy = (char**)ft_tabpush((void**)copy, "I really love my alien cat.", -1, (void*)(&strdup));
	copy = (char**)ft_tabpush((void**)copy, "I mean my normal cat.", 15, (void*)(&strdup));
	copy = (char**)ft_tabpush((void**)copy, "Oops.", 12, (void*)(&strdup));
	copy = (char**)ft_tabdelete((void**)copy, "NOT", (void*)&ft_strcmp, (void*)(&strdup));
	copy = (char**)ft_tabdelete((void**)copy, "u'll not find me", (void*)&ft_strcmp, (void*)(&strdup));
	copy = (char**)ft_tabdelete((void**)copy, "green, it's", (void*)&ft_strcmp, (void*)(&strdup));
	copy = (char**)ft_tabpush((void**)copy, "pink strayed, it's", 2, (void*)(&strdup));

	int i = -1;
	while (copy[++i])
		printf("[%d] %s\n", i, copy[i]);

	printf("the string %s can be found at index %d\n", "cat", ft_tabindex((const void**)copy, "cat", (void*)&ft_strcmp));
	printf("the string %s can be found at index %d\n", "NOT", ft_tabindex((const void**)copy, "NOT", (void*)&ft_strcmp));
	printf("the string %s can be found at index %d\n", "I really love my alien cat.", ft_tabindex((const void**)copy, "I really love my alien cat.", (void*)&ft_strcmp));
	printf("the string %s can be found at index %d\n", "U'll not find me", ft_tabindex((const void**)copy, "U'll not find me.", (void*)&ft_strcmp));

	ft_tabfree((void**)copy);
	return (0);
}
