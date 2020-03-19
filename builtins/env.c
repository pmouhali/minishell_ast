// 42 HEADER

/*
**	[SYNTAX]
**
** 	env
**
**	[DESCRIPTION]
**
**	affiche la liste des variables d'environnement sans format
**	seules les variables sans delimiter ne sont pas affichées
**	'EMPTY' ne sera pas affichée
**	'EMPTY=' le sera
**
**	[RETURN VALUES]
**	0, 1 si l'environment n'existe pas
*/

#include "minishell.h"

int		env(char *args[])
{
	int i;
	(void)args;

	if (environment == NULL || environment[0] == NULL)
	{
		ft_perrorc("minishell", "environment is empty or null", NULL);
		return (1);
	}
	i = -1;
	while (environment[++i])
		if (ft_index(environment[i], '=') != -1)
			ft_dprintf(1, "%s\n", environment[i]);
	return (0);
}
