// 42 HEADER

#include "minishell.h"

int		redirect_out_trunc(t_node *n, t_options *options)
{
	int file_fd;
	int	tmp;
	int ret;

	if (n->left->type != OPERATOR_ARG || n->type != REDIR_OUT_1)
		return (-1);
	if ((file_fd = open(n->left->args[0], O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)
		return (-1);
	tmp = options->current_pwrite;
	options->current_pwrite = file_fd;
	ret = eval_node(n->right, options);
	options->current_pwrite = tmp;
	close(file_fd);
	return (ret);
}

/*
**	Reçoit un node de type REDIR_OUT_1
**
**	Le node de gauche est considéré comme l'argument, donc le fichier à ouvrir.
**	Celui de droite sera évalué.
*/
