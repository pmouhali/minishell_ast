/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:01:21 by suzie             #+#    #+#             */
/*   Updated: 2020/03/16 16:51:18 by suzie            ###   ########.fr       */
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
#include <stdio.h>

static int  keycmp(char *key, char *str)
{
    unsigned int i;

	i = 0;
	while (key[i] == str[i] && key[i] != '\0' && str[i] != '\0')
		i++;
	return ((unsigned char)key[i] - (unsigned char)str[i]);
}

char    *get_key_value(char *key, char **tab)
{
	int i;
	char *value;

    i = ft_tabindex((const void**)tab, (const void*)key, (void*)&keycmp);
	value = ft_strdup(tab[i] + ft_strlen(key));
	return (value);
}
