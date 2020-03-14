/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:44:38 by pmouhali          #+#    #+#             */
/*   Updated: 2019/11/04 14:45:58 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*cdest;
	const unsigned char	*csrc;

	cdest = dest;
	csrc = src;
	while (n > 0 && *csrc != (unsigned char)c)
	{
		*cdest = *csrc;
		cdest++;
		csrc++;
		n--;
	}
	if (n == 0)
		return (NULL);
	if (n > 0 && *csrc == (unsigned char)c)
		*cdest = *csrc;
	return (cdest + 1);
}
