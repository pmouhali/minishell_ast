// 42 HEADER

#include "minishell.h"

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

int		call_builtin_function(int builtin_index, char *args[], t_options *opt)
{
	int r;
	
	TODO !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	SI OPTIONS : GERER DIRECTION ET PIPES
	r = g_builtin_functions[builtin_index](args);
	RESTORER STDOUT_FILENO && STDIN_FILENO
	return (r);
}

char	*isbinary(char *bname)
{
	if (try_path(bname))
		return (bname);
	if (errno == EISDIR)
		return (NULL);
	return (build_path(get_key_value(environment, "PATH"), bname));
}
