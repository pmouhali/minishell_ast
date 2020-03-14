/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:03:01 by grochefo          #+#    #+#             */
/*   Updated: 2019/03/18 20:51:21 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_howmanynbr(unsigned long n, int base)
{
	int	t;

	t = 0;
	while (n != 0)
	{
		n /= base;
		t++;
	}
	return (t);
}

static char		*ft_trad(char *str, unsigned long n, char *base)
{
	int i;
	int t;
	int s;

	s = 0;
	t = ft_howmanynbr(n, ft_strlen(base));
	i = 0;
	while (t--)
	{
		str[i] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
		ft_strlen(base) == 8 && str[i] == '7' ? s++ : 0;
		ft_strlen(base) == 8 && str[i] != '7' ? s = 0 : 0;
		i++;
	}
	s == 7 ? str[i - 1] = '3' : 0;
	return (str);
}

char			*ft_ultoa_base(unsigned long n, char *base)
{
	char	*str;

	if (n == 0)
		str = ft_strdup("0");
	else
	{
		str = ft_strnew(ft_howmanynbr(n, ft_strlen(base)));
		str = ft_trad(str, n, base);
		str = ft_strrev(str);
	}
	return (str);
}
