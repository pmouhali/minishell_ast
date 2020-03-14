/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:03:04 by pmouhali          #+#    #+#             */
/*   Updated: 2019/11/09 16:18:06 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((new = (char*)malloc(sizeof(char) * (size))) == NULL)
		return (NULL);
	size = 0;
	while (s1[size] != '\0')
	{
		new[size] = s1[size];
		size++;
	}
	while (*s2 != '\0')
	{
		new[size] = *s2;
		size++;
		s2++;
	}
	new[size] = '\0';
	return (new);
}
