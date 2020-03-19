#include <stdio.h>
#include "minishell.h"

int	main(void)
{
	int r, i;
	char *envp[] = {
		"HOME=/Planets/blargon-7", "USER=alien", "PWD=/Projects/invade_earth", NULL
	};
	environment = (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup);

	char *without_error[] = {
		"ft_export", "UNINITIALIZED", "EMPTY=", "USER=emperor Zorg-7", NULL
	};
	r = ft_export(without_error);
	i = ft_tabindex((const void **)environment, without_error[1], (void*)&ft_strcmp);
	ft_dprintf(1, i == -1 ? "%s failed to be pushed\n" : "%s successfully pushed\n",
		without_error[1]
	);
	i = ft_tabindex((const void **)environment, without_error[2], (void*)&ft_strcmp);
	ft_dprintf(1, i == -1 ? "%s failed to be pushed\n" : "%s successfully pushed\n",
		without_error[2]
	);
	i = ft_tabindex((const void **)environment, without_error[3], (void*)&ft_strcmp);
	ft_dprintf(1, i == -1 ? "%s failed to be pushed\n" : "%s successfully pushed\n",
		without_error[3]
	);
	ft_dprintf(1, "shouldn't throw any error, expect 0 got %d\n\n", r);

	char *with_error[] = {
		"ft_export", "OLDPWD=/Projects/invade_saturn", "x,y=658,-89563", "80085=xxxxx", NULL
	};
	r = ft_export(with_error);
	i = ft_tabindex((const void **)environment, with_error[1], (void*)&ft_strcmp);
	ft_dprintf(1, i == -1 ? "%s failed to be pushed\n" : "%s successfully pushed\n",
		with_error[1]
	);
	i = ft_tabindex((const void **)environment, with_error[2], (void*)&ft_strcmp);
	ft_dprintf(1, i != -1 ? "%s shouldn't have been pushed\n" : "%s successfully not pushed\n",
		with_error[2]
	);
	i = ft_tabindex((const void **)environment, with_error[3], (void*)&ft_strcmp);
	ft_dprintf(1, i != -1 ? "%s shouldn't have been pushed\n" : "%s successfully not pushed\n",
		with_error[3]
	);
	ft_dprintf(1, "should throw 2 errors, expect 1 got %d\n\n", r);

	char *only_one_arg[] = {
		"ft_export", "EMPTY", NULL
	};
	r = ft_export(only_one_arg);
	i = ft_tabindex((const void **)environment, only_one_arg[1], (void*)&ft_strcmp);
	ft_dprintf(1, i != -1 ? "%s shouldn't have been pushed\n" : "%s successfully not pushed\n",
		only_one_arg[1]
	);
	ft_dprintf(1, "shouldn't throw any error, expect 0 got %d\n\n", r);
	
	/* Display arrays
	ft_putstr("env before any modification :\n");
	ft_tabprint((const void **)envp, (void*)ft_putstr);
	ft_putstr("env after test suite :\n");
	ft_tabprint((const void **)environment, (void*)ft_putstr);
	*/
	ft_tabfree((void**)environment);
	return (0);
}
