/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 08:27:13 by grochefo          #+#    #+#             */
/*   Updated: 2019/03/20 17:21:59 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_bintoa(void *obj, size_t t)
{
	char	*str_new;
	size_t	b;

	t *= 8;
	str_new = NULL;
	b = 0;
	while (b != t)
	{
		if ((*(long long*)obj) >> b & 1)
			str_new = ft_strjoinplus(str_new, "1", 1);
		else
			str_new = ft_strjoinplus(str_new, "0", 1);
		b++;
	}
	if (!str_new)
	{
		str_new = ft_strdup("(null)");
		return (str_new);
	}
	while (t && str_new[t] != '1')
		t--;
	str_new = ft_strncut(str_new, t + 1, 1);
	str_new = ft_strrev(str_new);
	return (str_new);
}
