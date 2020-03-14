/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:44:26 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/14 19:33:27 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

char	*ft_print_o(char *buff, va_list ap, t_format *form)
{
	!(form->flag & LL) && !(form->flag & L) && !(form->flag & HH) &&
	!(form->flag & H) ? buff =
	ft_uitoa_base(va_arg(ap, unsigned int), BASE_8) : 0;
	form->flag & H ? buff =
	ft_uitoa_base((short)va_arg(ap, unsigned int), BASE_8) : 0;
	form->flag & HH ? buff =
	ft_uitoa_base((char)va_arg(ap, unsigned int), BASE_8) : 0;
	form->flag & L ? buff =
	ft_ultoa_base(va_arg(ap, unsigned long), BASE_8) : 0;
	form->flag & LL ? buff =
	ft_llutoa_base(va_arg(ap, unsigned long long), BASE_8) : 0;
	if (ft_strlen(buff) == 1 && buff[0] == '0' && form->prec == 0 &&
	!(form->flag & HASH))
	{
		buff = ft_manage_precexep(buff, form);
		return (buff);
	}
	form->prec != -1 && ((int)ft_strlen(buff)
	< form->prec) ? buff = ft_manage_prec(buff, form) : 0;
	form->flag & HASH && buff[0] != '0' ?
	buff = ft_strjoinplus("0", buff, 2) : 0;
	(int)(form->large - ft_strlen(buff)) > 0 ?
	buff = ft_manage_space(buff, form) : 0;
	return (buff);
}

char	*ft_print_x(char *buff, va_list ap, t_format *form)
{
	!(form->flag & LL) && !(form->flag & L) && !(form->flag & HH) &&
	!(form->flag & H) ? buff =
	ft_uitoa_base(va_arg(ap, int), BASE_16_MIN) : 0;
	form->flag & H ? buff =
	ft_uitoa_base((short)va_arg(ap, int), BASE_16_MIN) : 0;
	form->flag & HH ? buff =
	ft_uitoa_base((char)va_arg(ap, int), BASE_16_MIN) : 0;
	form->flag & L ? buff = ft_ultoa_base(va_arg(ap, long), BASE_16_MIN) : 0;
	form->flag & LL ? buff =
	ft_llutoa_base(va_arg(ap, long long), BASE_16_MIN) : 0;
	if (ft_strlen(buff) == 1 && buff[0] == '0' && form->prec == 0)
	{
		buff = ft_manage_precexep(buff, form);
		return (buff);
	}
	form->prec != -1 && ((int)ft_strlen(buff)
	< form->prec) ? buff = ft_manage_prec(buff, form) : 0;
	form->flag & HASH && !(ft_strlen(buff) == 1 && buff[0] == '0') ?
	buff = ft_strjoinplus("0x", buff, 2) : 0;
	(int)(form->large - ft_strlen(buff)) > 0 ?
	buff = ft_manage_space(buff, form) : 0;
	return (buff);
}

char	*ft_print_xmaj(char *buff, va_list ap, t_format *form)
{
	!(form->flag & LL) && !(form->flag & L) && !(form->flag & HH) &&
	!(form->flag & H) ? buff = ft_uitoa_base(va_arg(ap, int), BASE_16_MAJ) : 0;
	form->flag & H ? buff =
	ft_uitoa_base((short)va_arg(ap, int), BASE_16_MAJ) : 0;
	form->flag & HH ? buff =
	ft_uitoa_base((char)va_arg(ap, int), BASE_16_MAJ) : 0;
	form->flag & L ? buff = ft_ultoa_base(va_arg(ap, long), BASE_16_MAJ) : 0;
	form->flag & LL ? buff =
	ft_llutoa_base(va_arg(ap, long long), BASE_16_MAJ) : 0;
	if (ft_strlen(buff) == 1 && buff[0] == '0' && form->prec == 0)
	{
		buff = ft_manage_precexep(buff, form);
		return (buff);
	}
	form->prec != -1 && ((int)ft_strlen(buff)
	< form->prec) ? buff = ft_manage_prec(buff, form) : 0;
	form->flag & HASH && !(ft_strlen(buff) == 1 && buff[0] == '0') ?
	buff = ft_strjoinplus("0X", buff, 2) : 0;
	(int)(form->large - ft_strlen(buff)) > 0 ?
	buff = ft_manage_space(buff, form) : 0;
	return (buff);
}

char	*ft_print_b(char *buff, va_list ap, t_format *form)
{
	form->prec == -1 ? form->prec = 32 : 0;
	buff = ft_bintoa(va_arg(ap, void*), form->prec);
	(int)(form->large - ft_strlen(buff)) > 0 ?
	buff = ft_manage_space(buff, form) : 0;
	return (buff);
}
