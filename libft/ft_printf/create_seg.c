/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_seg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:21:30 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/15 12:20:28 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static char		*formcolor(t_format *form, char *buff)
{
	form->color == 'B' ? buff = ft_strdup(BLACK) : 0;
	form->color == 'R' ? buff = ft_strdup(RED) : 0;
	form->color == 'G' ? buff = ft_strdup(GREEN) : 0;
	form->color == 'Y' ? buff = ft_strdup(YELLOW) : 0;
	form->color == 'b' ? buff = ft_strdup(BLUE) : 0;
	form->color == 'P' ? buff = ft_strdup(PINK) : 0;
	form->color == 'C' ? buff = ft_strdup(CYAN) : 0;
	form->color == 'g' ? buff = ft_strdup(GREY) : 0;
	form->color == 'E' ? buff = ft_strdup(EOC) : 0;
	return (buff);
}

static char		*formseg(t_format *form, va_list ap, char *buff)
{
	form->type == 's' ? buff = ft_print_s(buff, ap, form) : 0;
	form->type == 'c' || form->type == 'C'
	? buff = ft_print_c(buff, (char)va_arg(ap, int), form) : 0;
	form->type == 'd' || form->type == 'i' || form->type == 'D' ?
	buff = ft_print_d(buff, ap, form) : 0;
	form->type == 'o' || form->type == 'O' ? buff = ft_print_o(buff, ap, form) :
	0;
	form->type == 'x' ? buff = ft_print_x(buff, ap, form) : 0;
	form->type == 'X' ? buff = ft_print_xmaj(buff, ap, form) : 0;
	form->type == 'u' || form->type == 'U' ? buff = ft_print_u(buff, ap, form) :
	0;
	form->type == 'b' ? buff = ft_print_b(buff, ap, form) : 0;
	form->type == 'f' || form->type == 'F' ?
	buff = ft_print_f(buff, ap, form) : 0;
	form->type == 'p' ? buff = ft_print_p(buff, ap, form) : 0;
	form->type == '%' ? buff = ft_print_c(buff, '%', form) : 0;
	return (buff);
}

void			create_seg(t_format *form, va_list ap)
{
	char		*buff;

	buff = NULL;
	if (!form->color && form->type)
		buff = formseg(form, ap, buff);
	else if (!form->type && form->color)
		buff = formcolor(form, buff);
	if (form->type != 'c' && form->type != '%')
		form->ret += write(1, buff, ft_strlen(buff));
	ft_strdel(&buff);
}
