#include "../minishell.h"
#include <stdio.h>

/*
** HOME shouldn't be displayed
*/

int	main(void)
{
	char *args[] = {NULL};
	char *envp[] = {"USER=emperor_Zorg-7", "PWD=/Projects/invade_earth", "HOME", "OLDPWD=", NULL};
	environment = (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup);
	env(args);
	ft_tabfree((void**)environment);
}
