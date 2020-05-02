// 42 HEADER

#include "minishell.h"

t_node	*btree_node_new(int type, char **args)
{
	t_node *new;

	if (!(new = malloc(sizeof(t_node) * 1)))
		return (NULL);
	new->type = type;
	new->args = args;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
