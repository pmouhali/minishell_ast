/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:10:12 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/14 20:21:31 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncut(char *dest, int n, int d)
{
	char	*svg;

	if (!(svg = ft_strndup(dest, n)))
		return (NULL);
	if (dest && d == 1)
		ft_strdel(&dest);
	return (svg);
}
