/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinplus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:59:33 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/14 15:59:51 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinplus(char *s1, char *s2, int c)
{
	char *str_new;

	str_new = NULL;
	if (s1 && !s2)
	{
		if (!(str_new = ft_strdup(s1)))
			return (NULL);
	}
	else if (s2 && !s1)
	{
		if (!(str_new = ft_strdup(s2)))
			return (NULL);
	}
	else if (s1 && s2)
	{
		if (!(str_new = (char*)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		ft_strcpy(str_new, s1);
		ft_strcat(str_new, s2);
	}
	if (s1 && (c == 1 || c == 3))
		ft_strdel(&s1);
	if (s2 && (c == 2 || c == 3))
		ft_strdel(&s2);
	return (str_new);
}
