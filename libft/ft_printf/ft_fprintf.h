/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:12:59 by grochefo          #+#    #+#             */
/*   Updated: 2020/03/14 20:08:14 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <stdarg.h>

# define BLACK	"\033[1;30m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define PINK	"\033[1;35m"
# define CYAN	"\033[1;36m"
# define GREY	"\033[1;37m"
# define EOC	"\033[0m"

# define LL		0x0001
# define L		0x0002
# define H		0x0004
# define HH		0x0008

# define HASH	0x0010
# define SPACE	0x0020
# define PLUS	0x0040
# define ZERO	0x0080
# define LESS	0x0100
# define LF		0x0200

typedef struct		s_format
{
	int				fd;
	char			type;
	int				flag;
	size_t			large;
	int				prec;
	char			color;
	size_t			ret;
}					t_format;

int					find_format(const char *format, t_format *form, va_list ap);
int					ft_fprintf(int fd, const char *format, ...);
void				create_seg(t_format *form, va_list ap);
char				*ft_print_xmaj(char *buff, va_list ap, t_format *form);
char				*ft_print_x(char *buff, va_list ap, t_format *form);
char				*ft_print_o(char *buff, va_list ap, t_format *form);
char				*ft_print_b(char *buff, va_list ap, t_format *form);
char				*ft_manage_space(char *buff, t_format *form);
char				*ft_manage_prec(char *buff, t_format *form);
char				*ft_print_d(char *buff, va_list ap, t_format *form);
char				*ft_print_u(char *buff, va_list ap, t_format *form);
char				*ft_print_f(char *buff, va_list ap, t_format *form);
char				*ft_print_p(char *buff, va_list ap, t_format *form);
char				*ft_print_c(char *buff, char c, t_format *form);
char				*ft_print_s(char *buff, va_list ap, t_format *form);
char				*ft_manage_precexep(char *buff, t_format *form);
#endif
