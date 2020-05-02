#include "minishell.h"

int	main(void)
{
	
	t_node *root = btree_node_new(AND, NULL);

	root->right = btree_node_new(AND, NULL);
	root->left = NULL;

	root->right->right = btree_node_new(COMMAND, NULL);
	root->right->left = btree_node_new(COMMAND, NULL);

	btree_delete(root);

	return (0);
}
