// HEADER

#include "minishell.h"

/*
**	Itère sur tout les répertoires spécifié dans la variable d'environment PATH
**
**	Paramètres : "paths" pour PATH, bname pour binary name
**
**	Construit un chemin absolu tel que : dirs[x] + bname
**	Vérifie que le chemin existe et mène à un executable
**	Le renvoie si c'est le cas
**
**	Retourne NULL dans les cas suivants :
**
**	PATH est vide (en réalité, l'argument paths)
**	Aucun chemin construit n'existait
*/

char	*build_path(char *paths, char *bname)
{
	char **dirs;
	int i;

	if (!paths)
		return (NULL);
	dirs = ft_split(paths, ':');
	i = -1;
	while (dirs[++i])
	{
		dirs[i] = ft_strjoinplus(ft_strjoinplus(dirs[i], "/", 1), bname, 1);
		if (try_path(dirs[i]))
		{
			bname = ft_strdup(dirs[i]);
			ft_tabfree((void**)dirs);
			return (bname);
		}
	}
	ft_tabfree((void**)dirs);
	return (NULL);
}
