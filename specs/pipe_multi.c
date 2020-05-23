#include "minishell.h"

int		main(int ac, char **av, char **envp)
{
	environment = (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup); // sert à simuler l'environnment (on en a besoin pour execve principalement)

	char *ccat[] = {"cat", "", NULL};
	char *cwc[] = {"wc", NULL};
	char *ctr[] = {"tr", "", "", NULL};
	char *crev[] = {"rev", NULL};
	char *cls[] = {"ls", "-la", NULL};
	char *cgrep[] = {"grep", ".h", NULL};
	char *ccut[] = {"cut", "-c1-6", NULL};
	char *ctop[] = {"top", NULL};
	char *cnot_real[] = {"idonotexistonurcomputer", NULL};

	int pc_r;
	t_node *ast;

	//=== TEST1 === ls -la | grep '.h' | rev

	char **alloc_ls = (char**)ft_tabdup((const void**)cls, (void*)&ft_strdup);
	char **alloc_grep = (char**)ft_tabdup((const void**)cgrep, (void*)&ft_strdup);
	char **alloc_rev = (char**)ft_tabdup((const void**)crev, (void*)&ft_strdup);

	ast = btree_node_new(PIPE, NULL);
	ast->left = btree_node_new(COMMAND, alloc_ls);
	ast->right = btree_node_new(PIPE, NULL);
	ast->right->left = btree_node_new(COMMAND, alloc_grep);
	ast->right->right = btree_node_new(COMMAND, alloc_rev);

	pc_r = process_container(ast);
	printf("EXIT CODE [%d] %s\n", pc_r, strerror(pc_r));

	btree_delete(ast);
	//=== TEST1 === ls -la | grep '.h' | rev

	//=== TEST2 === cat minishell.h | grep '#' | cut -c2-100 | cat -e | rev | grep '$>' | tr -d "$" | rev | tr " " "*" | wc 

	ccat[1] = "minishell.h"; char **alloc_cat = (char**)ft_tabdup((const void**)ccat, (void*)&ft_strdup);
	cgrep[1] = "#"; alloc_grep = (char**)ft_tabdup((const void**)cgrep, (void*)&ft_strdup);
	ccut[1] = "-c2-100"; char **alloc_cut = (char**)ft_tabdup((const void**)ccut, (void*)&ft_strdup);
	ccat[1] = "-e"; char **alloc_cat2 = (char**)ft_tabdup((const void**)ccat, (void*)&ft_strdup);
	alloc_rev = (char**)ft_tabdup((const void**)crev, (void*)&ft_strdup);
	cgrep[1] = "$>"; char **alloc_grep2 = (char**)ft_tabdup((const void**)cgrep, (void*)&ft_strdup);
	ctr[1] = "-d"; ctr[2] = "$"; char **alloc_tr = (char**)ft_tabdup((const void**)ctr, (void*)&ft_strdup);
	char **alloc_rev2 = (char**)ft_tabdup((const void**)crev, (void*)&ft_strdup);
	ctr[1] = " "; ctr[2] = "*"; char **alloc_tr2 = (char**)ft_tabdup((const void**)ctr, (void*)&ft_strdup);
	char **alloc_wc = (char**)ft_tabdup((const void**)cwc, (void*)&ft_strdup);

	ast = btree_node_new(PIPE, NULL);
	ast->left = btree_node_new(COMMAND, alloc_cat);
	ast->right = btree_node_new(PIPE, NULL);
	ast->right->left = btree_node_new(COMMAND, alloc_grep);
	ast->right->right = btree_node_new(PIPE, NULL);
	ast->right->right->left = btree_node_new(COMMAND, alloc_cut);
	ast->right->right->right = btree_node_new(PIPE, NULL);
	ast->right->right->right->left = btree_node_new(COMMAND, alloc_cat2);
	ast->right->right->right->right = btree_node_new(PIPE, NULL);
	ast->right->right->right->right->left = btree_node_new(COMMAND, alloc_rev);
	ast->right->right->right->right->right = btree_node_new(PIPE, NULL);
	ast->right->right->right->right->right->left = btree_node_new(COMMAND, alloc_grep2);
	ast->right->right->right->right->right->right = btree_node_new(PIPE, NULL);
	ast->right->right->right->right->right->right->left = btree_node_new(COMMAND, alloc_tr);
	ast->right->right->right->right->right->right->right = btree_node_new(PIPE, NULL);
	ast->right->right->right->right->right->right->right->left = btree_node_new(COMMAND, alloc_rev2);
	ast->right->right->right->right->right->right->right->right = btree_node_new(PIPE, NULL);
	ast->right->right->right->right->right->right->right->right->left = btree_node_new(COMMAND, alloc_tr2);
	ast->right->right->right->right->right->right->right->right->right = btree_node_new(COMMAND, alloc_wc);

	pc_r = process_container(ast);
	printf("EXIT CODE [%d] %s\n", pc_r, strerror(pc_r));

	btree_delete(ast);
	//=== TEST2 ===


	ft_tabfree((void**)environment);	
	return (0);
}
