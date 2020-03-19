// 42 HEADER

/*
**	[SYNTAX]
**
** 	export [args ...]
**
**	[DESCRIPTION]
**
** 	met à jour l'environment avec les arguments donnés, sans gérer aucune option
** 	si il n'y a aucun argument, la liste de toute les variables est affichée
** 	dans l'ordre ascii avec un format chelou (declare -x).
**
** 	si un des arguments n'est pas valide :
** 	il n'est pas push, une erreur est affichée.
** 	les arguments valides sont quand même push.
**
**	[RETURN VALUES]
**
**	0 si tout les arguments étaient valides, 1 si un ou plusieurs des arguments
**	étaient invalides
*/

#include "../minishell.h"

static int	display_mode(void)
{
	int i;
	int e;
	char **t;

	t = (char**)ft_tabdup((const void**)environment, (void*)&ft_strdup);
	ft_tabsort((void **)t, (void*)&ft_strcmp);
	i = -1;
	while (t[++i])
	{
		e = ft_index(t[i], '=');
		ft_dprintf(1, "declare -x %.*s%.*s%s%.*s\n",
			e + 1, t[i],
			e + 1, "\"",
			&t[i][e + 1],
			e + 1, "\""
		);
	}
	ft_tabfree((void **)t);
	return (0);
}

int		ft_export(char *args[])
{
	int i;
	int errors;

	if (args[1] == NULL)
		return (display_mode());
	i = 0;
	errors = 0;
	while (args[++i])
	{
		if (valid_envar_id(args[i]))
		{
			if (push_envar(args[i]) == 1)
			{
				ft_perrorc("minishell: environment erased :(", NULL, NULL);
				return (1);
			}
		}
		else
		{
			ft_perrorc("minishell: export", args[i], "invalid identifier");
			errors++;
		}
	}
	return (errors > 0);
}
