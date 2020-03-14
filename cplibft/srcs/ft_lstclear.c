/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:31:31 by pmouhali          #+#    #+#             */
/*   Updated: 2019/11/05 16:47:53 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *p;

	while (*lst)
	{
		p = *lst;
		*lst = (*lst)->next;
		if (del)
			del(p->content);
		free(p);
	}
	*lst = NULL;
}
