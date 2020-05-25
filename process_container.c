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
**	les valeures de retour d'eval_node et celle de status sont différentes
**	status corresponds à l'exit code d'un processus forké
**	launch_status corresponds au code de retour des fonctions internes
**	d'éxecution
*/

int		process_container(t_node *root)
{
	int pid;
	int status;
	int launch_status;

	status = 0;
	launch_status = eval_node(root, NULL);
	pid = 1;
	while (pid > 0)
		pid = wait(&status);
	if (launch_status)
		return (launch_status);
	return (WEXITSTATUS(status));
}
