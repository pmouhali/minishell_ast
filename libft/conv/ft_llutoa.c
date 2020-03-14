/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 13:48:52 by grochefo          #+#    #+#             */
/*   Updated: 2019/04/02 01:44:25 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*copy(char *s, unsigned long long n, int i)
{
	if (n <= 9)
		s[i] = n + '0';
	else
	{
		copy(s, n / 10, i - 1);
		s[i] = (n % 10) + '0';
	}
	return (s);
}

char			*ft_llutoa(unsigned long long n)
{
	char				*str_new;
	int					i;
	unsigned long long	svg;

	svg = n;
	i = 1;
	while (svg >= 10)
	{
		svg = svg / 10;
		i++;
	}
	if (!(str_new = ft_strnew(i)))
		return (NULL);
	copy(str_new, n, i - 1);
	str_new[i] = '\0';
	return (str_new);
}
