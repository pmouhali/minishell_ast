// 42 HEADER

#include "minishell.h"

int		pipe_processes(t_node *n, t_options *options)
{
	int r;
	int *p;

	if (!n || !n->left || !n->right || n->left->type != COMMAND || n->type != PIPE)
	{
		printf("pipe_process(): l'AST n'as pas été bien généré: n->left est de type %d, n est de type %d et n-right est de type %d\n", n ? n->left->type : 404, n ? n->type : 404, n->right ? n->right->type : 404);
		return (-1);
	}

	p = malloc(sizeof(int) * 3);
	pipe(p);
	options->current_pread = p[RDEND];
	options->current_pwrite = p[WREND];
	eval_node(n->left, options);
	close_pipe(&options->previous_pread, &options->previous_pwrite);
	options->previous_pread = p[RDEND];
	options->previous_pwrite = p[WREND];
	options->current_pread = -1;
	options->current_pwrite = -1;
	r = eval_node(n->right, options);
	close_pipe(&p[RDEND], &p[WREND]);
	free(p);
	return (r);
}


/*
**	create pipe
**	transmit to run process
**		run process dup2 / close pipe
**	close pipe

	Problème :
		Si le node a evaluer est de type commande, on appelle une version différente de run_process.
		Si le node n'est pas de type commande, on apelle eval_node.
		Mais eval_node finira par appeler le run_process normal, et donc le processus ne sera pas piper.
		Donc c'est faux.

		Il faudrait qu'à partir du moment où un operateur pipe est rencontré,
		seul la fonction run_process dedié au pipes soit appelée, jusqu'à
		rencontré un opérateur de plus haute priorité.

	Solution :
		le pipe est passé via la structure options
		dans chaques fonction, que ce soit run_process, redirection, ou pipe
		IL SERA OBLIGATOIRE de vérifier si un pipe est présent dans les options
		si oui, le comportement de la fonction change

	Notes :
		Puisqu'un node PIPE execute de la façon suivante :
			lance le processus à gauche
			evalue le node à droite

			alors, la fonction pipe qui créer un pipe se charge de
			lier le processus de gauche à la write end du pipe

			donc une fonction recevant un pipe qu'elle n'as pas créer elle même
			n'aura jamais à s'occuper de la write end
			seulement de la read

			Si une autre fonction reçoit un pipe, le comportement est le suivant :

				Je lie mon processus à la WREND du pipe que j'ai CREEER
				Je lie mon processus à la RDEND du pipe que j'ai RECUS
				Je close les deux pipes (les 4 fds) dans le processus fils
*/
