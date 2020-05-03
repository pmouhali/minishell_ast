// 42 HEADER

#include "minishell.h"

int		run_process(t_node *n, void *options)
{
	(void)options;
	int pid;

	if (!n || n->type != COMMAND || n->args == NULL)
		return (-1);
	if ((pid = fork()) == -1)
		return (errno);
	if (pid == 0) // child process
	{
		execve(n->args[0], n->args, environment);
		exit(errno);
	}
	return (0);
}
