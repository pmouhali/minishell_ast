// 42 HEADER

#include "minishell.h"

int		redirect_in(t_node *n, t_options *options)
{
	int file_fd;
	int	tmp;
	int ret;

	if (n->type != REDIR_IN_1)
		return (-1);
	if ((file_fd = open(n->args[0], O_RDONLY)) == -1)
	{
		ft_perrorc("minishell", n->args[0], strerror(errno));
		return (-1);
	}
	tmp = options->previous_pread;
	options->previous_pread = file_fd;
	ret = eval_node(n->right, options);
	options->previous_pread = tmp;
	close(file_fd);
	return (ret);
}

/*
**	Reçoit un node de type REDIR_IN_1
**
**	Le fichier à ouvrir se trouve dans node->args[0]
**	Celui de droite sera évalué.
*/
