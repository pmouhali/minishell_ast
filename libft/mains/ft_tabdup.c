#include <stdio.h>
#include <string.h>

void	ft_tabfree(void **tab);
int		ft_tablen(const void **tab);
void	**ft_tabdup(const void **tab, void *(*dup)(void *));

int	main(void)
{
	char *tab[] = {"my cat", "is", "green, it's", "an", "alien", "cat", "!", 0};
	char **copy;

	copy = (char**)ft_tabdup((const void**)tab, (void*)(&strdup));

	if (copy == NULL)
		return (printf("copy is null\n"));
	int i = -1;
	while (copy[++i])
		printf("%s\n", copy[i]);
	ft_tabfree((void**)copy);
	return (0);
}
