// 42 HEADER

#include "minishell.h"

int		redirect_out_append(t_node *n, t_options *options)
{
	int file_fd;
	int	stdout_fd_save;
	int ret;

	if (n->left->type != OPERATOR_ARG || n->type != REDIR_OUT_2)
		return (-1);
	if ((file_fd = open(n->left->args[0], O_WRONLY | O_CREAT | O_APPEND, 0666)) == -1)
		return (-1);
	if ((stdout_fd_save = dup(STDOUT_FILENO)) == -1)
	{
		close(file_fd);
		return (-1);
	}
	if (dup2(file_fd, STDOUT_FILENO) == -1)
	{
		close(file_fd);
		close(stdout_fd_save);
		return (-1);
	}
	ret = eval_node(n->right, options);
	close(file_fd);
	if (dup2(stdout_fd_save, STDOUT_FILENO) == -1)
	{
		close(stdout_fd_save);
		return (-1);
	}
	close(stdout_fd_save);
	return (ret);
}

/*
**	Reçoit un node de type REDIR_OUT_2
**
**	Le node de gauche est considéré comme l'argument, donc le fichier à ouvrir.
**	Celui de droite sera évalué.
*/
