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
	printf("Si aucun output apparaît, il y a probablement un problème avec la duplication/restoration du file description STDOUT_FILENO.\n\n");

	int pc_r = 0;
	environment = (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup);		// simule l'environnment (on en a besoin pour execve principalement)
	char **args; 
	char *sa_oparg[] = {"__1.testfile", NULL};
	char **oparg;
	t_node *ast;

	//===TEST1=== commande args > __1.testfile
	printf("TEST1 le résultat de la commande devrait apparaitre SEUL dans __1.testfile\n");
	args = (char**)ft_tabdup((const void**)&av[1], (void*)&ft_strdup); 			// Créer le tableau d'arguments (obligé de l'allouer parce que btree_delete est appelé à la fin)
	oparg = (char**)ft_tabdup((const void**)sa_oparg, (void*)&ft_strdup);		// Pareil que pour les arguments mais pour le node de type OPERATOR_ARG
	ast = btree_node_new(REDIR_OUT_1, NULL);									// Créer le node de type operator : redirection
	ast->left = btree_node_new(OPERATOR_ARG, oparg);							// Créer le node de type operator_arg, il contient le fichier à ouvrir en argument
	ast->right = btree_node_new(COMMAND, args);									// Créer le node de type command : il contient le tableau d'arguments représentant la commande

	pc_r = process_container(ast);
	
	printf("EXIT CODE [%d] %s\n\n", pc_r, strerror(pc_r));

	btree_delete(ast);															// simule le comportement final du programme en terme de free 
	//===TEST1===

	//===TEST2=== commande args >> __2.testfile
	printf("TEST2 le résultat de la commande devrait apparaitre à la suite du contenu déjà présent dans __2.testfile\n");
	args = (char**)ft_tabdup((const void**)&av[1], (void*)&ft_strdup);
	sa_oparg[0] = "__2.testfile";
	oparg = (char**)ft_tabdup((const void**)sa_oparg, (void*)&ft_strdup);
	ast = btree_node_new(REDIR_OUT_2, NULL);
	ast->left = btree_node_new(OPERATOR_ARG, oparg);
	ast->right = btree_node_new(COMMAND, args);

	pc_r = process_container(ast);
	
	printf("EXIT CODE [%d] %s\n\n", pc_r, strerror(pc_r));

	btree_delete(ast);
	//===TEST2===

	//===TEST3=== commande args < __2.testfile
	printf("TEST3 grep devrait lire depuis __2.testfile et surligner au moins la ligne 'minishell.h'\n");
	char *c_grep[]= {"grep", "--color", ".h", NULL};
	args = (char**)ft_tabdup((const void**)c_grep, (void*)&ft_strdup);
	sa_oparg[0] = "__2.testfile";
	oparg = (char**)ft_tabdup((const void**)sa_oparg, (void*)&ft_strdup);
	ast = btree_node_new(REDIR_IN_1, NULL);
	ast->left = btree_node_new(OPERATOR_ARG, oparg);
	ast->right = btree_node_new(COMMAND, args);

	pc_r = process_container(ast);
	
	printf("EXIT CODE [%d] %s\n\n", pc_r, strerror(pc_r));

	btree_delete(ast);
	//===TEST3===

	//===TEST4=== commande args < file_that_does_not_exists
	printf("TEST4 un message d'erreur indiquant que le fichier n'existe pas devrait apparaître et le code d'erreur devrait correspondre à ... ?\n");
	args = (char**)ft_tabdup((const void**)c_grep, (void*)&ft_strdup);
	sa_oparg[0] = "file_that_does_not_exists";
	oparg = (char**)ft_tabdup((const void**)sa_oparg, (void*)&ft_strdup);
	ast = btree_node_new(REDIR_IN_1, NULL);
	ast->left = btree_node_new(OPERATOR_ARG, oparg);
	ast->right = btree_node_new(COMMAND, args);

	pc_r = process_container(ast);
	
	printf("EXIT CODE [%d] %s\n\n", pc_r, strerror(pc_r));

	btree_delete(ast);
	//===TEST4===


	ft_tabfree((void**)environment);	
	return (0);
}
