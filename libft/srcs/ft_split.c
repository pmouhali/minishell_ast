/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:56:46 by pmouhali          #+#    #+#             */
/*   Updated: 2019/11/13 16:59:43 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	splits(const char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			j++;
		}
	}
	return (j);
}

char		**ft_split(char const *s, char c)
{
	char	**t;
	int		end;
	int		i;
	int		start;

	start = 0;
	i = 0;
	end = 0;
	if (!s)
		return (NULL);
	if (!(t = (char**)malloc(sizeof(char*) * (splits(s, c) + 1))))
		return (NULL);
	while (s[end])
	{
		while (s[end] != '\0' && s[end] == c)
			end++;
		start = end;
		while (s[end] != '\0' && s[end] != c)
			end++;
		if (s[end] == c || (s[end] == '\0' && s[end - 1] != c))
			t[i++] = ft_substr(s, start, (end - start));
	}
	t[i] = NULL;
	return (t);
}
