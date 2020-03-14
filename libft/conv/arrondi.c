/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrondi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:49:40 by grochefo          #+#    #+#             */
/*   Updated: 2019/03/13 17:36:20 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*rearrondi(char *str, size_t prec)
{
	while (prec && (str[prec] == '9' || str[prec] == '.'))
	{
		str[prec] == '9' ? str[prec] = '0' : 0;
		prec--;
	}
	if (prec)
		str[prec] += 1;
	else
	{
		if (!(str = ft_strjoinplus("1", str, 2)))
			return (NULL);
	}
	return (str);
}

char			*arrondi(char *str, size_t prec)
{
	char	*str_new;
	size_t	sv;

	sv = prec;
	if (str[prec] == '.')
		prec--;
	else if (str[prec] >= '5')
	{
		if (str[prec - 1] != '9')
		{
			if (str[prec - 1] == '.')
				prec--;
			str[prec - 1] += 1;
		}
		else if (str[prec - 1] == '9')
			str = rearrondi(str, prec);
	}
	if (str[sv - 1] == '.')
		sv--;
	str_new = ft_strndup(str, sv);
	ft_strdel(&str);
	return (str_new);
}
