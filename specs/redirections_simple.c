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
	char *testfile[] = {"__1.testfile", NULL};
	char *cls[] = {"ls", "builtins", NULL};
	char *cecho[] = {"echo", "0123456789abcdef", "01", NULL};
	char *cgrep[]= {"grep", "--color", "t", NULL};
	char **alloc_testfile;
	t_node *ast;

	//===TEST1=== commande args > __1.testfile
	printf("TEST1 : echo 0123456789abcdef 01 > __1.testfile\n");
	args = (char**)ft_tabdup((const void**)cecho, (void*)&ft_strdup); 			// Créer le tableau d'arguments (obligé de l'allouer parce que btree_delete est appelé à la fin)
	alloc_testfile = (char**)ft_tabdup((const void**)testfile, (void*)&ft_strdup);		// Pareil que pour les arguments mais pour le node de type OPERATOR_ARG
	ast = btree_node_new(REDIR_OUT_1, alloc_testfile);									// Créer le node de type operator : redirection
	ast->right = btree_node_new(COMMAND, args);									// Créer le node de type command : il contient le tableau d'arguments représentant la commande

	pc_r = process_container(ast);
	system("cat __1.testfile");	// Display le contenu du testfile permettra de vérifier son contenu plus précisemment et efficacement
	printf("EXIT CODE [%d] %s\n\n", pc_r, strerror(pc_r));

	btree_delete(ast);															// simule le comportement final du programme en terme de free 
	//===TEST1===

	//===TEST2=== commande args >> __2.testfile
	printf("TEST2 ls builtins/ >> __2.testfile\n");
	args = (char**)ft_tabdup((const void**)cls, (void*)&ft_strdup);
	testfile[0] = "__2.testfile";
	alloc_testfile = (char**)ft_tabdup((const void**)testfile, (void*)&ft_strdup);
	ast = btree_node_new(REDIR_OUT_2, alloc_testfile);
	ast->right = btree_node_new(COMMAND, args);

	pc_r = process_container(ast);
	system("cat __2.testfile");
	printf("EXIT CODE [%d] %s\n\n", pc_r, strerror(pc_r));

	btree_delete(ast);
	//===TEST2===

	//===TEST3=== commande args < __2.testfile
	printf("TEST3 grep --color t < __2.testfile\n");
	args = (char**)ft_tabdup((const void**)cgrep, (void*)&ft_strdup);
	testfile[0] = "__2.testfile";
	alloc_testfile = (char**)ft_tabdup((const void**)testfile, (void*)&ft_strdup);
	ast = btree_node_new(REDIR_IN_1, alloc_testfile);
	ast->right = btree_node_new(COMMAND, args);

	pc_r = process_container(ast);
	
	printf("EXIT CODE [%d] %s\n\n", pc_r, strerror(pc_r));

	btree_delete(ast);
	//===TEST3===

	//===TEST4=== commande args < file_that_does_not_exists
	printf("TEST4 grep < file_that_does_not_exists\n");
	args = (char**)ft_tabdup((const void**)cgrep, (void*)&ft_strdup);
	testfile[0] = "file_that_does_not_exists";
	alloc_testfile = (char**)ft_tabdup((const void**)testfile, (void*)&ft_strdup);
	ast = btree_node_new(REDIR_IN_1, alloc_testfile);
	ast->right = btree_node_new(COMMAND, args);

	pc_r = process_container(ast);
	
	printf("EXIT CODE [%d] %s\n\n", pc_r, strerror(pc_r));

	btree_delete(ast);
	//===TEST4===


	ft_tabfree((void**)environment);	
	return (0);
}
