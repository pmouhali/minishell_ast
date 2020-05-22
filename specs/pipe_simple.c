#include "minishell.h"

int		main(int ac, char **av, char **envp)
{
	environment = (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup); // sert à simuler l'environnment (on en a besoin pour execve principalement)

	char *cls[] = {"ls", "-la", NULL};
	char *cgrep[] = {"grep", ".h", NULL};
	char *ctop[] = {"top", NULL};
	char *cnot_real[] = {"idonotexistonurcomputer", NULL};

	int pc_r;
	t_node *ast;

	//=== TEST1 === ls -la | grep '.h'

	char **alloc_ls = (char**)ft_tabdup((const void**)cls, (void*)&ft_strdup);
	char **alloc_grep = (char**)ft_tabdup((const void**)cgrep, (void*)&ft_strdup);

	ast = btree_node_new(PIPE, NULL);
	ast->left = btree_node_new(COMMAND, alloc_ls);
	ast->right = btree_node_new(COMMAND, alloc_grep);

	pc_r = process_container(ast);
	printf("EXIT CODE [%d] %s\n", pc_r, strerror(pc_r));

	btree_delete(ast);
	//=== TEST1 === ls -la | grep '.h'

	//=== TEST2 === top | grep '06'

	char **alloc_top = (char**)ft_tabdup((const void**)ctop, (void*)&ft_strdup);
	cgrep[1] = "systemd";
	alloc_grep = (char**)ft_tabdup((const void**)cgrep, (void*)&ft_strdup);

	ast = btree_node_new(PIPE, NULL);
	ast->left = btree_node_new(COMMAND, alloc_top);
	ast->right = btree_node_new(COMMAND, alloc_grep);

	pc_r = process_container(ast);
	printf("EXIT CODE [%d] %s\n", pc_r, strerror(pc_r));

	btree_delete(ast);
	//=== TEST2 === top | grep '06'

	//=== TEST3 === not_a_real_command | grep '.h'

	char **alloc_not_real = (char**)ft_tabdup((const void**)cnot_real, (void*)&ft_strdup);
	alloc_grep = (char**)ft_tabdup((const void**)cgrep, (void*)&ft_strdup);

	ast = btree_node_new(PIPE, NULL);
	ast->left = btree_node_new(COMMAND, alloc_not_real);
	ast->right = btree_node_new(COMMAND, alloc_grep);

	pc_r = process_container(ast);
	printf("EXIT CODE [%d] %s\n", pc_r, strerror(pc_r));

	btree_delete(ast);
	//=== TEST3 === not_a_real_command | grep '.h'

	//=== TEST4 === ls | not_a_real_command

	alloc_not_real = (char**)ft_tabdup((const void**)cnot_real, (void*)&ft_strdup);
	alloc_ls = (char**)ft_tabdup((const void**)cls, (void*)&ft_strdup);

	ast = btree_node_new(PIPE, NULL);
	ast->left = btree_node_new(COMMAND, alloc_ls);
	ast->right = btree_node_new(COMMAND, alloc_not_real);

	pc_r = process_container(ast);
	printf("EXIT CODE [%d] %s\n", pc_r, strerror(pc_r));

	btree_delete(ast);
	//=== TEST3 === ls | not_a_real_command

	ft_tabfree((void**)environment);	
	return (0);
}
