#include "minishell.h"

int		main(int ac, char **av, char **envp)
{
	char *cecho[] = {"echo", "a", NULL};
	char *cfalse[] = {"false", NULL};
	environment = (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup);
	int r; t_node *ast; char **c1, **c2, **c3, **c4, **c5, **c6, **c7;

	//=== TEST1 ===
	printf("$> echo a || echo b && echo c\n");
	c1 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "b";
	c2 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "c";
	c3 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);

	ast = btree_node_new(AND, NULL);
	ast->right = btree_node_new(COMMAND, c3);
	ast->left = btree_node_new(OR, NULL);
	ast->left->left = btree_node_new(COMMAND, c1);
	ast->left->right = btree_node_new(COMMAND, c2);

	printf("EXIT CODE [%d] %s\n\n", (r = process_container(ast)), strerror(errno));
	btree_delete(ast);
	//=== TEST1 ===

	//=== TEST2 ===
	printf("$> echo a && echo b || echo c\n");
	cecho[1] = "a"; c1 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "b"; c2 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "c"; c3 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);

	ast = btree_node_new(OR, NULL);
	ast->right = btree_node_new(COMMAND, c3);
	ast->left = btree_node_new(AND, NULL);
	ast->left->left = btree_node_new(COMMAND, c1);
	ast->left->right = btree_node_new(COMMAND, c2);

	printf("EXIT CODE [%d] %s\n\n", (r = process_container(ast)), strerror(errno));
	btree_delete(ast);
	//=== TEST2 ===

	//=== TEST3 ===
	printf("$> echo a || echo b && echo c && echo d || echo e || echo f\n");
	cecho[1] = "a"; c1 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "b"; c2 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "c"; c3 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "d"; c4 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "e"; c5 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "f"; c6 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);

	ast = btree_node_new(OR, NULL);
	ast->right = btree_node_new(OR, NULL);
	ast->right->left = btree_node_new(COMMAND, c5);
	ast->right->right = btree_node_new(COMMAND, c6);
	ast->left = btree_node_new(AND, NULL);
	ast->left->left = btree_node_new(OR, NULL);
	ast->left->left->left = btree_node_new(COMMAND, c1);
	ast->left->left->right = btree_node_new(COMMAND, c2);
	ast->left->right = btree_node_new(AND, NULL);
	ast->left->right->left = btree_node_new(COMMAND, c3);
	ast->left->right->right = btree_node_new(COMMAND, c4);
	/*
											OR
										 /      \
									  AND        OR
									 /   \      /  \
								   OR	  AND  c5  c6
								  /  \   /   \
								 c1  c2 c3   c4
	*/

	printf("EXIT CODE [%d] %s\n\n", (r = process_container(ast)), strerror(errno));
	btree_delete(ast);
	//=== TEST3 ===

	//=== TEST4 ===
	printf("$> echo a || echo b && echo c && echo d || echo e || echo f && echo g\n");
	cecho[1] = "a"; c1 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "b"; c2 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "c"; c3 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "d"; c4 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "e"; c5 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "f"; c6 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "g"; c7 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);

	ast = btree_node_new(AND, NULL);
	ast->right = btree_node_new(COMMAND, c7);
	ast->left = btree_node_new(OR, NULL);
	ast->left->right = btree_node_new(OR, NULL);
	ast->left->right->left = btree_node_new(COMMAND, c5);
	ast->left->right->right = btree_node_new(COMMAND, c6);
	ast->left->left = btree_node_new(AND, NULL);
	ast->left->left->left = btree_node_new(OR, NULL);
	ast->left->left->left->left = btree_node_new(COMMAND, c1);
	ast->left->left->left->right = btree_node_new(COMMAND, c2);
	ast->left->left->right = btree_node_new(AND, NULL);
	ast->left->left->right->left = btree_node_new(COMMAND, c3);
	ast->left->left->right->right = btree_node_new(COMMAND, c4);
	/*
											   AND
											  /   \
											OR	   c7
										 /      \
									  AND        OR
									 /   \      /  \
								   OR	  AND  c5  c6
								  /  \   /   \
								 c1  c2 c3   c4
	*/

	printf("EXIT CODE [%d] %s\n\n", (r = process_container(ast)), strerror(errno));
	btree_delete(ast);
	//=== TEST4 ===

	ft_tabfree((void**)environment);
}
