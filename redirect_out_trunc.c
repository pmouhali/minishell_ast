// 42 HEADER

#include "minishell.h"

int		redirect_out_trunc(t_node *n, t_options *options)
{
	int file_fd;
	int	tmp;
	int ret;

	if (n->type != REDIR_OUT_1)
		return (-1);
	if ((file_fd = open(n->args[0], O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1)
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
**	Le fichier à ouvrir se trouve a n->args[0]	
**	Le node de droite sera évalué.
*/
