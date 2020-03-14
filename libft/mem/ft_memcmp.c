/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:52:27 by pmouhali          #+#    #+#             */
/*   Updated: 2019/11/04 14:52:31 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		i = *(unsigned char*)s1 - *(unsigned char*)s2;
		if (i != 0)
			return (i);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
