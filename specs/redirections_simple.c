#include "minishell.h"

/*
**	TEST : l'envoi d'un AST au process_container avec différentes redirections
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

int		main(int ac, char **av, char **envp) // redirections simple
{
	int pc_r = 0;
	environment = (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup);		// simule l'environnment (on en a besoin pour execve principalement)
	char **args; 
	char *sa_oparg[] = {"__1.testfile", NULL};
	char **oparg;
	t_node *ast;

	//===TEST1=== commande args > __1.testfile
	args = (char**)ft_tabdup((const void**)&av[1], (void*)&ft_strdup); 			// Créer le tableau d'arguments (obligé de l'allouer parce que btree_delete est appelé à la fin)
	oparg = (char**)ft_tabdup((const void**)sa_oparg, (void*)&ft_strdup);		// Pareil que pour les arguments mais pour le node de type OPERATOR_ARG
	ast = btree_node_new(REDIR_OUT_1, NULL);									// Créer le node de type operator : redirection
	ast->left = btree_node_new(OPERATOR_ARG, oparg);							// Créer le node de type operator_arg, il contient le fichier à ouvrir en argument
	ast->right = btree_node_new(COMMAND, args);									// Créer le node de type command : il contient le tableau d'arguments représentant la commande

	pc_r = process_container(ast);
	
	printf("[if you don't see this there is a problem with the stdout file descriptor]\nprocess_container exit code = %d, %s\n", pc_r, strerror(pc_r));

	btree_delete(ast);															// simule le comportement final du programme en terme de free 
	//===TEST1===

	//===TEST2=== commande args >> __2.testfile
	args = (char**)ft_tabdup((const void**)&av[1], (void*)&ft_strdup);
	sa_oparg[0] = "__2.testfile";
	oparg = (char**)ft_tabdup((const void**)sa_oparg, (void*)&ft_strdup);
	ast = btree_node_new(REDIR_OUT_2, NULL);
	ast->left = btree_node_new(OPERATOR_ARG, oparg);
	ast->right = btree_node_new(COMMAND, args);

	pc_r = process_container(ast);
	
	printf("[if you don't see this there is a problem with the stdout file descriptor]\nprocess_container exit code = %d, %s\n", pc_r, strerror(pc_r));

	btree_delete(ast);
	//===TEST2===

	//===TEST3=== commande args < __2.testfile
	char *c_grep[]= {"grep", "--color", "aliens", NULL};
	args = (char**)ft_tabdup((const void**)c_grep, (void*)&ft_strdup);
	sa_oparg[0] = "__2.testfile";
	oparg = (char**)ft_tabdup((const void**)sa_oparg, (void*)&ft_strdup);
	ast = btree_node_new(REDIR_IN_1, NULL);
	ast->left = btree_node_new(OPERATOR_ARG, oparg);
	ast->right = btree_node_new(COMMAND, args);

	pc_r = process_container(ast);
	
	printf("[if you don't see this there is a problem with the stdout file descriptor]\nprocess_container exit code = %d, %s\n", pc_r, strerror(pc_r));

	btree_delete(ast);
	//===TEST3===

	//===TEST4=== commande args < file_that_does_not_exists
	args = (char**)ft_tabdup((const void**)c_grep, (void*)&ft_strdup);
	sa_oparg[0] = "file_that_does_not_exists";
	oparg = (char**)ft_tabdup((const void**)sa_oparg, (void*)&ft_strdup);
	ast = btree_node_new(REDIR_IN_1, NULL);
	ast->left = btree_node_new(OPERATOR_ARG, oparg);
	ast->right = btree_node_new(COMMAND, args);

	pc_r = process_container(ast);
	
	printf("[if you don't see this there is a problem with the stdout file descriptor]\nprocess_container exit code = %d, %s\n", pc_r, strerror(pc_r));

	btree_delete(ast);
	//===TEST4===


	ft_tabfree((void**)environment);	
	return (0);
}
