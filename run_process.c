// 42 HEADER

#include "minishell.h"

int		run_process(t_node *n, void *options)
{
	(void)options;
	char *bpath;
	int pid;

	if (!n || n->type != COMMAND || n->args == NULL)
		return (-1);
	if (!(bpath = build_path(get_key_value(environment, "PATH"), n->args[0])))
		return (COMMAND_NOT_FOUND);
	if ((pid = fork()) == -1)
		return (errno);
	if (pid == 0) // child process
	{
		execve(bpath, n->args, environment);
		exit(errno);
	}
	free(bpath);
	return (0);
}
