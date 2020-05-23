// 42 HEADER

/*
**	[SYNTAX]
**
** 	echo [option args ...]
**
**	[DESCRIPTION]
**
**	affiche chaque argument suivi d'un espace
**	le dernier argument est suivi d'un newline et non d'un espace
**
**	si l'option -n est présente, le newline final n'est pas imprimé
**
**	[RETURN VALUES]
**	0
*/

#include "minishell.h"

int		echo(char *args[])
{
	char nl;
	int i;

	nl = true;
	i = 0;
	while (args[++i] && ft_strcmp(args[i], "-n") == 0)
		nl = false;
	i--;
	while (args[++i])
		ft_dprintf(STDOUT_FILENO, args[i + 1] == NULL ? "%s" : "%s ", args[i]);
	if (nl)
		ft_dprintf(STDOUT_FILENO, "\n");
	return (0);
}
