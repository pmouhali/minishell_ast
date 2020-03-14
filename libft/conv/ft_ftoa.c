/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:58:09 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/14 20:25:16 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_exclusiveone(long double n)
{
	int c;

	c = 0;
	while (n && c < 2)
	{
		n *= 10;
		n -= (long)n;
		c++;
	}
	if (c == 2)
		return (1);
	else
		return (0);
}

static char		*ft_putmantice(long double n, size_t prec, char *str)
{
	prec++;
	n < 0 && n != -0 ? n *= -1 : 0;
	while (prec)
	{
		n *= 10;
		if (!(str = ft_strjoinplus(str, ft_lltoa((long)n), 3)))
			return (NULL);
		n -= (long)n;
		prec--;
	}
	return (str);
}

static char		*ft_nan_inf(char *str, long double n)
{
	if (n == 1.0 / 0.0)
	{
		if (!(str = ft_strdup("inf")))
			return (NULL);
	}
	else if (n == -1.0 / 0.0)
	{
		if (!(str = ft_strdup("-inf")))
			return (NULL);
	}
	else if (n != n)
	{
		if (!(str = ft_strdup("nan")))
			return (NULL);
	}
	return (str);
}

char			*ft_ftoa(long double n, size_t prec)
{
	char	*str_new;

	str_new = NULL;
	if (n == 1.0 / 0.0 || n == -1.0 / 0.0 || n != n)
	{
		str_new = ft_nan_inf(str_new, n);
		return (str_new);
	}
	else if (1.0 / n == -1.0 / 0.0)
	{
		if (!(str_new = ft_strdup("-0")))
			return (NULL);
	}
	else
		str_new = ft_lltoa(n);
	n = (n) - ((long)n);
	if (ft_exclusiveone(n) || prec)
	{
		if (!(str_new = ft_strjoinplus(str_new, ".", 1)))
			return (NULL);
		str_new = ft_putmantice(n, prec, str_new);
		str_new = arrondi(str_new, ft_strlen(str_new) - 1);
	}
	return (str_new);
}
