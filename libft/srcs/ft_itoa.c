/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:24:15 by pmouhali          #+#    #+#             */
/*   Updated: 2019/11/11 15:25:16 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_chrcnt(int n)
{
	int a;

	if (n == 0)
		return (1);
	a = n < 0 ? 1 : 0;
	while (n != 0)
	{
		a += 1;
		n = n / 10;
	}
	return (a);
}

char		*ft_itoa(int n)
{
	char*toa;
	int	i;
	int	m;

	i = ft_itoa_chrcnt(n);
	m = 1;
	if ((toa = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	if (n < 0)
	{
		toa[0] = '-';
		m = -1;
	}
	if (n == 0)
		toa[0] = '0';
	toa[i] = '\0';
	while (n != 0)
	{
		toa[--i] = ((n % 10) * m) + 48;
		n = n / 10;
	}
	return (toa);
}
