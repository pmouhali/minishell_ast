// 42 HEADER

#include "minishell.h"

int		or_operator(t_node *n, t_options *opt)
{
	int r;
	(void)opt;

	if (!n || n->type != OR)
	{
		ft_perrorc("or_operator", "", "le node est null ou du mauvais type");
		return (-1);
	}
	r = process_container(n->left);
	if (r)
		return (process_container(n->right));
	return (r);
}
