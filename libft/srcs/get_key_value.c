/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:01:21 by suzie             #+#    #+#             */
/*   Updated: 2020/03/16 18:40:11 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	[NAME] :
**	get_key_value
**  [DESCRIPTION] :
**	use the provided comparison function to find the value of a key in a
**	two-dimensional array.
**	the comparison function must return the value of the key.
**	[RETURN VALUE] :
**	returns the value of the key if it was found or NULL;
**
*/

#include "libft.h"

static int  keycmp(char *str, char *key)
{
    unsigned int i;

	i = 0;
	while (str[i] == key[i] && key[i] != '\0' && str[i] != '\0')
		i++;
	if (str[i] == '=')
		return (0);
	return (-1);
}

char    *get_key_value(char **tab, char *key)
{
	int i;

    i = ft_tabindex((const void**)tab, (const void*)key, (void*)&keycmp);
	return ((tab[i]) + ft_strlen(key) + 1);
}
