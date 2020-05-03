#include "minishell.h"

int	main(int ac, char *av[], char *envp[])
{
	(void)ac;
	(void)av;
	t_node *root = btree_node_new(AND, NULL);

	root->right = btree_node_new(AND, NULL);
	root->left = NULL;

	root->right->right = btree_node_new(COMMAND, (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup));
	root->right->left = btree_node_new(COMMAND, (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup));

	btree_delete(root);

	return (0);
}
