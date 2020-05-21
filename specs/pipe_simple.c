#include "minishell.h"

/*
**	TEST : l'envoi d'un AST au process_container
**
**	vérifie donc que process_container appel bien eval_node, récupère bien les code de sorte, arrête l'execution si un code de sortie est mauvais
**	vérifie aussi qu'eval_node fonctionne correctement
**	eval_node appel la fonction correspondant au type du node et retourne le résultat
**	donc en fonction du node/ast envoyé, vérifie que les fonctions marchent comme attendu
**
**	Usage :
**	./a.out cat hello.txt
**	
**	Un node est construit avec &argv[1] donc ["cat", "hello.txt, NULL]
*/

int		main(int ac, char **av, char **envp)
{
	environment = (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup); // sert à simuler l'environnment (on en a besoin pour execve principalement)

	char *cls[] = {"ls", "-la", NULL};
	char *cgrep[] = {"grep", ".h", NULL};

	char **alloc_ls = (char**)ft_tabdup((const void**)cls, (void*)&ft_strdup);
	char **alloc_grep = (char**)ft_tabdup((const void**)cgrep, (void*)&ft_strdup);


	t_node *ast;

	ast = btree_node_new(PIPE, NULL);
	ast->left = btree_node_new(COMMAND, alloc_ls);
	ast->right = btree_node_new(COMMAND, alloc_grep);

	int pc_r = process_container(ast);
	
	printf("process_container exit code = %d, %s\n", pc_r, strerror(pc_r));

	ft_tabfree((void**)environment);	
	btree_delete(ast); // btree_delete free aussi le char** du node donc args est free via cette fonction
	return (0);
}
