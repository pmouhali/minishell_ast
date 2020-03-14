/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:39:05 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/14 16:38:15 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

char		*ft_print_p(char *buff, va_list ap, t_format *form)
{
	buff = ft_llutoa_base(va_arg(ap, unsigned long), BASE_16_MIN);
	buff = ft_strjoinplus("0x", buff, 2);
	form->prec != -1 && ((int)ft_strlen(buff) < form->prec) ?
	buff = ft_manage_prec(buff, form) : 0;
	(int)(form->large - ft_strlen(buff)) > 0 ?
	buff = ft_manage_space(buff, form) : 0;
	return (buff);
}

char		*ft_print_c(char *buff, char c, t_format *form)
{
	form->large == 0 ? form->large++ : 0;
	buff = ft_strdup("c");
	form->large > 1 ? buff = ft_manage_space(buff, form) : 0;
	buff[ft_strlenn(buff, 'c')] = c;
	form->ret += write(form->fd, buff, form->large);
	return (buff);
}

char		*ft_print_s(char *buff, va_list ap, t_format *form)
{
	if (!(buff = ft_strdup(va_arg(ap, char*))))
		buff = ft_strdup("(null)");
	form->prec != -1 && ((int)ft_strlen(buff) > form->prec) ?
	buff = ft_manage_prec(buff, form) : 0;
	(int)(form->large - ft_strlen(buff)) > 0 ?
	buff = ft_manage_space(buff, form) : 0;
	return (buff);
}
