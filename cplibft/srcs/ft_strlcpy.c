/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:03:59 by pmouhali          #+#    #+#             */
/*   Updated: 2019/11/09 16:24:44 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	if (!src)
		return (0);
	i = 0;
	if (size > 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		if (size == 1)
			dst[size - 1] = '\0';
		else if (*src)
			dst[i--] = '\0';
		else if (!*src)
			dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
