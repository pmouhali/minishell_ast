/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:54:25 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/16 16:53:05 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

char	*ft_print_d(char *buff, va_list ap, t_format *form)
{
	!(form->flag & LL) && !(form->flag & L) && !(form->flag & HH) &&
	!(form->flag & H) ? buff = ft_itoa(va_arg(ap, int)) : 0;
	form->flag & H ? buff = ft_itoa((short)va_arg(ap, int)) : 0;
	form->flag & HH ? buff = ft_itoa((char)va_arg(ap, int)) : 0;
	form->flag & L ? buff = ft_lltoa(va_arg(ap, long)) : 0;
	form->flag & LL ? buff = ft_lltoa(va_arg(ap, long long)) : 0;
	if (ft_strlen(buff) == 1 && buff[0] == '0' && form->prec == 0)
	{
		buff = ft_manage_precexep(buff, form);
		return (buff);
	}
	buff[0] != '-' && form->flag & PLUS ?
	buff = ft_strjoinplus("+", buff, 2) : 0;
	form->prec != -1 && (((int)ft_strlen(buff) - (buff[0] == '-' ||
	buff[0] == '+')) < form->prec) ? buff = ft_manage_prec(buff, form) : 0;
	form->flag & SPACE && buff[0] != '-' && buff[0] != '+'
	? buff = ft_strjoinplus(" ", buff, 2) : 0;
	(int)(form->large - ft_strlen(buff)) > 0 ?
	buff = ft_manage_space(buff, form) : 0;
	return (buff);
}

char	*ft_print_f(char *buff, va_list ap, t_format *form)
{
	form->prec == -1 ? form->prec = 6 : 0;
	!(form->flag & LF) ? buff = ft_ftoa(va_arg(ap, double), form->prec) : 0;
	form->flag & LF ? buff = ft_ftoa(va_arg(ap, long double), form->prec) : 0;
	form->flag & PLUS && buff[0] != '-' ? buff = ft_strjoinplus("+", buff, 2) :
	0;
	ft_isalpha(buff[1]) && form->flag & ZERO ? form->flag -= ZERO : 0;
	!(ft_isalpha(buff[1])) && (((int)ft_strlen(buff) -
	(buff[0] == '-' || buff[0] == '+')) < form->prec) ? buff =
	ft_manage_prec(buff, form) : 0;
	if (ft_isalpha(buff[1]) && form->type == 'F')
	{
		buff[0] == '-' ? buff[3] -= 32 : 0;
		buff[0] != '-' ? buff[0] -= 32 : 0;
		buff[1] -= 32;
		buff[2] -= 32;
	}
	form->flag & SPACE && buff[0] != '-' && buff[0] != '+'
	? buff = ft_strjoinplus(" ", buff, 2) : 0;
	form->flag & HASH && form->prec == 0 ?
	buff = ft_strjoinplus(buff, ".", 1) : 0;
	(int)(form->large - ft_strlen(buff)) > 0 ?
	buff = ft_manage_space(buff, form) : 0;
	return (buff);
}

char	*ft_print_u(char *buff, va_list ap, t_format *form)
{
	!(form->flag & LL) && !(form->flag & L) && !(form->flag & HH) &&
	!(form->flag & H) ? buff = ft_uitoa(va_arg(ap, int)) : 0;
	form->flag & H ? buff = ft_uitoa((char)va_arg(ap, int)) : 0;
	form->flag & HH ? buff = ft_uitoa((short)va_arg(ap, int)) : 0;
	form->flag & L ? buff = ft_ultoa(va_arg(ap, long)) : 0;
	form->flag & LL ? buff = ft_llutoa(va_arg(ap, long long)) : 0;
	if (ft_strlen(buff) == 1 && buff[0] == '0' && form->prec == 0)
	{
		buff = ft_manage_precexep(buff, form);
		return (buff);
	}
	form->prec != -1 && (((int)ft_strlen(buff) - (buff[0] == '+'))
	< form->prec) ? buff = ft_manage_prec(buff, form) : 0;
	(int)(form->large - ft_strlen(buff)) > 0 ?
	buff = ft_manage_space(buff, form) : 0;
	return (buff);
}
