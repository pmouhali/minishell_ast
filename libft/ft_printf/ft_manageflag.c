/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manageflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:27:33 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/16 16:56:49 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

char			*ft_manage_precexep(char *buff, t_format *form)
{
	ft_strdel(&buff);
	if ((form->type == 'd' || form->type == 'i') && form->flag & PLUS)
		buff = ft_strdup("+");
	else if (form->large > 0)
		buff = ft_strnew(form->large);
	if (form->large > 0)
		buff = ft_manage_space(buff, form);
	return (buff);
}

static void		ft_placesigns(char *buff, char *space, t_format *form, char s)
{
	s == '0' && (buff[0] == '-' || buff[0] == '+' || buff[0] == ' ')
	? space[0] = buff[0] : 0;
	s == '0' && (buff[0] == '-' || buff[0] == '+' || buff[0] == ' ')
	? buff[0] = '0' : 0;
	form->flag & HASH && s == '0' && (form->type == 'x' || form->type == 'X')
	? buff[1] = '0' : 0;
}

char			*ft_manage_space(char *buff, t_format *form)
{
	char	*space;
	char	s;
	int		t;

	s = ' ';
	!(form->flag & LESS) && form->flag & ZERO && form->prec == -1 ? s = '0' : 0;
	!(form->flag & LESS) &&
	form->type == 'f' && form->flag & ZERO ? s = '0' : 0;
	t = form->large - ft_strlen(buff);
	space = ft_strnew(t);
	ft_bzero(space, t);
	while (t--)
		space[t] = s;
	ft_placesigns(buff, space, form, s);
	form->flag & LESS ?
	buff = ft_strjoinplus(buff, space, 3) : 0;
	!(form->flag & LESS) ?
	buff = ft_strjoinplus(space, buff, 3) : 0;
	form->flag & HASH && s == '0' && (form->type == 'x' || form->type == 'X')
	? buff[1] = form->type : 0;
	return (buff);
}

char			*ft_manage_prec(char *buff, t_format *form)
{
	char	*str_new;
	size_t	t;
	int		s;

	s = 0;
	form->type == 's' ?
	str_new = ft_strndup(buff, form->prec) : 0;
	if (form->type != 's')
	{
		buff && (buff[0] == '-' || buff[0] == '+') ? s = 1 : 0;
		if (buff)
			t = form->prec - ft_strlen(buff) + s;
		else
			t = form->prec;
		str_new = ft_strnew(t + s);
		ft_bzero(str_new, t);
		while (t--)
			str_new[t] = '0';
		s == 1 ? str_new[0] = buff[0] : 0;
		s == 1 ? buff[0] = '0' : 0;
		str_new = ft_strjoinplus(str_new, buff, 3);
	}
	else
		((int)ft_strlen(buff) > form->prec) ? ft_strdel(&buff) : 0;
	return (str_new);
}
