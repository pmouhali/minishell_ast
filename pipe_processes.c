// 42 HEADER

#include "minishell.h"

int		pipe_processes(t_node *n, t_options *options)
{
	int r;
	int p[3];

	if (!n || n->type != PIPE)
	{
		ft_perrorc("pipe_processes()", "", "Le node reçu est null ou d'un type différent de PIPE.");
		return (-1);
	}
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
	return (r);
}


/*
**	ROLE
**
**	Créer un pipe, assigner les file descriptors obtenus aux bonnes options
**	Evaluer les nodes left et right
**	Fermer le pipe
**
**	LOGIC
**
**	Lorsque run_process sera appelée, elle vérifiera si des file descriptors
**	sont présent dans les options, si oui elle tentera de 'piper' le processus.
**
**	Elle respectera cette règle afin de 'piper' un processus reçu :
**		READ on PREVIOUS
**		WRITE on CURRENT
**
**	Ce qui permet de faire des swaps à certains moment pour gérer aussi bien
**	un pipe unique qu'un pipeline entier.
**
**	Dans le cas d'un pipe unique :
**
**	Un pipe est crée.
**	Les deux fd sont stockés dans options->current_ (pread, pwrite).
**	
**	Le noeud de gauche est évalué, ce qui finira par lancer le processus.
**	options->current_ contient donc un pipe, options->previous n'en contient pas
**	Lire sur previous_ reviendra donc à lire sur l'entrée standard.	
**	Ecrire sur current_ reviendra à écrire sur le pipe
**	Exactement le comportement attendu pour le processus de gauche.
**
**	Les deux fd sont déplacés dans previous_, et current_ remis à -1.
**
**	Le noeud de droite est évalué, ce qui finira par lancer un processus.
**	options->current_ ne contient rien, options->previous contient le pipe
**	Lire sur previous_ reviendra donc à lire sur le pipe.
**	Ecrire sur current_ reviendra à écrire sur la sortie standard
**	Exactement le comportement attendu pour le processus de droite.
**
**	Le pipe est fermé.
**
**	Concernant le multi pipe, ça fonctionne de la même manière, les options
**	peuvent contenir deux pipes simultanément (quatre file descriptor).
**	L'ordre des déplacement entre current_ et previous_ et fait pour que le bon
**	pipe soit toujours au bon endroit.
**	Après le lancement du processus de gauche, le pipe situé dans previous
**	est fermé.
**	C'est parce que si l'on est sur un processus de milieu de pipeline, le pipe
**	créé juste avant et sur lequel on vient de lire doit être fermé, sinon
**	ça tourne dans le vide.
**	Cette action es réalisé dans tout les cas, c'est safe puisque la fonction
**	close_pipe() n'appel pas l'appel système close pour rien.
*/
