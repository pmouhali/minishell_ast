// 42 HEADER

#include "minishell.h"

/*
**	ROLE
**
**	Evaluer un node. Appel la fonction correspondant au type du node :
**	lancer le processus si c'est une 'commande'
**	appeler une fonction de gestion si c'est un operateur
**	ne rien faire si le node est null
**
**	Retourne 0 ou errno maybe ?
*/

// Est ce que c'est vraiment une bonne idée de déclarer ce truc ici ? IDK

static t_eval_node_function g_eval_node_functions[10] = {
	&run_process, &redirect_out_trunc, &redirect_out_append, &redirect_in
};

int		eval_node(t_node *node, void *options)
{
	if (node)
		return (g_eval_node_functions[node->type](node, options));	
	return (0);
}
