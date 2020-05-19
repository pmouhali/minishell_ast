// 42 HEADER

#include "minishell.h"

/*
**	ROLE
**
**	wrapper qui prends un AST en paramètre
**	evalue tout les nodes
**	attends que tout les processus fils lancés se terminent
**	renvoie le code de sortie du dernier processus terminé
**
**	arrête l'execution si problème ?
**	affiche l'erreur ?
*/

int		process_container(t_node *root)
{
	int pid;
	int status;

	status = eval_node(root, NULL);
	pid = 1;
	while (pid > 0)
		pid = wait(&status);
	if (status > 1000)
		return (status);
	return (WEXITSTATUS(status));
}
