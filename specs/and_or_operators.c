#include "minishell.h"

int		main(int ac, char **av, char **envp)
{
	char *cecho[] = {"echo", "a", NULL};
	char *cfalse[] = {"false", NULL};
	environment = (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup);
	int r; t_node *ast; char **c1, **c2, **c3, **c4;

	//=== TEST1 ===
	printf("$> echo a && echo b\n");
	c1 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "b";
	c2 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);

	ast = btree_node_new(AND, NULL);
	ast->left = btree_node_new(COMMAND, c1);
	ast->right = btree_node_new(COMMAND, c2);

	printf("EXIT CODE [%d] %s\n\n", (r = process_container(ast)), strerror(errno));
	btree_delete(ast);
	//=== TEST1 ===

	//=== TEST2 ===
	printf("$> false && echo b\n");
	c1 = (char**)ft_tabdup((const void**)cfalse, (void*)&ft_strdup);
	c2 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);

	ast = btree_node_new(AND, NULL);
	ast->left = btree_node_new(COMMAND, c1);
	ast->right = btree_node_new(COMMAND, c2);

	printf("EXIT CODE [%d] %s\n\n", (r = process_container(ast)), strerror(errno));
	btree_delete(ast);
	//=== TEST2 ===

	//=== TEST3 ===
	printf("$> echo a && echo b && echo c && echo d\n");
	cecho[1] = "a"; c1 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "b"; c2 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "c"; c3 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "d"; c4 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);

	ast = btree_node_new(AND, NULL);
	ast->left = btree_node_new(COMMAND, c1);
	ast->right = btree_node_new(AND, NULL);
	ast->right->left = btree_node_new(COMMAND, c2);
	ast->right->right = btree_node_new(AND, NULL);
	ast->right->right->left = btree_node_new(COMMAND, c3);
	ast->right->right->right = btree_node_new(COMMAND, c4);

	printf("EXIT CODE [%d] %s\n\n", (r = process_container(ast)), strerror(errno));
	btree_delete(ast);
	//=== TEST3 ===

	//=== TEST4 ===
	printf("$> echo a && echo b && false && echo d\n");
	cecho[1] = "a"; c1 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "b"; c2 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	c3 = (char**)ft_tabdup((const void**)cfalse, (void*)&ft_strdup);
	cecho[1] = "d"; c4 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);

	ast = btree_node_new(AND, NULL);
	ast->left = btree_node_new(COMMAND, c1);
	ast->right = btree_node_new(AND, NULL);
	ast->right->left = btree_node_new(COMMAND, c2);
	ast->right->right = btree_node_new(AND, NULL);
	ast->right->right->left = btree_node_new(COMMAND, c3);
	ast->right->right->right = btree_node_new(COMMAND, c4);

	printf("EXIT CODE [%d] %s\n\n", (r = process_container(ast)), strerror(errno));
	btree_delete(ast);
	//=== TEST4 ===

	//=== TEST5 ===
	printf("$> echo a && echo b && echo c && false\n");
	cecho[1] = "a"; c1 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "b"; c2 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "c"; c3 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	c4 = (char**)ft_tabdup((const void**)cfalse, (void*)&ft_strdup);

	ast = btree_node_new(AND, NULL);
	ast->left = btree_node_new(COMMAND, c1);
	ast->right = btree_node_new(AND, NULL);
	ast->right->left = btree_node_new(COMMAND, c2);
	ast->right->right = btree_node_new(AND, NULL);
	ast->right->right->left = btree_node_new(COMMAND, c3);
	ast->right->right->right = btree_node_new(COMMAND, c4);

	printf("EXIT CODE [%d] %s\n\n", (r = process_container(ast)), strerror(errno));
	btree_delete(ast);
	//=== TEST5 ===

	//=== TEST6 ===
	printf("$> echo a || echo b\n");
	cecho[1] = "a";
	c1 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "b";
	c2 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);

	ast = btree_node_new(OR, NULL);
	ast->left = btree_node_new(COMMAND, c1);
	ast->right = btree_node_new(COMMAND, c2);

	printf("EXIT CODE [%d] %s\n\n", (r = process_container(ast)), strerror(errno));
	btree_delete(ast);
	//=== TEST6 ===

	//=== TEST7 ===
	printf("$> false || echo b\n");
	c1 = (char**)ft_tabdup((const void**)cfalse, (void*)&ft_strdup);
	c2 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);

	ast = btree_node_new(OR, NULL);
	ast->left = btree_node_new(COMMAND, c1);
	ast->right = btree_node_new(COMMAND, c2);

	printf("EXIT CODE [%d] %s\n\n", (r = process_container(ast)), strerror(errno));
	btree_delete(ast);
	//=== TEST7 ===

	//=== TEST8 ===
	printf("$> false || false || echo c || echo d\n");
	c1 = (char**)ft_tabdup((const void**)cfalse, (void*)&ft_strdup);
	c2 = (char**)ft_tabdup((const void**)cfalse, (void*)&ft_strdup);
	cecho[1] = "c"; c3 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);
	cecho[1] = "d"; c4 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);

	ast = btree_node_new(OR, NULL);
	ast->left = btree_node_new(COMMAND, c1);
	ast->right = btree_node_new(OR, NULL);
	ast->right->left = btree_node_new(COMMAND, c2);
	ast->right->right = btree_node_new(OR, NULL);
	ast->right->right->left = btree_node_new(COMMAND, c3);
	ast->right->right->right = btree_node_new(COMMAND, c4);

	printf("EXIT CODE [%d] %s\n\n", (r = process_container(ast)), strerror(errno));
	btree_delete(ast);
	//=== TEST8 ===

	//=== TEST9 ===
	printf("$> false && false && false && echo d\n");
	c1 = (char**)ft_tabdup((const void**)cfalse, (void*)&ft_strdup);
	c2 = (char**)ft_tabdup((const void**)cfalse, (void*)&ft_strdup);
	c3 = (char**)ft_tabdup((const void**)cfalse, (void*)&ft_strdup);
	cecho[1] = "d"; c4 = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup);

	ast = btree_node_new(OR, NULL);
	ast->left = btree_node_new(COMMAND, c1);
	ast->right = btree_node_new(OR, NULL);
	ast->right->left = btree_node_new(COMMAND, c2);
	ast->right->right = btree_node_new(OR, NULL);
	ast->right->right->left = btree_node_new(COMMAND, c3);
	ast->right->right->right = btree_node_new(COMMAND, c4);

	printf("EXIT CODE [%d] %s\n\n", (r = process_container(ast)), strerror(errno));
	btree_delete(ast);
	//=== TEST9 ===

	ft_tabfree((void**)environment);
}
