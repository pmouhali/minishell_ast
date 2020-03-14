#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
{
	char *stacktab[] = {
		"my cat is", "orange", "with", "green stripes", "and also", "pink zebras", ", i found him", "on a foreign", "planet", "named : Blargon 7.",
		"He really is a nice cat.", "But", "he likes to eat babies", "...", "human babies..", "it's a weird cat but i like him.", 0
	};
	char **heaptab = (char **)ft_tabdup((const void**)stacktab, (void*)&ft_strdup);

	ft_tabdeletem((void**)heaptab, "orange", (void*)&ft_strcmp);
	ft_tabdeletem((void**)heaptab, "with", (void*)&ft_strcmp);
	ft_tabdeletem((void**)heaptab, "green stripes", (void*)&ft_strcmp);
	ft_tabdeletem((void**)heaptab, "and also", (void*)&ft_strcmp);
	ft_tabdeletem((void**)heaptab, "pink zebras", (void*)&ft_strcmp);
	ft_tabdeletem((void**)heaptab, ", i found him", (void*)&ft_strcmp);
	ft_tabdeletem((void**)heaptab, "on a foreign", (void*)&ft_strcmp);
	ft_tabdeletem((void**)heaptab, "planet", (void*)&ft_strcmp);
	ft_tabdeletem((void**)heaptab, "", (void*)&ft_strcmp);
	ft_tabdeletem((void**)heaptab, "orange", (void*)&ft_strcmp);
	ft_tabdeletem((void**)heaptab, "with", (void*)&ft_strcmp);

	int i = -1;
	while (heaptab[++i])
		printf("[%3d] %s\n", i, heaptab[i]);
	ft_tabfree((void**)heaptab);
	return (0);
}
