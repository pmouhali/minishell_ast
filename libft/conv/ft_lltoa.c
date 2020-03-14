/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:32:06 by grochefo          #+#    #+#             */
/*   Updated: 2019/04/02 01:44:02 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*copy(char *s, long long n, int i)
{
	if (n == LLONG_MIN)
	{
		ft_strcpy(&s[1], "9223372036854775808");
		return (s);
	}
	if (n < 0)
		n = n * -1;
	if (n <= 9)
		s[i] = n + '0';
	else
	{
		copy(s, n / 10, i - 1);
		s[i] = (n % 10) + '0';
	}
	return (s);
}

char			*ft_lltoa(long long n)
{
	char		*str_new;
	int			i;
	long long	svg;

	svg = n;
	i = 1;
	while (svg >= 10 || svg <= -10)
	{
		svg = svg / 10;
		i++;
	}
	if (n < 0)
	{
		if (!(str_new = (char*)ft_memalloc(i + 2)))
			return (NULL);
		str_new[0] = '-';
		i = i + 1;
	}
	else if (!(str_new = (char*)ft_memalloc(i + 1)))
		return (NULL);
	copy(str_new, n, i - 1);
	str_new[i] = '\0';
	return (str_new);
}
