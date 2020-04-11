/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 14:40:36 by suzie             #+#    #+#             */
/*   Updated: 2020/04/11 14:13:58 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 42 HEADER

/*
**	[SYNTAX]
**
** 	unset [args ...]
**
**	[DESCRIPTION]
**
**  Supprime dans l'environnement les arguments donnés.
**
** 	si un des arguments n'est pas valide :
** 	il n'est pas supprimé, une erreur est affichée.
** 	les arguments valides sont quand même supprimés.
**
**	[RETURN VALUES]
**
**	0 si tout les arguments étaient valides, 1 si un ou plusieurs des arguments
**	étaient invalides
*/

#include "../minishell.h"

int ft_unset(char *arg[])
{
    int i;
    int ret;
    
    i = 1;
    ret = 0;
    while (arg[i])
    {
        if (valid_envar_id(arg[i]) ==  false)
        {
            ft_perrorc("minishell: unset:", arg[i], "invalid identifier");
            ret = 1;
        }
        else
            ft_tabdeletem((void**)environment, arg[i], (void*)&ft_strcmp);
        i++;
    }
    return(ret);
}