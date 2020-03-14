/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 16:12:22 by grochefo          #+#    #+#             */
/*   Updated: 2019/03/18 20:48:56 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_howmanynbr(long long n, int base)
{
	int	t;

	t = 0;
	n < 0 && base == 16 ? t += 5 : 0;
	n < 0 && base == 8 ? t += 6 : 0;
	while (n != 0)
	{
		n /= base;
		t++;
	}
	return (t);
}

static char		*ft_trad(char *str, long long n, char *base)
{
	int i;
	int t;

	t = ft_howmanynbr(n, ft_strlen(base));
	i = 0;
	while (t--)
	{
		str[i] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
		i++;
	}
	return (str);
}

char			*ft_lltoa_base(long long n, char *base)
{
	char	*str;

	if (n == 0)
		str = ft_strdup("0");
	else
	{
		str = ft_strnew(ft_howmanynbr(n, ft_strlen(base)));
		str = ft_trad(str, n, base);
		if (n < 0 && ft_strlen(base) != 16)
		{
			if (ft_strlen(base) == 8 && !(str = ft_strjoinplus(str, "3", 1)))
				return (NULL);
			if (ft_strlen(base) == 10 && !(str = ft_strjoinplus(str, "-", 1)))
				return (NULL);
		}
		str = ft_strrev(str);
	}
	return (str);
}
