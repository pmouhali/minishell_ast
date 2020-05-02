// 42 HEADER

#include "minishell.h"

/*
**	[NOM] : btree_delete()
**
**	[DESCRIPTION] :
**
**	supprime tout les nodes d'un arbre binaire
**	la mémoire est libérée et le pointeur root mis à NULL
*/

void	btree_delete(t_node *node)
{
	if (!node)
		return ;
	btree_delete(node->left);
	btree_delete(node->right);
	free(node);
	node = NULL;
}
