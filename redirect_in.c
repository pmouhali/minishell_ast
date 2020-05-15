// 42 HEADER

#include "minishell.h"

int		redirect_in(t_node *n, void *options)
{
	int file_fd;
	int	stdin_save;
	int ret;

	if (n->left->type != OPERATOR_ARG || n->type != REDIR_IN_1)
		return (-1);
	if ((file_fd = open(n->left->args[0], O_RDONLY)) == -1)
	{
		ft_perrorc("minishell", n->left->args[0], strerror(errno));
		return (-1);
	}
	if ((stdin_save = dup(STDIN_FILENO)) == -1)
	{
		close(file_fd);
		return (-1);
	}
	if (dup2(file_fd, STDIN_FILENO) == -1)
	{
		close(file_fd);
		close(stdin_save);
		return (-1);
	}
	ret = eval_node(n->right, options);
	close(file_fd);
	if (dup2(stdin_save, STDIN_FILENO) == -1)
	{
		close(stdin_save);
		return (-1);
	}
	close(stdin_save);
	return (ret);
}

/*
**	Reçoit un node de type REDIR_IN_1
**
**	Le node de gauche est considéré comme l'argument, donc le fichier à ouvrir.
**	Celui de droite sera évalué.
*/
