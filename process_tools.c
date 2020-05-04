// 42 HEADER

#include "minishell.h"

/*
**	NAME : isbuiltin()
**
**	ROLE : indique si le nom de binaire passé en paramètre est enfait un builtin
**		   renvoie l'index du builtin dans le tableau de fonctions ou -1 
*/

char *builtin_names[] = {
	"exit", "cd", "echo", "env", "export", "pwd", "unset", NULL
};

t_builtin_function	g_builtin_functions[] = {
	NULL, &change_dir, &echo, &env, &ft_export, &ft_pwd, &ft_unset, NULL
};

int		isbuiltin(char *bname)
{
	return (ft_tabindex(
		(const void **)builtin_names, (const void*)bname, (void*)ft_strcmp
	));
}

/*
**	NAME : call_builtin_function()
**
**	ROLE : appel la fonction builtin correspondant a l'index, avec les arguments passés en paramètres
*/

int		call_builtin_function(int builtin_index, char *args[])
{
	return (g_builtin_functions[builtin_index](args));
}

/*
**	NAME : isbinary()
**
**	ROLE : indique si le nom de binaire passé en paramètres est disponible sur
**			sur la machine retourne son chemin absolu si c'est le cas null sinon
**			la recherche est basé sur la variable d'environment PATH comme d'hab
*/

char	*isbinary(char *bname)
{
	 return (build_path(get_key_value(environment, "PATH"), bname));
}
