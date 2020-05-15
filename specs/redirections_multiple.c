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

// create some 2darrays representing commands with their args for later duplication in tests
char *c_ls[]= {"ls", "builtins", NULL};
char *c_echo[]= {"echo", "-n", "Now", "is", "the", "winter", "of", "our", "discontent", ".", NULL};
char *c_cat[]= {"cat", "eval_node.c", NULL};
char *c_env[]= {"env", NULL};
char *c_grep[]= {"grep", "--color" , "un", NULL};

char *tfile1[] = {"__1.testfile", NULL};
char *tfile2[] = {"__2.testfile", NULL};
char *tfile3[] = {"__3.testfile", NULL};

int		main(int ac, char **av, char **envp) // redirection multiples
{
	int pc_r;
	environment = (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup); // sert à simuler l'environnment (on en a besoin pour execve principalement)
	char **tf1;
	char **tf2;
	char **tf3;
	char **args;
	t_node *ast;

	//===TEST1=== commande args > __1.testfile > __2.testfile
	args = (char**)ft_tabdup((const void**)c_ls, (void*)&ft_strdup);
	tf1 = (char**)ft_tabdup((const void**)tfile1, (void*)&ft_strdup);
	tf2 = (char**)ft_tabdup((const void**)tfile2, (void*)&ft_strdup);

	ast = btree_node_new(REDIR_OUT_1, NULL);
	ast->left = btree_node_new(OPERATOR_ARG, tf1); // the file where the output is redirected
	ast->right = btree_node_new(REDIR_OUT_1, NULL); // the command
	ast->right->left = btree_node_new(OPERATOR_ARG, tf2); // the file where the output is redirected
	ast->right->right = btree_node_new(COMMAND, args); // the command

	pc_r = process_container(ast);
	
	printf("[if you don't see this there is a problem with the stdout file descriptor]\nprocess_container exit code = %d, %s\n", pc_r, strerror(errno));

	btree_delete(ast); // btree_delete free aussi le char** du node donc args est free via cette fonction
	//===TEST1===

	//===TEST2=== commande args >> __2.testfile >> __1.testfile
	args = (char**)ft_tabdup((const void**)c_echo, (void*)&ft_strdup);
	tf1 = (char**)ft_tabdup((const void**)tfile1, (void*)&ft_strdup);
	tf2 = (char**)ft_tabdup((const void**)tfile2, (void*)&ft_strdup);

	ast = btree_node_new(REDIR_OUT_2, NULL);
	ast->left = btree_node_new(OPERATOR_ARG, tf2); // the file where the output is redirected
	ast->right = btree_node_new(REDIR_OUT_2, NULL); // the command
	ast->right->left = btree_node_new(OPERATOR_ARG, tf1); // the file where the output is redirected
	ast->right->right = btree_node_new(COMMAND, args); // the command

	pc_r = process_container(ast);
	
	printf("[if you don't see this there is a problem with the stdout file descriptor]\nprocess_container exit code = %d, %s\n", pc_r, strerror(errno));

	btree_delete(ast);
	//===TEST2===

	//===TEST3=== commande args >> __1.testfile >> __2.testfile > __3.testfile
	args = (char**)ft_tabdup((const void**)c_cat, (void*)&ft_strdup);
	tf1 = (char**)ft_tabdup((const void**)tfile1, (void*)&ft_strdup);
	tf2 = (char**)ft_tabdup((const void**)tfile2, (void*)&ft_strdup);
	tf3 = (char**)ft_tabdup((const void**)tfile3, (void*)&ft_strdup);

	ast = btree_node_new(REDIR_OUT_2, NULL);
	ast->left = btree_node_new(OPERATOR_ARG, tf1);
	ast->right = btree_node_new(REDIR_OUT_2, NULL);
	ast->right->left = btree_node_new(OPERATOR_ARG, tf2);
	ast->right->right = btree_node_new(REDIR_OUT_1, NULL);
	ast->right->right->left = btree_node_new(OPERATOR_ARG, tf3);
	ast->right->right->right = btree_node_new(COMMAND, args);

	pc_r = process_container(ast);
	
	printf("[if you don't see this there is a problem with the stdout file descriptor]\nprocess_container exit code = %d, %s\n", pc_r, strerror(errno));

	btree_delete(ast);
	//===TEST3===

	//===TEST4=== commande args < __1.testfile < __3.testfile < __2.testfile
	printf("===TEST4=== commande args < __1.testfile < __3.testfile < __2.testfile\n\n");
	args = (char**)ft_tabdup((const void**)c_grep, (void*)&ft_strdup);
	tf1 = (char**)ft_tabdup((const void**)tfile1, (void*)&ft_strdup);
	tf2 = (char**)ft_tabdup((const void**)tfile3, (void*)&ft_strdup);
	tf3 = (char**)ft_tabdup((const void**)tfile2, (void*)&ft_strdup);

	ast = btree_node_new(REDIR_IN_1, NULL);
	ast->left = btree_node_new(OPERATOR_ARG, tf1);
	ast->right = btree_node_new(REDIR_IN_1, NULL);
	ast->right->left = btree_node_new(OPERATOR_ARG, tf2);
	ast->right->right = btree_node_new(REDIR_IN_1, NULL);
	ast->right->right->left = btree_node_new(OPERATOR_ARG, tf3);
	ast->right->right->right = btree_node_new(COMMAND, args);

	pc_r = process_container(ast);
	
	printf("\nprocess_container() exit code : %d : %s\n", pc_r, strerror(errno));

	btree_delete(ast);
	//===TEST4===

	//===TEST5=== commande args < __1.testfile < file_that_does_not_exists < __2.testfile
	printf("===TEST5=== commande args < __1.testfile < file_that_does_not_exists < __2.testfile\n\n");
	args = (char**)ft_tabdup((const void**)c_grep, (void*)&ft_strdup);
	tf1 = (char**)ft_tabdup((const void**)tfile1, (void*)&ft_strdup);
	tfile3[0] = "file_that_does_not_exists";
	tf2 = (char**)ft_tabdup((const void**)tfile3, (void*)&ft_strdup);
	tfile3[0] = "__3.testfile";
	tf3 = (char**)ft_tabdup((const void**)tfile2, (void*)&ft_strdup);

	ast = btree_node_new(REDIR_IN_1, NULL);
	ast->left = btree_node_new(OPERATOR_ARG, tf1);
	ast->right = btree_node_new(REDIR_IN_1, NULL);
	ast->right->left = btree_node_new(OPERATOR_ARG, tf2);
	ast->right->right = btree_node_new(REDIR_IN_1, NULL);
	ast->right->right->left = btree_node_new(OPERATOR_ARG, tf3);
	ast->right->right->right = btree_node_new(COMMAND, args);

	pc_r = process_container(ast);
	
	printf("\nprocess_container() exit code : %d : %s\n", pc_r, strerror(errno));

	btree_delete(ast);
	//===TEST5===

	//===TEST6=== commande args < __1.testfile > __3.testfile < __2.testfile
	printf("===TEST6=== commande args < __1.testfile > __3.testfile < __2.testfile\n\n");
	args = (char**)ft_tabdup((const void**)c_grep, (void*)&ft_strdup);
	tf1 = (char**)ft_tabdup((const void**)tfile1, (void*)&ft_strdup);
	tfile3[0] = "file_that_does_not_exists";
	tf2 = (char**)ft_tabdup((const void**)tfile3, (void*)&ft_strdup);
	tf3 = (char**)ft_tabdup((const void**)tfile2, (void*)&ft_strdup);

	ast = btree_node_new(REDIR_IN_1, NULL);
	ast->left = btree_node_new(OPERATOR_ARG, tf1);
	ast->right = btree_node_new(REDIR_IN_1, NULL);
	ast->right->left = btree_node_new(OPERATOR_ARG, tf2);
	ast->right->right = btree_node_new(REDIR_IN_1, NULL);
	ast->right->right->left = btree_node_new(OPERATOR_ARG, tf3);
	ast->right->right->right = btree_node_new(COMMAND, args);

	pc_r = process_container(ast);
	
	printf("\nprocess_container() exit code : %d : %s\n", pc_r, strerror(errno));

	btree_delete(ast);
	//===TEST6===

	ft_tabfree((void**)environment);	
	return (0);
}
