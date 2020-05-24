// 42 HEADER

#include "minishell.h"

int		redirect_out_append(t_node *n, t_options *options)
{
	int file_fd;
	int ret;
	int tmp;

	if (n->type != REDIR_OUT_2)
		return (-1);
	if ((file_fd = open(n->args[0], O_WRONLY | O_CREAT | O_APPEND, 0666)) == -1)
		return (-1);
	tmp = options->current_pwrite;
	options->current_pwrite = file_fd;
	ret = eval_node(n->right, options);
	options->current_pwrite = tmp;
	close(file_fd);
	return (ret);
}

/*
**	Reçoit un node de type REDIR_OUT_2
**
**	Le fichier à ouvrir se trouve dans node->args[0]	
**	Le node de droite est évalué.
*/
