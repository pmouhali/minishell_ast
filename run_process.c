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

static int	new_piped_process(char *binpath, t_node *n, t_options *opt)
{
	int pid;

	if ((pid = fork()) == -1)
		return (errno);
	if (pid == 0) // child process
	{
		if (opt->previous_pread != -1)
			dup2(opt->previous_pread, STDIN_FILENO);		// Where the process gets the data : not the stdin, but the pipe file descriptor
		if (opt->current_pwrite != -1)
			dup2(opt->current_pwrite, STDOUT_FILENO);		// Where the process writes the data : not the stdout, but the pipe file descriptor
		close_pipe(&opt->previous_pread, &opt->previous_pwrite);
		close_pipe(&opt->current_pread, &opt->current_pwrite);
		execve(binpath, n->args, environment);
		exit(errno);
	}
	return (0);
}

int		run_process(t_node *n, t_options *options)
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
		if (options->current_pread != -1 || options->previous_pwrite != -1)
			x = new_piped_process(bpath, n, options);
		else
			x = new_process(bpath, n);
		free(bpath);
		return (x);
	}
	ft_perrorc("minishell", n->args[0], errno == EISDIR ? strerror(EISDIR) : "command not found");
	return (errno);
}
