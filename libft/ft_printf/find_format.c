/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:22:18 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/15 12:23:46 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static int		find_color(const char *format, t_format *form)
{
	int	i;

	i = 0;
	ft_strncmp(format, "{black}", 7) ? form->color = 'B' : 0;
	ft_strncmp(format, "{red}", 5) ? form->color = 'R' : 0;
	ft_strncmp(format, "{green}", 7) ? form->color = 'G' : 0;
	ft_strncmp(format, "{yellow}", 8) ? form->color = 'Y' : 0;
	ft_strncmp(format, "{blue}", 6) ? form->color = 'b' : 0;
	ft_strncmp(format, "{pink}", 6) ? form->color = 'P' : 0;
	ft_strncmp(format, "{cyan}", 6) ? form->color = 'C' : 0;
	ft_strncmp(format, "{grey}", 6) ? form->color = 'g' : 0;
	ft_strncmp(format, "{eoc}", 5) ? form->color = 'E' : 0;
	if (form->color)
	{
		while (format[i] != '}')
			i++;
	}
	else
		form->color = '{';
	return (i);
}

static int		trad_type(const char *format, t_format *form, va_list ap)
{
	int	i;

	i = 0;
	if (format[i] == '.')
	{
		i++;
		if (format[i] == '*')
			form->prec = va_arg(ap, int);
		else
			form->prec = ft_atoi(format + i);
		while ((format[i] >= '0' && format[i] <= '9') || format[i] == '*')
			i++;
	}
	format[i] == 'h' && format[i + 1] == 'h' ? form->flag += HH : 0;
	format[i] == 'l' && format[i + 1] == 'l' ? form->flag += LL : 0;
	format[i] == 'h' && format[i + 1] != 'h' ? form->flag += H : 0;
	format[i] == 'l' && format[i + 1] != 'l' ? form->flag += L : 0;
	format[i] == 'L' ? form->flag += LF : 0;
	form->flag & HH || form->flag & LL ? i += 2 : 0;
	form->flag & H || form->flag & L || form->flag & LF ? i++ : 0;
	form->type = format[i];
	return (i + 1);
}

static int		trad_flag(const char *format, t_format *form, va_list ap)
{
	int i;

	i = 0;
	while (format[i] == '-' || format[i] == '+' || format[i] == '#' ||
	format[i] == '0' || format[i] == ' ')
	{
		format[i] == '-' && !(form->flag & LESS) ? form->flag += LESS : 0;
		format[i] == '+' && !(form->flag & PLUS) ? form->flag += PLUS : 0;
		format[i] == '#' && !(form->flag & HASH) ? form->flag += HASH : 0;
		format[i] == '0' && !(form->flag & ZERO) ? form->flag += ZERO : 0;
		format[i] == ' ' && !(form->flag & SPACE) ? form->flag += SPACE : 0;
		i++;
	}
	if (format[i] == '*')
		form->large = va_arg(ap, int);
	else
		form->large = ft_atoi(format + i);
	while ((format[i] >= '0' && format[i] <= '9') || format[i] == '*')
		i++;
	return (i + trad_type(format + i, form, ap));
}

int				find_format(const char *format, t_format *form, va_list ap)
{
	int	i;

	form->color = 0;
	form->type = 0;
	if (format[0] == '%')
	{
		form->flag = 0;
		form->large = 0;
		form->prec = -1;
		i = trad_flag(format + 1, form, ap);
	}
	else
		i = find_color(format, form);
	return (i);
}
