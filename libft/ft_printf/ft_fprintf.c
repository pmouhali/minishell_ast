/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:27:02 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/15 12:21:59 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"
#include <stdio.h>

static void	verifyform(t_format *form)
{
	form->color == '{' ? form->ret += write(form->fd, "{", 1) : 0;
	if (form->type != 'd' && form->type != 's' && form->type != 'p' \
	&& form->type != 'i' && form->type != 'c' && form->type != 'X' && \
	form->type != 'x' && form->type != 'u' && form->type != 'o' && \
	form->type != 'b' && form->type != 'f' && form->type != '%' && \
	form->type != 'D' && form->type != 'C' && form->type != 'F' && \
	form->type != 'O' && form->type != 'U' && form->type != 0)
		form->ret += write(form->fd, &form->type, 1);
	(form->type == 'D' || form->type == 'O'
	|| form->type == 'U') && !(form->flag & L) ? form->flag += L : 0;
}

int			ft_fprintf(int fd, const char *format, ...)
{
	t_format	form;
	va_list		ap;
	int			i;
	int			b;

	va_start(ap, format);
	form.fd = fd;
	form.ret = 0;
	i = 0;
	b = 1;
	while (format[i])
	{
		if (format[i] == '%' || format[i] == '{')
		{
			form.ret += write(fd, format + (i - (b - 1)), b - 1);
			i += find_format(format + i, &form, ap);
			verifyform(&form);
			create_seg(&form, ap);
			b = 0;
		}
		format[i] ? b++ : 0;
		format[i] ? i++ : 0;
	}
	b > 0 ? form.ret += write(1, format + (i - (b - 1)), b - 1) : 0;
	va_end(ap);
	return (form.ret);
}
