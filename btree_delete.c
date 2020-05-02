// 42 HEADER

#include "libft.h"

/*
**	[NOM] : btree_delete()
**
**	[DESCRIPTION] :
**
**	supprime tout les nodes d'un arbre binaire
**	la mémoire est libérée et le pointeur root mis à NULL
**
**	supporte n'importe quel structure de node du moment que celle ci
**	possèdes les élements void *left && void *right
*/

void	btree_delete(void *node)
{
	btree_delete(node->left);
	btree_delete(node->right);
	free(node);
	node = NULL;
}
