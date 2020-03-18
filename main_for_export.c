#include <stdio.h>
#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
//	environment = (char**)ft_tabdup((const void**)envp, (void*)&strdup);

//	export(av);

//	ft_tabfree((void**)environment);

	printf("%d\n", valid_envar_name(av[1]));
	return (0);
}
