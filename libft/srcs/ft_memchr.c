/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:46:09 by pmouhali          #+#    #+#             */
/*   Updated: 2019/11/10 17:51:10 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*cs;

	cs = s;
	i = 0;
	while (cs && *cs && *cs != (unsigned char)c && i < n)
	{
		i++;
		cs++;
	}
	if (i < n && *cs == (unsigned char)c)
		return ((void*)cs);
	else
		return (NULL);
}
