// 42 HEADER

#include "minishell.h"

static int	new_process(char *binpath, t_node *n)
{
	int pid;

	if ((pid = fork()) == -1)
		return (errno);
	if (pid == 0) // child process
	{
		execve(binpath, n->args, environment);
		exit(errno);
	}
	return (0);
}

int		run_process(t_node *n, void *options)
{
	(void)options;
	char *bpath;
	int x;

	if (!n || n->type != COMMAND || n->args == NULL)
		return (-1);
	if ((x = isbuiltin(n->args[0])) != -1)
		return (call_builtin_function(x, n->args));
	if ((bpath = isbinary(n->args[0])))
	{
		x = new_process(bpath, n);
		free(bpath);
		return (x);
	}
	return (errno);
}
