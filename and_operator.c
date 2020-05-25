// 42 HEADER

#include "minishell.h"

int		and_operator(t_node *n, t_options *opt)
{
	int r;
	(void)opt;

	if (!n || n->type != AND)
	{
		ft_perrorc("and_operator", "", "le node est null ou du mauvais type");
		return (-1);
	}
	r = process_container(n->left);
	if (r)
		return (r);
	return (process_container(n->right));
}
